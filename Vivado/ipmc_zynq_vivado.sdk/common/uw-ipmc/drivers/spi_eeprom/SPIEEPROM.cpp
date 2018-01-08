/*
 * EEPROM.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: jtikalsky
 */

#include <drivers/spi_eeprom/SPIEEPROM.h>
#include <task.h>

/**
 * Instantiate an EEPROM interface.
 *
 * @param spibus       The PS_SPI bus the EEPROM is on
 * @param chip_select  The chip select for the EEPROM
 * @param size         The size of the EEPROM
 * @param page_size    The page size of the EEPROM
 */
SPI_EEPROM::SPI_EEPROM(SPI &spibus, u8 chip_select, u32 size, u8 page_size)
	: EEPROM(size, page_size), spibus(spibus), cs(chip_select) {
	this->mutex = xSemaphoreCreateMutex();
}

SPI_EEPROM::~SPI_EEPROM() {
	xSemaphoreTake(this->mutex, portMAX_DELAY);
	vSemaphoreDelete(this->mutex);
}

/**
 * Read from the EEPROM.
 *
 * @param address The read address
 * @param buf     The output buffer
 * @param bytes   The number of bytes to read
 * @return        The number of bytes read
 */
size_t SPI_EEPROM::read(u16 address, u8 *buf, size_t bytes) {
	configASSERT(address + bytes <= this->size);
	xSemaphoreTake(this->mutex, portMAX_DELAY);

	/* Reads don't care about page boundaries, but page_size is a decent read
	 * block size for avoiding stack overflow issues with large transfers.
	 */
	const u8 hdr_len = (this->size > 256 ? 3 : 2);
	u8 txbuf[hdr_len+this->page_size];
	size_t bytes_read = 0;
	while (bytes_read < bytes) {
		memset(txbuf, 0, 3+bytes); // Clear the buffer for shift out.
		txbuf[0] = 3; // CMD_READ
		if (hdr_len == 3) {
			// Two byte address.
			txbuf[1] = address >> 8;
			txbuf[2] = address & 0xff;
		}
		else {
			// One byte address.
			configASSERT(address <= 0xff);
			txbuf[1] = address & 0xff;
		}
		size_t to_read = bytes - bytes_read;
		if (to_read > this->page_size)
			to_read = this->page_size;
		if (!this->spibus.transfer(this->cs, txbuf, txbuf, hdr_len+to_read))
			break;

		memcpy(buf+bytes_read, txbuf+hdr_len, to_read);
		bytes_read += to_read;
		address += to_read;
	}
	xSemaphoreGive(this->mutex);
	return bytes_read;
}

/**
 * Write to the EEPROM.
 *
 * @param address The write address
 * @param buf     The output buffer
 * @param bytes   The number of bytes to write
 * @return        The number of bytes written
 */
size_t SPI_EEPROM::write(u16 address, u8 *buf, size_t bytes) {
	configASSERT(address + bytes <= this->size);
	xSemaphoreTake(this->mutex, portMAX_DELAY);

	/* Unlike reads, writes DEFINITELY care about page boundaries.  We'll need
	 * to split transactions correctly.
	 */
	const u8 hdr_len = (this->size > 256 ? 3 : 2);
	u8 txbuf[hdr_len+this->page_size];
	size_t bytes_written = 0;
	while (bytes_written < bytes) {
		txbuf[0] = 2; // CMD_WRITE
		if (hdr_len == 3) {
			// Two byte address.
			txbuf[1] = address >> 8;
			txbuf[2] = address & 0xff;
		}
		else {
			// One byte address.
			configASSERT(address <= 0xff);
			txbuf[1] = address & 0xff;
		}
		// We'll fill a page worth, but will only TRANSFER up to boundary.
		memcpy(txbuf+hdr_len, buf+bytes_written, (bytes > this->page_size ? bytes : this->page_size));

		size_t to_write = this->page_size - (address % this->page_size);
		if (to_write > (bytes - bytes_written))
			to_write = bytes - bytes_written;
		if (!this->spibus.transfer(this->cs, txbuf, NULL, hdr_len+to_write))
			break;

		do {
			if (txbuf[0] == 5) // Not our first RDSR
				vTaskDelay(1); // Sleep the shortest possible duration before rechecking.
			// Now to wait until the write operation is actually complete.
			txbuf[0] = 5; // CMD_RDSR
			txbuf[1] = 1; // So the `continue;` below will in fact always loop.
			if (!this->spibus.transfer(this->cs, txbuf, txbuf, 2))
				continue;
		} while (txbuf[1] & 1); // Write In Progress.

		bytes_written += to_write;
		address += to_write;
	}
	xSemaphoreGive(this->mutex);
	return bytes_written;
}
