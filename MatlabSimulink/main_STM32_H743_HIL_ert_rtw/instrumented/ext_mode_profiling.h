#ifndef __XCP_PROFILING_HEADER__
#define __XCP_PROFILING_HEADER__

/* Include main XCP header with XcpErrorCode type definition */
/* Functions with a C call interface */
#ifdef __cplusplus

extern "C"
{

#endif

#include "xcp.h"
#ifdef XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME
#include "xcp_ext_common.h"
#endif

  /* Functions with a C call interface */
#ifdef __cplusplus

}

#endif

/* Include main instrumentation header */
#include "code_profiling_utility_functions.h"

/* Methods to get element address in the profiling buffer */
uint32_T* getMaxElementInProfilingBuffer(uint32_T idx);
uint32_T* getAvgElementInProfilingBuffer(uint32_T idx);
uint32_T* getCallsElementInProfilingBuffer(uint32_T idx);
void writeIDsInProfilingBuffer(uint32_T idxMax, uint32_T idxAvg, uint32_T
  idxCalls);
XcpErrorCode extmodeInitProfiling(void);

/* This method returns the last error happened since the last call of extmodeGetLastProfilingError */
extern XcpErrorCode extmodeGetLastProfilingError(void);

#endif
