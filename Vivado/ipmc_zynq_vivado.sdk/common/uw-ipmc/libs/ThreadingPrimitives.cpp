#include <FreeRTOS.h>
#include <libs/ThreadingPrimitives.h>
#include <task.h>
#include <semphr.h>
#include <timers.h>
#include <task.h>
#include <IPMC.h>

/**
 * Instantiate an AbsoluteTimeout.
 *
 * \param relative_timeout The relative timeout to be converted to absolute form.
 */
AbsoluteTimeout::AbsoluteTimeout(TickType_t relative_timeout) {
	if (IN_INTERRUPT())
		this->last = xTaskGetTickCountFromISR();
	else
		this->last = xTaskGetTickCount();
	this->remaining = relative_timeout; // Wraparound handled by u32-wrap.
}

AbsoluteTimeout::~AbsoluteTimeout() {
	// Nothing to destruct.
}

/**
 * Get the current remaining timeout.
 *
 * \warning You must call this at least once per timer wrap or it will lose track.
 * \return A correct relative timeout for this object from the current point in time.
 */
TickType_t AbsoluteTimeout::get_timeout() {
	if (this->remaining == portMAX_DELAY)
		return portMAX_DELAY;

	TickType_t now;
	if (IN_INTERRUPT())
		now = xTaskGetTickCountFromISR();
	else
		now = xTaskGetTickCount();

	TickType_t time_passed = now - this->last;
	if (time_passed > remaining) {
		this->remaining = 0;
	}
	else {
		this->remaining -= time_passed;
	}
	this->last = now;
	return this->remaining;
}


WaitList::~WaitList() {
	/* Fail-secure.
	 *
	 * We can only safely deconstruct if no-one is waiting on us.
	 *
	 * It is better to alert the developers to this occurrence than to simply
	 * release all waiters.
	 */
	configASSERT(!this->waitlist.size());
}

/**
 * Join this waitlist.
 *
 * In order to wait on a waitlist, you must first join it.  The separation of
 * these two operations allows one to join a waitlist while holding various
 * relevant mutexes, but release those mutexes before waiting.
 *
 * \return An opaque handle identifying your waitlist subscription.
 *
 * \warning After calling this function you MUST call #wait(), even if you
 *          simply do so with a timeout of 0.
 */
WaitList::Subscription_t WaitList::join() {
	configASSERT(!IN_INTERRUPT());

	SemaphoreHandle_t sem = xSemaphoreCreateBinary();
	configASSERT(sem);
	taskENTER_CRITICAL();
	this->waitlist.push_back(sem);
	taskEXIT_CRITICAL();
	return sem;
}

/**
 * Wait on this waitlist using a pre-acquired subscription.
 *
 * \param subscription The subscription that you have joined the waitlist with.
 * \param timeout The wait timeout in standard FreeRTOS format.
 * \return false if the wait timed out, else true.
 *
 * \note After this call, your waitlist subscription is no longer valid.
 */
bool WaitList::wait(WaitList::Subscription_t subscription, TickType_t timeout) {
	configASSERT(!IN_INTERRUPT());

	BaseType_t sem_result = xSemaphoreTake(subscription, timeout);

	taskENTER_CRITICAL();
	this->waitlist.remove(subscription);
	taskEXIT_CRITICAL();

	vSemaphoreDelete(subscription); // Clean up after ourselves.
	return sem_result == pdTRUE;
}

/**
 * Wake threads waiting on this waitlist.
 *
 * \note This function is ISR safe.
 *
 * \param waiters The number of waiters to wake.  -1 to wake all waiters.
 */
void WaitList::wake(s32 waiters) {
	if (!IN_INTERRUPT())
		taskENTER_CRITICAL();
	BaseType_t xHigherPriorityTaskWoken = pdTRUE;
	for (auto it = this->waitlist.begin(), eit = this->waitlist.end(); waiters-- && it != eit; ++it)
		xSemaphoreGiveFromISR(*it, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	if (!IN_INTERRUPT())
		taskEXIT_CRITICAL();
}

/**
 * Construct an Event object.
 *
 * \param initial_state The initial state of the flag defining this Event.
 */
Event::Event(bool initial_state) :
		flag(initial_state), interrupt_pend_count(0) {
	// Nothing more to do here.
}

/**
 * Set the event flag to 'true', and unblock all waiters.
 *
 * \warning In an ISR, use #setFromISR() instead.
 */
void Event::set() {
	configASSERT(!IN_INTERRUPT());
	taskENTER_CRITICAL();
	bool old_flag = this->flag;
	this->flag = true;
	if (!old_flag) {
		// We set it.  Time to release all waiters.
		this->waitlist.wake();
	}
	taskEXIT_CRITICAL();
}

/**
 * Complete the callback to clear the event flag from an ISR (via timer thread).
 */
void Event::_complete_setFromISR() {
	portENTER_CRITICAL();
	this->set();
	this->interrupt_pend_count--;
	portEXIT_CRITICAL();
}

static void event_set_from_isr_callback(void *vEvent, uint32_t ulUnused) {
	static_cast<Event*>(vEvent)->_complete_setFromISR();
}

/**
 * Set the event flag to 'true', and unblock all waiters from an ISR.
 *
 * \param pxHigherPriorityTaskWoken See documentation for xTimerPendFunctionCallFromISR()
 *
 * \warning Outside of an ISR, use #set() instead.
 *
 * \note This operation is completed in a deferred interrupt style, using the timer thread.
 */
void Event::setFromISR(BaseType_t * const pxHigherPriorityTaskWoken) {
	configASSERT(IN_INTERRUPT());
	this->interrupt_pend_count++;
	xTimerPendFunctionCallFromISR(event_set_from_isr_callback, this, 0, pxHigherPriorityTaskWoken);
}

/**
 * Set the event flag to 'false' and block all waiters.
 *
 * \warning In an ISR, use #clear() instead.
 */
void Event::clear() {
	taskENTER_CRITICAL();
	this->flag = false;
	taskEXIT_CRITICAL();
}

/**
 * Set the event flag to 'false' and block all waiters from within an interrupt.
 */
void Event::clearFromISR() {
	this->flag = false;
}

/**
 * Check the current value of the flag.
 *
 * \return The current value of the flag.
 */
bool Event::get() {
	taskENTER_CRITICAL();
	bool state = this->flag;
	taskEXIT_CRITICAL();
	return state;
}

/**
 * Wait for this event to be true.
 *
 * \param timeout The wait timeout in standard FreeRTOS format.
 * \return The value of the flag after waiting (false is possible if the wait timed out).
 */
bool Event::wait(TickType_t timeout) {
	taskENTER_CRITICAL();
	if (this->flag) {
		taskEXIT_CRITICAL();
		return true;
	}
	WaitList::Subscription_t subscription = this->waitlist.join();
	taskEXIT_CRITICAL();
	return this->waitlist.wait(subscription, timeout);
}

/**
 * Destructor for ThreadingEvent.
 *
 * \warning This object cannot be deleted while there are tasks waiting on it.
 */
Event::~Event() {
	/* Wait for any deferred interrupt style setFromISR to complete.  If we
	 * didn't do this, they'd call a freed pointer.  That'd be bad.
	 */
	while (this->interrupt_pend_count)
		vTaskDelay(1);
}
