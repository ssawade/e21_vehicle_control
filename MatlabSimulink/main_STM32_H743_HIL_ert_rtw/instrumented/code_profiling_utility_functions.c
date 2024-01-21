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
#define profileStart_ECU_RCP_offset    8
#define profileEnd_ECU_RCP_offset      8

/* Code instrumentation offset(s) for model main_STM32_H743_HIL */
#define profileStart_m_0d34002402f40824_offset 24
#define profileEnd_main_STM32_H743_HIL_offset 24

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

void xilUploadProfilingData(uint32_T sectionId)
{
  code_profiling_atomic_read_store(sectionId);
}

/* For real-time, multitasking case this function is stubbed out. */
void xilProfilingTimerFreezeInternal(void)
{
}

void xilProfilingTimerFreeze(void)
{
}

/* For real-time, multitasking case this function is stubbed out. */
void xilProfilingTimerUnFreezeInternal(void)
{
}

void xilProfilingTimerUnFreeze(void)
{
}

void taskTimeStart(uint32_T sectionId)
{
  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreezeInternal();
}

void taskTimeEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreezeInternal();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
}

void profileStart(uint32_T sectionId)
{
  xilProfilingTimerFreezeInternal();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreezeInternal();
}

void profileEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreezeInternal();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
  xilProfilingTimerUnFreezeInternal();
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
