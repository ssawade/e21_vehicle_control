/*
 * File: code_profiling_utility_functions.h
 *
 * Code generated for instrumentation.
 *
 */

/* Functions with a C call interface */
#ifdef __cplusplus

extern "C"
{

#endif

#include "xcp_platform_custom.h"
#ifdef __cplusplus

}

#endif

#include "rtwtypes.h"

/* Upload code instrumentation data point */
void store_code_profiling_data_point(
  void* pData, uint32_T numMemUnits, uint32_T sectionId);

/* Atomic function to read timer and upload data point */
void code_profiling_atomic_read_store(uint32_T sectionId);

/* Request upload of metrics evaluated on target */
void captureMode(uint32_T sectionId);

/* Update methods */
void captureModeStart(uint32_T sectionId);
void captureModeEnd(uint32_T sectionId);

/* Code instrumentation method(s) for model main_STM32_H743_HIL */
void taskTimeStart_main_STM32_H743_HIL(uint32_T sectionId);
void taskTimeEnd_main_STM32_H743_HIL(uint32_T sectionId);

/* Code instrumentation method(s) for model ECU_RCP */
void profileStart_ECU_RCP(uint32_T sectionId);
void profileEnd_ECU_RCP(uint32_T sectionId);

/* Code instrumentation method(s) for model main_STM32_H743_HIL */
void profileStart_m_0d34002402f40824(uint32_T sectionId);
void profileEnd_main_STM32_H743_HIL(uint32_T sectionId);

/* Code instrumentation method(s) for model main_STM32_H743_HIL */
void captureMode_main_STM32_H743_HIL(uint32_T sectionId);

/* Callback called when the simulation starts */
void InitEvent(void);

/* Callback called when the simulation is paused */
void PauseEvent (void);

/* Callback called when the simulation ends */
void TerminateEvent (void);

/* Callback called when a step ends */
void StepCompletedEvent (void);
