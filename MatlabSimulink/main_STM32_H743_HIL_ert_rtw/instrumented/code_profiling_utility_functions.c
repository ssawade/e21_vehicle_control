/*
 * File: code_profiling_utility_functions.c
 *
 * Code generated for instrumentation.
 *
 */

#include "code_profiling_utility_functions.h"

/* Code instrumentation offset(s) for model main_STM32_H743_HIL */
#define taskTimeStart_main_STM32_H743_HIL_offset 0
#define taskTimeEnd_main_STM32_H743_HIL_offset 0

/* Code instrumentation offset(s) for model ECU_RCP */
#define profileStart_ECU_RCP_offset    11
#define profileEnd_ECU_RCP_offset      11

/* Code instrumentation offset(s) for model main_STM32_H743_HIL */
#define profileStart_m_0d34002402f40824_offset 27
#define profileEnd_main_STM32_H743_HIL_offset 27

/* Code instrumentation offset(s) for model main_STM32_H743_HIL */
#define captureMode_main_STM32_H743_HIL_offset 8

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

static inline void taskTimeStart(uint32_T sectionId)
{
  captureModeStart(sectionId);
}

static inline void taskTimeEnd(uint32_T sectionId)
{
  captureModeEnd(sectionId);
}

#include "ext_mode_profiling.h"
#define MAX_EXECUTION_SECTION_ID       41
#define MAP_CAPTURE_IDS(X)             (((X) > 0 && (X) <= 8) ? (X) : (((X) > 11 && (X) <= 44) ? ((X) - 3) : 0))

static uint32_T xsd_xil_last_start_time[MAX_EXECUTION_SECTION_ID] = { 0 };

static uint32_T xsd_xil_capture_mode_nested[MAX_EXECUTION_SECTION_ID] = { 0 };

void captureMode(uint32_T sectionId)
{
  UNUSED_PARAMETER(sectionId);
}

void captureModeStart(uint32_T sectionId)
{
  uint32_T mappedId = MAP_CAPTURE_IDS(sectionId);
  if (mappedId > 0) {
    xsd_xil_last_start_time[mappedId - 1] = profileTimerRead();
    xsd_xil_capture_mode_nested[mappedId - 1] = 1;
  }                                    /* if */
}

void captureModeEnd(uint32_T sectionId)
{
  uint8_T* addr;
  uint32_T captureValue;
  uint32_T mappedId = MAP_CAPTURE_IDS(sectionId);
  uint32_T turnaroundTime;
  if (mappedId > 0) {
    mappedId = mappedId - 1;
    if (xsd_xil_capture_mode_nested[mappedId] != 1) {
      xsd_xil_capture_mode_nested[mappedId] = 0;
      return;
    }                                  /* if */

    xsd_xil_capture_mode_nested[mappedId] = 0;

    /* Update maximum execution */
    addr = (uint8_T*)getMaxElementInProfilingBuffer(mappedId);
    XCP_MEMCPY((void*)&captureValue, (void*)addr, sizeof(uint32_T));
    turnaroundTime = profileTimerRead() - xsd_xil_last_start_time[mappedId];
    if (turnaroundTime > captureValue) {
      XCP_MEMCPY((void*)addr, (void*)&turnaroundTime, sizeof(uint32_T));
    }                                  /* if */

    /* Try to update to total execution counter */
    addr = (uint8_T*)getAvgElementInProfilingBuffer(mappedId);
    XCP_MEMCPY((void*)&captureValue, (void*)addr, sizeof(uint32_T));
    if ((captureValue + turnaroundTime) >= captureValue) {
      captureValue = captureValue + turnaroundTime;
      XCP_MEMCPY((void*)addr, (void*)&captureValue, sizeof(uint32_T));

      /* Update total number of calls */
      addr = (uint8_T*)getCallsElementInProfilingBuffer(mappedId);
      XCP_MEMCPY((void*)&captureValue, (void*)addr, sizeof(uint32_T));
      captureValue = captureValue + 1;
      XCP_MEMCPY((void*)addr, (void*)&captureValue, sizeof(uint32_T));
    }                                  /* if */
  }                                    /* if */
}

static inline void profileStart(uint32_T sectionId)
{
  captureModeStart(sectionId);
}

static inline void profileEnd(uint32_T sectionId)
{
  captureModeEnd(sectionId);
}

/* Code instrumentation method(s) for model main_STM32_H743_HIL */
void taskTimeStart_main_STM32_H743_HIL(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart_main_STM32_H743_HIL_offset + sectionId);
}

void taskTimeEnd_main_STM32_H743_HIL(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd_main_STM32_H743_HIL_offset + sectionId);
}

/* Code instrumentation method(s) for model ECU_RCP */
void profileStart_ECU_RCP(uint32_T sectionId)
{
  profileStart(profileStart_ECU_RCP_offset + sectionId);
}

void profileEnd_ECU_RCP(uint32_T sectionId)
{
  profileEnd(profileEnd_ECU_RCP_offset + sectionId);
}

/* Code instrumentation method(s) for model main_STM32_H743_HIL */
void profileStart_m_0d34002402f40824(uint32_T sectionId)
{
  profileStart(profileStart_m_0d34002402f40824_offset + sectionId);
}

void profileEnd_main_STM32_H743_HIL(uint32_T sectionId)
{
  profileEnd(profileEnd_main_STM32_H743_HIL_offset + sectionId);
}

/* Code instrumentation method(s) for model main_STM32_H743_HIL */
void captureMode_main_STM32_H743_HIL(uint32_T sectionId)
{
  captureMode(captureMode_main_STM32_H743_HIL_offset + sectionId);
}

void InitEvent (void)
{
  /* callbacks executed when the sim starts */
}

void PauseEvent (void)
{
  /* callbacks executed when the sim is paused */
}

void TerminateEvent (void)
{
  /* callbacks executed when the sim ends */
}

void StepCompletedEvent (void)
{
  /* callbacks executed when a step ends */
}
