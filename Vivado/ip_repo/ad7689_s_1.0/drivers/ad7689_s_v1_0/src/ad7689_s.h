
#ifndef AD7689_S_H
#define AD7689_S_H

#ifdef __cplusplus
extern "C" {
#endif

/****************** Include Files ********************/
#include "xil_types.h"
#include "xstatus.h"

/**************************** Type Definitions *****************************/

/**
 * This typedef contains configuration information for the device.
 */
typedef struct {
    u16 DeviceId; /* Unique ID of device */
    UINTPTR BaseAddress; /* Device base address */
    u32 InterfaceCount; /* Number of available interfaces */
} AD7689_S_Config;

/**
 * The AD7689_S driver instance data. The user is required to allocate a
 * variable of this type for every AD7689_S device in the system. A pointer
 * to a variable of this type is then passed to the driver API functions.
 **/
typedef struct {
    UINTPTR BaseAddress;    /* Device base address */
    u32 IsReady;        /* Device is initialized and ready */
    u32 InterfaceCount; /* Number of available interfaces */
} AD7689_S;


int AD7689_S_Initialize(AD7689_S *InstancePtr, u16 DeviceId);

void AD7689_S_Reset(AD7689_S * InstancePtr);

u16 AD7689_S_Measure_Conv_Freq(AD7689_S *InstancePtr);

void AD7689_S_Set_Conv_Freq(AD7689_S *InstancePtr, u16 freq);

u32 AD7689_S_Get_Conv_Cnt(AD7689_S *InstancePtr);

XStatus AD7689_S_Get_Reading(AD7689_S *InstancePtr, u8 ch, u16 * reading);

void AD7689_S_Set_Master_Ovrrd_Enable(AD7689_S *InstancePtr, u32 enable);

u32 AD7689_S_Get_Master_Ovrrd_Enable(AD7689_S *InstancePtr);

void AD7689_S_Set_Ch_Ovrrd_Enables(AD7689_S *InstancePtr, u32 enables);

u32 AD7689_S_Get_Ch_Ovrrd_Enables(AD7689_S *InstancePtr);

XStatus AD7689_S_Set_Ovrrd_Val(AD7689_S *InstancePtr, u8 ch, u16 ovrrd_val);

XStatus AD7689_S_Get_Ovrrd_Val(AD7689_S *InstancePtr, u8 ch, u16 * ovrrd_val);


#ifdef __cplusplus
}
#endif

#endif // AD7689_S_H
