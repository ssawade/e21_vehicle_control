/************************************************************
 * Includes
 ************************************************************/

#include "rtwtypes.h"
#include "ext_mode_profiling.h"

/************************************************************
 * Defines
 ************************************************************/
#define XCP_PROFILING_EVENT            6
#define MAX_EXECUTION_SECTION_ID       41
#define XCP_PROFILING_BUFFER_SIZE      (sizeof(uint32_T)*3 + sizeof(uint32_T)*MAX_EXECUTION_SECTION_ID*3)

/************************************************************
 * Global variables in the file
 ************************************************************/
static XcpErrorCode profilingLastErrorCode = XCP_SUCCESS;
XCP_MUTEX_DEFINE(profiling_mutex);
uint8_T xcpProfilingBuffer[XCP_PROFILING_BUFFER_SIZE] = { 0 };

/************************************************************
 * Functions
 ************************************************************/
XcpErrorCode extmodeInitProfiling(void)
{
  /* Initialize/reset profiling */

  /* Initialize profiling mutex */
  XCP_MUTEX_INIT(profiling_mutex);

  /* Reset profiling buffer */
  XCP_MEMSET((void*)xcpProfilingBuffer, 0, XCP_PROFILING_BUFFER_SIZE);
  writeIDsInProfilingBuffer(9, 10, 11);
  return XCP_SUCCESS;
}

uint32_T* getMaxElementInProfilingBuffer(uint32_T idx)
{
  uint32_T* addr = (uint32_T*)(xcpProfilingBuffer + sizeof(uint32_T));
  return addr+idx;
}

uint32_T* getAvgElementInProfilingBuffer(uint32_T idx)
{
  uint32_T* addr = (uint32_T*)(xcpProfilingBuffer + sizeof(uint32_T)+(sizeof
    (uint32_T) + sizeof(uint32_T)*MAX_EXECUTION_SECTION_ID));
  return addr+idx;
}

uint32_T* getCallsElementInProfilingBuffer(uint32_T idx)
{
  uint32_T* addr = (uint32_T*)(xcpProfilingBuffer + sizeof(uint32_T)+(sizeof
    (uint32_T) + sizeof(uint32_T)*MAX_EXECUTION_SECTION_ID)*2);
  return addr+idx;
}

void writeIDsInProfilingBuffer(uint32_T idxMax, uint32_T idxAvg, uint32_T
  idxCalls)
{
  uint32_T* addr = (uint32_T*)(xcpProfilingBuffer);
  *addr = idxMax;
  addr = (uint32_T*)(xcpProfilingBuffer + (sizeof(uint32_T) + sizeof(uint32_T)
    *MAX_EXECUTION_SECTION_ID));
  *addr = idxAvg;
  addr = (uint32_T*)(xcpProfilingBuffer + (sizeof(uint32_T)*2 + sizeof(uint32_T)*
    MAX_EXECUTION_SECTION_ID*2));
  *addr = idxCalls;
}

XcpErrorCode extmodeGetLastProfilingError (void)
{
  XcpErrorCode old = profilingLastErrorCode;
  profilingLastErrorCode = XCP_SUCCESS;
  return old;
}
