/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_STM32_H743_HIL.c
 *
 * Code generated for Simulink model 'main_STM32_H743_HIL'.
 *
 * Model version                  : 2.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jan  6 21:34:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_STM32_H743_HIL.h"
#include "rtwtypes.h"
#include "main_STM32_H743_HIL_types.h"
#include "main_STM32_H743_HIL_private.h"
#include "mw_stm32_spi_ll.h"
#include "rt_roundd_snf.h"
#include "stm_timer_ll.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "ECU_RCP.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Named constants for MATLAB Function: '<S14>/MATLAB Function' */
#define main_STM32_H743_HIL_CALL_EVENT (-1)

/* Named constants for MATLAB Function: '<S14>/MATLAB Function1' */
#define main_STM32_H743_HI_CALL_EVENT_o (-1)

rtTimingBridge main_STM32_H743_HIL_TimingBrdg;

/* Block signals (default storage) */
B_main_STM32_H743_HIL_T main_STM32_H743_HIL_B;

/* Block states (default storage) */
DW_main_STM32_H743_HIL_T main_STM32_H743_HIL_DW;

/* Real-time model */
static RT_MODEL_main_STM32_H743_HIL_T main_STM32_H743_HIL_M_;
RT_MODEL_main_STM32_H743_HIL_T *const main_STM32_H743_HIL_M =
  &main_STM32_H743_HIL_M_;

/* Forward declaration for local functions */
static void main_STM32_H74_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void main_STM32_H_SystemCore_setup_l(stm32cube_blocks_TimerCapture_T *obj);

/* Forward declaration for local functions */
static void main_S_MedianFilterCG_resetImpl(c_dsp_internal_MedianFilter_c_T *obj);
static void m_MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilter_c_T *obj,
  real32_T i);
static void m_MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilter_c_T *obj,
  real32_T i);
static void main_STM32__SystemCore_setup_cs(stm32cube_blocks_AnalogInputF_T *obj);
static void main_ST_SystemCore_setup_cslt2a(stm32cube_blocks_PWMOutput_ma_T *obj);
static void main_STM32_H_SystemCore_setup_c(stm32cube_blocks_AnalogInputF_T *obj);
static void main_STM_SystemCore_setup_cslt2(stm32cube_blocks_UARTWrite_ma_T *obj);
static void main_STM3_SystemCore_setup_cslt(stm32cube_blocks_UARTRead_mai_T *obj);
static void main_STM32_SystemCore_setup_csl(stm32cube_blocks_EncoderBlock_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void main_STM32_H743_HIL_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(main_STM32_H743_HIL_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(main_STM32_H743_HIL_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(main_STM32_H743_HIL_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(main_STM32_H743_HIL_M, 4));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2, 3 */
  main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1 =
    (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1] == 0);
  main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_2 =
    (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2] == 0);
  main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3 =
    (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] == 0);

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_2 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2] == 0);
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* tid 2 shares data with slower tid rates: 3, 4 */
  if (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2] == 0) {
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_3 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] == 0);
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_4 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[4] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1])++;
  if ((main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.005s, 0.0s] */
    main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1] = 0;
  }

  (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2])++;
  if ((main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2] = 0;
  }

  (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3])++;
  if ((main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3]) > 49) {/* Sample time: [0.05s, 0.0s] */
    main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] = 0;
  }

  (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[4])++;
  if ((main_STM32_H743_HIL_M->Timing.TaskCounters.TID[4]) > 99) {/* Sample time: [0.1s, 0.0s] */
    main_STM32_H743_HIL_M->Timing.TaskCounters.TID[4] = 0;
  }
}

static void main_STM32_H74_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S8>/SPI Controller Transfer2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = SPI3;
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_2);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_2);
  obj->isSetupComplete = true;
}

/* Start for atomic system: */
void SPIControllerTransfer_Start(DW_SPIControllerTransfer2_mai_T *localDW)
{
  /* Start for MATLABSystem: '<S8>/SPI Controller Transfer2' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  main_STM32_H74_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void main_SPIControllerTransfer2(uint16_T rtu_0, B_SPIControllerTransfer2_main_T
  *localB, DW_SPIControllerTransfer2_mai_T *localDW)
{
  uint8_T status;

  /* MATLABSystem: '<S8>/SPI Controller Transfer2' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0, true);
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_2);
  if (status == 0) {
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0,
      &localB->SPIControllerTransfer2, 1, 1U, 0, 1U);
  }

  /* End of MATLABSystem: '<S8>/SPI Controller Transfer2' */
}

/* Termination for atomic system: */
void SPIControllerTransfer2_Term(DW_SPIControllerTransfer2_mai_T *localDW)
{
  /* Terminate for MATLABSystem: '<S8>/SPI Controller Transfer2' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/SPI Controller Transfer2' */
}

/*
 * System initialize for atomic system:
 *    '<S14>/MATLAB Function'
 *    '<S14>/MATLAB Function3'
 */
void main_ST_MATLABFunction_Init(DW_MATLABFunction_main_STM32__T *localDW)
{
  localDW->sfEvent = main_STM32_H743_HIL_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S14>/MATLAB Function'
 *    '<S14>/MATLAB Function3'
 */
void main_STM32_H_MATLABFunction(int32_T rtu_u, uint8_T rty_byte_array[4],
  DW_MATLABFunction_main_STM32__T *localDW)
{
  int32_T saturatedUnaryMinus;
  uint32_T qY;
  uint32_T qY_tmp;
  uint8_T byte2;
  uint8_T byte3;
  uint8_T num_abs;
  localDW->sfEvent = main_STM32_H743_HIL_CALL_EVENT;
  if (rtu_u < 0) {
    if (rtu_u <= MIN_int32_T) {
      saturatedUnaryMinus = MAX_int32_T;
    } else {
      saturatedUnaryMinus = -rtu_u;
    }

    if (saturatedUnaryMinus > 255) {
      saturatedUnaryMinus = 255;
    }

    num_abs = (uint8_T)saturatedUnaryMinus;
  } else {
    saturatedUnaryMinus = rtu_u;
    if (rtu_u > 255) {
      saturatedUnaryMinus = 255;
    }

    num_abs = (uint8_T)saturatedUnaryMinus;
  }

  byte3 = (uint8_T)(num_abs - (uint32_T)((int32_T)(num_abs / 100U) * 100));
  qY = (uint32_T)num_abs - /*MW:OvSatOk*/ byte3;
  if (qY > num_abs) {
    qY = 0U;
  }

  byte2 = (uint8_T)((int32_T)rt_roundd_snf((real_T)qY / 100.0) + 48);
  qY_tmp = (uint8_T)(num_abs - (uint32_T)((int32_T)(num_abs / 10U) * 10));
  qY = byte3 - /*MW:OvSatOk*/ qY_tmp;
  if (qY > byte3) {
    qY = 0U;
  }

  byte3 = (uint8_T)((int32_T)rt_roundd_snf((real_T)qY / 10.0) + 48);
  if (num_abs < 100) {
    byte2 = 32U;
  }

  if (num_abs < 10) {
    byte3 = 32U;
  }

  if ((rtu_u > 0) || (!(rtu_u < 0))) {
    rty_byte_array[0] = 32U;
  } else {
    rty_byte_array[0] = 45U;
    if (num_abs < 100) {
      rty_byte_array[0] = 32U;
      byte2 = 45U;
    }

    if (num_abs < 10) {
      rty_byte_array[0] = 32U;
      byte2 = 32U;
      byte3 = 45U;
    }
  }

  rty_byte_array[1] = byte2;
  rty_byte_array[2] = byte3;
  saturatedUnaryMinus = (int32_T)(qY_tmp + 1U);
  if (qY_tmp + 1U > 255U) {
    saturatedUnaryMinus = 255;
  }

  rty_byte_array[3] = (uint8_T)((uint32_T)saturatedUnaryMinus + 47U);
}

/*
 * System initialize for atomic system:
 *    '<S14>/MATLAB Function1'
 *    '<S14>/MATLAB Function2'
 */
void main_S_MATLABFunction1_Init(DW_MATLABFunction1_main_STM32_T *localDW)
{
  localDW->sfEvent = main_STM32_H743_HI_CALL_EVENT_o;
}

/*
 * Output and update for atomic system:
 *    '<S14>/MATLAB Function1'
 *    '<S14>/MATLAB Function2'
 */
void main_STM32__MATLABFunction1(int32_T rtu_u, uint8_T rty_byte_array[4],
  DW_MATLABFunction1_main_STM32_T *localDW)
{
  uint32_T num_abs;
  uint32_T qY;
  uint32_T temp1;
  uint32_T temp2;
  uint8_T byte2;
  uint8_T byte3;
  localDW->sfEvent = main_STM32_H743_HI_CALL_EVENT_o;
  if (rtu_u < 0) {
    if (rtu_u <= MIN_int32_T) {
      num_abs = 2147483647U;
    } else {
      num_abs = (uint32_T)-rtu_u;
    }
  } else {
    num_abs = (uint32_T)rtu_u;
  }

  temp1 = num_abs - num_abs / 1000U * 1000U;
  qY = num_abs - /*MW:OvSatOk*/ temp1;
  if (qY > num_abs) {
    qY = 0U;
  }

  rty_byte_array[0] = (uint8_T)((uint8_T)(int32_T)rt_roundd_snf((real_T)qY /
    1000.0) + 48U);
  temp2 = num_abs - num_abs / 100U * 100U;
  qY = temp1 - /*MW:OvSatOk*/ temp2;
  if (qY > temp1) {
    qY = 0U;
  }

  byte2 = (uint8_T)((uint8_T)(int32_T)rt_roundd_snf((real_T)qY / 100.0) + 48U);
  temp1 = num_abs - num_abs / 10U * 10U;
  qY = temp2 - /*MW:OvSatOk*/ temp1;
  if (qY > temp2) {
    qY = 0U;
  }

  byte3 = (uint8_T)((uint8_T)(int32_T)rt_roundd_snf((real_T)qY / 10.0) + 48U);
  if ((int32_T)num_abs < 1000) {
    rty_byte_array[0] = 32U;
  }

  if ((int32_T)num_abs < 100) {
    byte2 = 32U;
  }

  if ((int32_T)num_abs < 10) {
    byte3 = 32U;
  }

  rty_byte_array[1] = byte2;
  rty_byte_array[2] = byte3;
  qY = temp1 + /*MW:OvSatOk*/ 1U;
  if (temp1 + 1U < temp1) {
    qY = MAX_uint32_T;
  }

  rty_byte_array[3] = (uint8_T)((uint8_T)((int32_T)qY - 1) + 48U);
}

static void main_STM32_H_SystemCore_setup_l(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S13>/Timer Capture1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM15;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S13>/Timer Capture1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 2);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S13>/Timer Capture1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void main_S_MedianFilterCG_resetImpl(c_dsp_internal_MedianFilter_c_T *obj)
{
  for (main_STM32_H743_HIL_B.i_c = 0; main_STM32_H743_HIL_B.i_c < 10;
       main_STM32_H743_HIL_B.i_c++) {
    /* Start for MATLABSystem: '<Root>/Median Filter2' */
    obj->pBuf[main_STM32_H743_HIL_B.i_c] = 0.0F;
    obj->pPos[main_STM32_H743_HIL_B.i_c] = 0.0F;
    obj->pHeap[main_STM32_H743_HIL_B.i_c] = 0.0F;
  }

  /* Start for MATLABSystem: '<Root>/Median Filter2' */
  obj->pWinLen = 10.0F;
  obj->pIdx = obj->pWinLen;

  /* Start for MATLABSystem: '<Root>/Median Filter2' */
  obj->pMidHeap = ceilf((obj->pWinLen + 1.0F) / 2.0F);
  obj->pMinHeapLength = truncf((obj->pWinLen - 1.0F) / 2.0F);
  obj->pMaxHeapLength = truncf(obj->pWinLen / 2.0F);
  main_STM32_H743_HIL_B.cnt1 = 1.0F;
  main_STM32_H743_HIL_B.cnt2 = obj->pWinLen;
  for (main_STM32_H743_HIL_B.i_c = 0; main_STM32_H743_HIL_B.i_c < 10;
       main_STM32_H743_HIL_B.i_c++) {
    /* Start for MATLABSystem: '<Root>/Median Filter2' */
    if (fmodf(10.0F - (real32_T)main_STM32_H743_HIL_B.i_c, 2.0F) == 0.0F) {
      obj->pPos[9 - main_STM32_H743_HIL_B.i_c] = main_STM32_H743_HIL_B.cnt1;
      main_STM32_H743_HIL_B.cnt1++;
    } else {
      obj->pPos[9 - main_STM32_H743_HIL_B.i_c] = main_STM32_H743_HIL_B.cnt2;
      main_STM32_H743_HIL_B.cnt2--;
    }

    obj->pHeap[(int32_T)obj->pPos[9 - main_STM32_H743_HIL_B.i_c] - 1] = 10.0F -
      (real32_T)main_STM32_H743_HIL_B.i_c;
  }
}

static void m_MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilter_c_T *obj,
  real32_T i)
{
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i >= -obj->pMaxHeapLength)) {
    if ((i < -1.0F) && (i > -obj->pMaxHeapLength) && (obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)(i + obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)((i - 1.0F) + obj->pMidHeap) - 1] - 1])) {
      i--;
    }

    main_STM32_H743_HIL_B.ind1_c = truncf(i / 2.0F) + obj->pMidHeap;
    main_STM32_H743_HIL_B.ind2_b = i + obj->pMidHeap;
    main_STM32_H743_HIL_B.f2 = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1_c
      - 1];
    main_STM32_H743_HIL_B.f3 = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2_b
      - 1];
    if (!(obj->pBuf[(int32_T)main_STM32_H743_HIL_B.f2 - 1] < obj->pBuf[(int32_T)
          main_STM32_H743_HIL_B.f3 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1_c - 1] =
        main_STM32_H743_HIL_B.f3;
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2_b - 1] =
        main_STM32_H743_HIL_B.f2;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1_c - 1] -
        1] = main_STM32_H743_HIL_B.ind1_c;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2_b - 1] -
        1] = main_STM32_H743_HIL_B.ind2_b;
      i *= 2.0F;
    }
  }
}

static void m_MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilter_c_T *obj,
  real32_T i)
{
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i <= obj->pMinHeapLength)) {
    if ((i > 1.0F) && (i < obj->pMinHeapLength) && (obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)((i + 1.0F) + obj->pMidHeap) - 1] - 1] < obj->pBuf
         [(int32_T)obj->pHeap[(int32_T)(i + obj->pMidHeap) - 1] - 1])) {
      i++;
    }

    main_STM32_H743_HIL_B.ind1 = i + obj->pMidHeap;
    main_STM32_H743_HIL_B.ind2 = truncf(i / 2.0F) + obj->pMidHeap;
    main_STM32_H743_HIL_B.f_k = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1 -
      1];
    main_STM32_H743_HIL_B.f1 = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2 -
      1];
    if (!(obj->pBuf[(int32_T)main_STM32_H743_HIL_B.f_k - 1] < obj->pBuf[(int32_T)
          main_STM32_H743_HIL_B.f1 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1 - 1] =
        main_STM32_H743_HIL_B.f1;
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2 - 1] =
        main_STM32_H743_HIL_B.f_k;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1 - 1] - 1]
        = main_STM32_H743_HIL_B.ind1;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2 - 1] - 1]
        = main_STM32_H743_HIL_B.ind2;
      i *= 2.0F;
    }
  }
}

static void main_STM32__SystemCore_setup_cs(stm32cube_blocks_AnalogInputF_T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADCAutomaticCalibration(obj->ADCHandle, (uint32_T)
    LL_ADC_CALIB_OFFSET_LINEARITY, 0);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

static void main_ST_SystemCore_setup_cslt2a(stm32cube_blocks_PWMOutput_ma_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S29>/PWM Output' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM13;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S29>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S29>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void main_STM32_H_SystemCore_setup_c(stm32cube_blocks_AnalogInputF_T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC3;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADCAutomaticCalibration(obj->ADCHandle, (uint32_T)
    LL_ADC_CALIB_OFFSET_LINEARITY, 0);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

static void main_STM_SystemCore_setup_cslt2(stm32cube_blocks_UARTWrite_ma_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S14>/UART//USART Write' */
  obj->isInitialized = 1;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = USART2;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void main_STM3_SystemCore_setup_cslt(stm32cube_blocks_UARTRead_mai_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S14>/UART//USART Read' */
  obj->isInitialized = 1;
  b.buffer.rxBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 1.0;

  /* Start for MATLABSystem: '<S14>/UART//USART Read' */
  b.mode = UART_RX_INTERRUPT_MODE;
  b.peripheralPtr = USART2;
  b.rxdmaPeripheralPtr = NULL;
  b.rxdmastream = 0;
  b.disableDMAIntOnError = false;

  /* Start for MATLABSystem: '<S14>/UART//USART Read' */
  b.buffer.rxBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void main_STM32_SystemCore_setup_csl(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S9>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S9>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<S9>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S9>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void main_STM32_H743_HIL_step0(void)   /* Sample time: [0.001s, 0.0s] */
{
  c_dsp_internal_MedianFilter_c_T *obj;
  boolean_T exitg1;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S18>/Analog to Digital Converter' */
  regularReadADCNormal(main_STM32_H743_HIL_DW.obj_n.ADCHandle,
                       ADC_TRIGGER_AND_READ,
                       &main_STM32_H743_HIL_B.AnalogtoDigitalConverter);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  main_STM32_H743_HIL_B.DataTypeConversion3 = (real32_T)
    main_STM32_H743_HIL_B.AnalogtoDigitalConverter;

  /* RateTransition generated from: '<Root>/Model' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Model' */
    main_STM32_H743_HIL_B.v_ist_kmh = main_STM32_H743_HIL_DW.v_ist_kmh_Buffer0;

    /* RateTransition generated from: '<Root>/Model' */
    main_STM32_H743_HIL_B.nMot_1pmin =
      main_STM32_H743_HIL_DW.TmpRTBAtModelInport5_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Model' */

  /* RateTransition generated from: '<Root>/Model' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition generated from: '<Root>/Model' */
    main_STM32_H743_HIL_B.PG4_in_Kupplung =
      main_STM32_H743_HIL_DW.TmpRTBAtModelInport7_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Model' */

  /* ModelReference: '<Root>/Model' incorporates:
   *  Constant: '<Root>/phi3_driver_norm'
   *  Constant: '<Root>/vst_factor'
   */
  ECU_RCPTID0(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtm),
              &main_STM32_H743_HIL_B.DataTypeConversion3,
              &main_STM32_H743_HIL_P.phi3_driver_norm_Value,
              &main_STM32_H743_HIL_B.v_ist_kmh,
              &main_STM32_H743_HIL_B.nMot_1pmin,
              &main_STM32_H743_HIL_B.PG4_in_Kupplung,
              &main_STM32_H743_HIL_P.vst_factor_Value,
              &main_STM32_H743_HIL_B.u_ref,
              &main_STM32_H743_HIL_B.phi3_M_filt_norm,
              &main_STM32_H743_HIL_B.i_calc_ext,
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));

  /* MATLABSystem: '<S24>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  main_STM32_H743_HIL_B.portNameLoc = GPIOA;
  if (main_STM32_H743_HIL_B.u_ref >= main_STM32_H743_HIL_P.Constant_Value_m) {
    main_STM32_H743_HIL_B.c_p = 1024;
  } else {
    main_STM32_H743_HIL_B.c_p = 0;
  }

  LL_GPIO_SetOutputPin(main_STM32_H743_HIL_B.portNameLoc, (uint32_T)
                       main_STM32_H743_HIL_B.c_p);
  LL_GPIO_ResetOutputPin(main_STM32_H743_HIL_B.portNameLoc, ~(uint32_T)
    main_STM32_H743_HIL_B.c_p & 1024U);

  /* End of MATLABSystem: '<S24>/Digital Port Write' */

  /* MATLABSystem: '<S29>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   *  Gain: '<Root>/Gain1'
   */
  setDutyCycleInPercentageChannel1(main_STM32_H743_HIL_DW.obj_m3.TimerHandle,
    main_STM32_H743_HIL_P.Gain1_Gain * fabsf(main_STM32_H743_HIL_B.u_ref));

  /* ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter2' */

  /* RateTransition generated from: '<Root>/Memory1' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3) {
    /* RateTransition generated from: '<Root>/Memory1' */
    main_STM32_H743_HIL_B.TmpRTBAtMemory1Inport1 =
      main_STM32_H743_HIL_DW.TmpRTBAtMemory1Inport1_Buffer0;

    /* RateTransition generated from: '<Root>/Memory' */
    main_STM32_H743_HIL_B.TmpRTBAtMemoryInport1 =
      main_STM32_H743_HIL_DW.TmpRTBAtMemoryInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Memory1' */

  /* RateTransition generated from: '<Root>/Subsystem' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1) {
    main_STM32_H743_HIL_DW.TmpRTBAtSubsystemInport1_Buffer =
      main_STM32_H743_HIL_B.phi3_M_filt_norm;
  }

  /* End of RateTransition generated from: '<Root>/Subsystem' */

  /* RateTransition generated from: '<Root>/data_exchange_HMI' incorporates:
   *  Memory: '<Root>/Memory'
   */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3) {
    main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInport =
      main_STM32_H743_HIL_DW.Memory_PreviousInput;

    /* RateTransition generated from: '<Root>/data_exchange_HMI' incorporates:
     *  Memory: '<Root>/Memory'
     *  Memory: '<Root>/Memory1'
     */
    main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_c =
      main_STM32_H743_HIL_DW.Memory1_PreviousInput;

    /* RateTransition generated from: '<Root>/data_exchange_HMI' incorporates:
     *  Memory: '<Root>/Memory2'
     */
    main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_g =
      main_STM32_H743_HIL_DW.Memory2_PreviousInput;
  }

  /* End of RateTransition generated from: '<Root>/data_exchange_HMI' */

  /* RateTransition generated from: '<Root>/Model' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Model' */
    main_STM32_H743_HIL_B.a_ist_mps2 = main_STM32_H743_HIL_DW.xpp_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Model' */

  /* MATLABSystem: '<S16>/Analog to Digital Converter' */
  regularReadADCNormal(main_STM32_H743_HIL_DW.obj_m.ADCHandle,
                       ADC_TRIGGER_AND_READ,
                       &main_STM32_H743_HIL_B.AnalogtoDigitalConverter_c);

  /* ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter1' */

  /* MATLABSystem: '<Root>/Median Filter2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  obj = &main_STM32_H743_HIL_DW.obj.pMID;
  if (main_STM32_H743_HIL_DW.obj.pMID.isInitialized != 1) {
    main_STM32_H743_HIL_DW.obj.pMID.isInitialized = 1;
    main_STM32_H743_HIL_DW.obj.pMID.isSetupComplete = true;
    main_S_MedianFilterCG_resetImpl(&main_STM32_H743_HIL_DW.obj.pMID);
  }

  main_STM32_H743_HIL_B.vprev = main_STM32_H743_HIL_DW.obj.pMID.pBuf[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pIdx - 1];
  main_STM32_H743_HIL_DW.obj.pMID.pBuf[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pIdx - 1] = (real32_T)
    main_STM32_H743_HIL_B.AnalogtoDigitalConverter_c;
  main_STM32_H743_HIL_B.p = main_STM32_H743_HIL_DW.obj.pMID.pPos[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pIdx - 1];
  main_STM32_H743_HIL_DW.obj.pMID.pIdx++;
  if (main_STM32_H743_HIL_DW.obj.pMID.pWinLen + 1.0F ==
      main_STM32_H743_HIL_DW.obj.pMID.pIdx) {
    main_STM32_H743_HIL_DW.obj.pMID.pIdx = 1.0F;
  }

  if (main_STM32_H743_HIL_B.p > main_STM32_H743_HIL_DW.obj.pMID.pMidHeap) {
    if (main_STM32_H743_HIL_B.vprev <
        main_STM32_H743_HIL_B.AnalogtoDigitalConverter_c) {
      main_STM32_H743_HIL_B.vprev = main_STM32_H743_HIL_B.p -
        main_STM32_H743_HIL_DW.obj.pMID.pMidHeap;
      m_MedianFilterCG_trickleDownMin(&main_STM32_H743_HIL_DW.obj.pMID,
        main_STM32_H743_HIL_B.vprev * 2.0F);
    } else {
      main_STM32_H743_HIL_B.vprev = main_STM32_H743_HIL_B.p -
        main_STM32_H743_HIL_DW.obj.pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (main_STM32_H743_HIL_B.vprev > 0.0F)) {
        main_STM32_H743_HIL_B.flag_tmp = truncf(main_STM32_H743_HIL_B.vprev /
          2.0F);
        main_STM32_H743_HIL_B.flag = (obj->pBuf[(int32_T)obj->pHeap[(int32_T)
          (main_STM32_H743_HIL_B.vprev + obj->pMidHeap) - 1] - 1] < obj->pBuf
          [(int32_T)obj->pHeap[(int32_T)(main_STM32_H743_HIL_B.flag_tmp +
          obj->pMidHeap) - 1] - 1]);
        if (!main_STM32_H743_HIL_B.flag) {
          exitg1 = true;
        } else {
          main_STM32_H743_HIL_B.p = main_STM32_H743_HIL_B.vprev + obj->pMidHeap;
          main_STM32_H743_HIL_B.flag_tmp += obj->pMidHeap;
          main_STM32_H743_HIL_B.temp = obj->pHeap[(int32_T)
            main_STM32_H743_HIL_B.p - 1];
          obj->pHeap[(int32_T)main_STM32_H743_HIL_B.p - 1] = obj->pHeap[(int32_T)
            main_STM32_H743_HIL_B.flag_tmp - 1];
          obj->pHeap[(int32_T)main_STM32_H743_HIL_B.flag_tmp - 1] =
            main_STM32_H743_HIL_B.temp;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.p - 1] -
            1] = main_STM32_H743_HIL_B.p;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.flag_tmp
            - 1] - 1] = main_STM32_H743_HIL_B.flag_tmp;
          main_STM32_H743_HIL_B.vprev = truncf(main_STM32_H743_HIL_B.vprev /
            2.0F);
        }
      }

      if (main_STM32_H743_HIL_B.vprev == 0.0F) {
        m_MedianFilterCG_trickleDownMax(&main_STM32_H743_HIL_DW.obj.pMID, -1.0F);
      }
    }
  } else if (main_STM32_H743_HIL_B.p < main_STM32_H743_HIL_DW.obj.pMID.pMidHeap)
  {
    if (main_STM32_H743_HIL_B.AnalogtoDigitalConverter_c <
        main_STM32_H743_HIL_B.vprev) {
      main_STM32_H743_HIL_B.vprev = main_STM32_H743_HIL_B.p -
        main_STM32_H743_HIL_DW.obj.pMID.pMidHeap;
      m_MedianFilterCG_trickleDownMax(&main_STM32_H743_HIL_DW.obj.pMID,
        main_STM32_H743_HIL_B.vprev * 2.0F);
    } else {
      main_STM32_H743_HIL_B.vprev = main_STM32_H743_HIL_B.p -
        main_STM32_H743_HIL_DW.obj.pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (main_STM32_H743_HIL_B.vprev < 0.0F)) {
        main_STM32_H743_HIL_B.flag_tmp = truncf(main_STM32_H743_HIL_B.vprev /
          2.0F);
        main_STM32_H743_HIL_B.flag = (obj->pBuf[(int32_T)obj->pHeap[(int32_T)
          (main_STM32_H743_HIL_B.flag_tmp + obj->pMidHeap) - 1] - 1] < obj->
          pBuf[(int32_T)obj->pHeap[(int32_T)(main_STM32_H743_HIL_B.vprev +
          obj->pMidHeap) - 1] - 1]);
        if (!main_STM32_H743_HIL_B.flag) {
          exitg1 = true;
        } else {
          main_STM32_H743_HIL_B.p = main_STM32_H743_HIL_B.flag_tmp +
            obj->pMidHeap;
          main_STM32_H743_HIL_B.flag_tmp = main_STM32_H743_HIL_B.vprev +
            obj->pMidHeap;
          main_STM32_H743_HIL_B.temp = obj->pHeap[(int32_T)
            main_STM32_H743_HIL_B.p - 1];
          obj->pHeap[(int32_T)main_STM32_H743_HIL_B.p - 1] = obj->pHeap[(int32_T)
            main_STM32_H743_HIL_B.flag_tmp - 1];
          obj->pHeap[(int32_T)main_STM32_H743_HIL_B.flag_tmp - 1] =
            main_STM32_H743_HIL_B.temp;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.p - 1] -
            1] = main_STM32_H743_HIL_B.p;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.flag_tmp
            - 1] - 1] = main_STM32_H743_HIL_B.flag_tmp;
          main_STM32_H743_HIL_B.vprev = truncf(main_STM32_H743_HIL_B.vprev /
            2.0F);
        }
      }

      if (main_STM32_H743_HIL_B.vprev == 0.0F) {
        m_MedianFilterCG_trickleDownMin(&main_STM32_H743_HIL_DW.obj.pMID, 1.0F);
      }
    }
  } else {
    if (main_STM32_H743_HIL_DW.obj.pMID.pMaxHeapLength != 0.0F) {
      m_MedianFilterCG_trickleDownMax(&main_STM32_H743_HIL_DW.obj.pMID, -1.0F);
    }

    if (main_STM32_H743_HIL_DW.obj.pMID.pMinHeapLength > 0.0F) {
      m_MedianFilterCG_trickleDownMin(&main_STM32_H743_HIL_DW.obj.pMID, 1.0F);
    }
  }

  main_STM32_H743_HIL_B.vprev = main_STM32_H743_HIL_DW.obj.pMID.pBuf[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pHeap[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pMidHeap - 1] - 1];
  main_STM32_H743_HIL_B.vprev += main_STM32_H743_HIL_DW.obj.pMID.pBuf[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pHeap[(int32_T)
    (main_STM32_H743_HIL_DW.obj.pMID.pMidHeap - 1.0F) - 1] - 1];

  /* MATLABSystem: '<Root>/Median Filter2' */
  main_STM32_H743_HIL_B.A3_filt = main_STM32_H743_HIL_B.vprev / 2.0F;

  /* ToAsyncQueueBlock generated from: '<Root>/Median Filter2' */

  /* MATLABSystem: '<S22>/Digital Port Write' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  main_STM32_H743_HIL_B.portNameLoc = GPIOC;
  if (main_STM32_H743_HIL_P.Constant_Value_p !=
      main_STM32_H743_HIL_P.Constant_Value) {
    main_STM32_H743_HIL_B.c_p = 64;
  } else {
    main_STM32_H743_HIL_B.c_p = 0;
  }

  LL_GPIO_SetOutputPin(main_STM32_H743_HIL_B.portNameLoc, (uint32_T)
                       main_STM32_H743_HIL_B.c_p);
  LL_GPIO_ResetOutputPin(main_STM32_H743_HIL_B.portNameLoc, ~(uint32_T)
    main_STM32_H743_HIL_B.c_p & 64U);

  /* End of MATLABSystem: '<S22>/Digital Port Write' */

  /* Update for Memory: '<Root>/Memory' */
  main_STM32_H743_HIL_DW.Memory_PreviousInput =
    main_STM32_H743_HIL_B.TmpRTBAtMemoryInport1;

  /* Update for Memory: '<Root>/Memory1' */
  main_STM32_H743_HIL_DW.Memory1_PreviousInput =
    main_STM32_H743_HIL_B.TmpRTBAtMemory1Inport1;

  /* Update for Memory: '<Root>/Memory2' */
  main_STM32_H743_HIL_DW.Memory2_PreviousInput =
    main_STM32_H743_HIL_B.i_calc_ext;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  main_STM32_H743_HIL_M->Timing.taskTime0 =
    ((time_T)(++main_STM32_H743_HIL_M->Timing.clockTick0)) *
    main_STM32_H743_HIL_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void main_STM32_H743_HIL_step1(void)   /* Sample time: [0.005s, 0.0s] */
{
  real_T xpp_tmp;
  real32_T n_Mot1min_tmp;
  real32_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Constant: '<S12>/Constant' incorporates:
   *  Constant: '<Root>/gear'
   *  Selector: '<S12>/Selector'
   */
  n_Mot1min_tmp = (real32_T)rtP_iG_car[(int32_T)main_STM32_H743_HIL_P.gear_Value];

  /* Gain: '<S12>/Gain8' incorporates:
   *  Constant: '<S12>/Constant'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Gain: '<S12>/Gain6'
   *  Gain: '<S12>/Gain7'
   *  Product: '<S12>/Product2'
   */
  main_STM32_H743_HIL_B.n_Mot1min = (real32_T)(1.0 / rtP_r_dyn) *
    main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE * (real32_T)rtP_iD_car *
    n_Mot1min_tmp * main_STM32_H743_HIL_P.Gain8_Gain;

  /* Signum: '<S12>/Sign' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   */
  if (rtIsNaNF(main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE)) {
    tmp = (rtNaNF);
  } else if (main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE < 0.0F) {
    tmp = -1.0F;
  } else {
    tmp = (real32_T)(main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE > 0.0F);
  }

  /* Gain: '<S12>/Gain12' incorporates:
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S12>/Gain4'
   */
  xpp_tmp = rtP_m_F + rtP_m_Zu;

  /* Gain: '<S12>/Gain3' incorporates:
   *  Constant: '<Root>/gradient_relative'
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant3'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S12>/Gain10'
   *  Gain: '<S12>/Gain11'
   *  Gain: '<S12>/Gain12'
   *  Gain: '<S12>/Gain2'
   *  Gain: '<S12>/Gain4'
   *  Gain: '<S12>/Gain5'
   *  Gain: '<S12>/Gain9'
   *  Math: '<S12>/Math Function'
   *  Math: '<S12>/Math Function1'
   *  Product: '<S12>/Product1'
   *  Product: '<S12>/Product3'
   *  RateTransition generated from: '<Root>/Subsystem'
   *  Signum: '<S12>/Sign'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S12>/Sum3'
   *  Sum: '<S12>/Sum5'
   *  Trigonometry: '<S12>/Trigonometric Function'
   *  Trigonometry: '<S12>/Trigonometric Function1'
   */
  main_STM32_H743_HIL_B.xpp = ((((((main_STM32_H743_HIL_B.n_Mot1min *
    main_STM32_H743_HIL_B.n_Mot1min * (real32_T)rtP_p[0] + (real32_T)rtP_p[1] *
    main_STM32_H743_HIL_B.n_Mot1min) + (real32_T)rtP_p[2]) *
    main_STM32_H743_HIL_DW.TmpRTBAtSubsystemInport1_Buffer + (real32_T)rtP_m_vkm
    * main_STM32_H743_HIL_B.n_Mot1min) + (real32_T)rtP_b_vkm) * (real32_T)
    rtP_eta * n_Mot1min_tmp * (real32_T)rtP_iD_car * (real32_T)(1.0 / rtP_r_stat)
    - (real32_T)(xpp_tmp * rtP_g) * sinf(atanf
    (main_STM32_H743_HIL_P.gradient_relative_Value))) - ((real32_T)(0.5 *
    rtP_c_W * rtP_A * rtP_p_L) *
    (main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE *
     main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE) + (real32_T)(xpp_tmp *
    rtP_f_R * rtP_g) * tmp)) * (real32_T)(1.0 / xpp_tmp);

  /* Gain: '<S12>/Gain13' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   */
  main_STM32_H743_HIL_B.Gain13 = main_STM32_H743_HIL_P.Gain13_Gain *
    main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE +=
    main_STM32_H743_HIL_P.DiscreteTimeIntegrator_gainval *
    main_STM32_H743_HIL_B.xpp;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* ModelReference: '<Root>/Model' */
  ECU_RCPTID1(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtm),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.TmpRTBAtModelInport5_Buffer0 =
    main_STM32_H743_HIL_B.n_Mot1min;

  /* RateTransition generated from: '<Root>/data_exchange_HMI' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3) {
    main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInp_gk =
      main_STM32_H743_HIL_B.Gain13;

    /* RateTransition generated from: '<Root>/data_exchange_HMI' */
    main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_d =
      main_STM32_H743_HIL_B.n_Mot1min;
  }

  /* End of RateTransition generated from: '<Root>/data_exchange_HMI' */

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.v_ist_kmh_Buffer0 = main_STM32_H743_HIL_B.Gain13;

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.xpp_Buffer0 = main_STM32_H743_HIL_B.xpp;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_STM32_H743_HIL_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void main_STM32_H743_HIL_step2(void)   /* Sample time: [0.01s, 0.0s] */
{
  real32_T tmp;

  /* MATLABSystem: '<S20>/Digital Port Read' */
  main_STM32_H743_HIL_B.portNameLoc_c = GPIOG;
  main_STM32_H743_HIL_B.pinReadLoc = LL_GPIO_ReadInputPort
    (main_STM32_H743_HIL_B.portNameLoc_c);
  main_STM32_H743_HIL_B.pinReadArrayLoc[0] = ((main_STM32_H743_HIL_B.pinReadLoc
    & 16U) != 0U);
  main_STM32_H743_HIL_B.pinReadArrayLoc[1] = ((main_STM32_H743_HIL_B.pinReadLoc
    & 32U) != 0U);
  main_STM32_H743_HIL_B.pinReadArrayLoc[2] = ((main_STM32_H743_HIL_B.pinReadLoc
    & 64U) != 0U);
  main_STM32_H743_HIL_B.pinReadArrayLoc[3] = ((main_STM32_H743_HIL_B.pinReadLoc
    & 128U) != 0U);
  main_STM32_H743_HIL_B.pinReadArrayLoc[4] = ((main_STM32_H743_HIL_B.pinReadLoc
    & 256U) != 0U);
  for (main_STM32_H743_HIL_B.i = 0; main_STM32_H743_HIL_B.i < 5;
       main_STM32_H743_HIL_B.i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
     *  MATLABSystem: '<S20>/Digital Port Read'
     *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
     */
    main_STM32_H743_HIL_B.DataTypeConversion7[main_STM32_H743_HIL_B.i] =
      (boolean_T)(main_STM32_H743_HIL_B.pinReadArrayLoc[main_STM32_H743_HIL_B.i]
                  ^ 1);
  }

  /* ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* ModelReference: '<Root>/Model' */
  ECU_RCPTID2(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtm),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));

  /* RateTransition generated from: '<Root>/Model' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_3) {
    main_STM32_H743_HIL_DW.TmpRTBAtModelInport6_Buffer =
      main_STM32_H743_HIL_B.DataTypeConversion7[2];
  }

  /* End of RateTransition generated from: '<Root>/Model' */

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.TmpRTBAtModelInport7_Buffer0 =
    main_STM32_H743_HIL_B.DataTypeConversion7[0];

  /* RateTransition generated from: '<Root>/Discrete Transfer Fcn3' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_4) {
    /* RateTransition generated from: '<Root>/Discrete Transfer Fcn3' */
    main_STM32_H743_HIL_B.count_diff_filt =
      main_STM32_H743_HIL_DW.count_diff_filt2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Discrete Transfer Fcn3' */

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_B.DiscreteTransferFcn3_tmp =
    ((main_STM32_H743_HIL_B.count_diff_filt -
      main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[0] * rtP_a_den_vFzg[1])
     - main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[1] * rtP_a_den_vFzg[2])
    / rtP_a_den_vFzg[0];

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_B.count_diff_filt3 = (rtP_b_num_vFzg[0] *
    main_STM32_H743_HIL_B.DiscreteTransferFcn3_tmp +
    main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[0] * rtP_b_num_vFzg[1]) +
    main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[1] * rtP_b_num_vFzg[2];

  /* ToAsyncQueueBlock generated from: '<Root>/Discrete Transfer Fcn3' */

  /* Gain: '<Root>/Gain9' */
  main_STM32_H743_HIL_B.v_ist_kmph_TIM3 = -rtP_ks_vel *
    main_STM32_H743_HIL_B.count_diff_filt3;

  /* ToAsyncQueueBlock generated from: '<Root>/Gain9' */

  /* Outputs for Atomic SubSystem: '<Root>/Fahrpedalsensor' */
  /* S-Function (sfix_bitop): '<S8>/Bitwise Operator1' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   */
  main_SPIControllerTransfer2((uint16_T)(main_STM32_H743_HIL_P.Constant2_Value |
    main_STM32_H743_HIL_P.Constant3_Value),
    &main_STM32_H743_HIL_B.SPIControllerTransfer3,
    &main_STM32_H743_HIL_DW.SPIControllerTransfer3);

  /* ArithShift: '<S8>/Shift Arithmetic1' incorporates:
   *  MATLABSystem: '<S8>/SPI Controller Transfer3'
   */
  main_STM32_H743_HIL_B.left_shift_2 = (uint16_T)
    (main_STM32_H743_HIL_B.SPIControllerTransfer3.SPIControllerTransfer2 << 2);

  /* ArithShift: '<S8>/Shift Arithmetic4' incorporates:
   *  ArithShift: '<S8>/Shift Arithmetic1'
   */
  main_STM32_H743_HIL_B.right_shift_2 = (uint16_T)((uint32_T)
    main_STM32_H743_HIL_B.left_shift_2 >> 2);

  /* Gain: '<S8>/Gain' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  main_STM32_H743_HIL_B.raw_angle_deg = main_STM32_H743_HIL_P.Gain_Gain *
    (real32_T)main_STM32_H743_HIL_B.right_shift_2;

  /* Saturate: '<S8>/Saturation' */
  if (main_STM32_H743_HIL_B.raw_angle_deg > rtP_ped_low_deg) {
    tmp = rtP_ped_low_deg;
  } else if (main_STM32_H743_HIL_B.raw_angle_deg < rtP_ped_high_deg) {
    tmp = rtP_ped_high_deg;
  } else {
    tmp = main_STM32_H743_HIL_B.raw_angle_deg;
  }

  /* Gain: '<S8>/Gain2' incorporates:
   *  Constant: '<S8>/Constant7'
   *  Saturate: '<S8>/Saturation'
   *  Sum: '<S8>/Sum'
   */
  main_STM32_H743_HIL_B.ped = (tmp - rtP_ped_low_deg) *
    main_STM32_H743_HIL_P.Gain2_Gain;

  /* ToAsyncQueueBlock generated from: '<S8>/Gain2' */

  /* ToAsyncQueueBlock generated from: '<S8>/Gain' */

  /* ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic4' */

  /* ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic1' */

  /* ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer3' */

  /* S-Function (sfix_bitop): '<S8>/Bitwise Operator' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   */
  main_SPIControllerTransfer2((uint16_T)(main_STM32_H743_HIL_P.Constant_Value_i |
    main_STM32_H743_HIL_P.Constant1_Value),
    &main_STM32_H743_HIL_B.SPIControllerTransfer2,
    &main_STM32_H743_HIL_DW.SPIControllerTransfer2);

  /* ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer2' */

  /* End of Outputs for SubSystem: '<Root>/Fahrpedalsensor' */

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[1] =
    main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[0];
  main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[0] =
    main_STM32_H743_HIL_B.DiscreteTransferFcn3_tmp;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_STM32_H743_HIL_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void main_STM32_H743_HIL_step3(void)   /* Sample time: [0.05s, 0.0s] */
{
  cell_wrap_0_main_STM32_H743_H_T e;
  cell_wrap_0_main_STM32_H743_H_T f;
  int32_T i;
  int32_T tmp_0;
  real32_T tmp;
  uint32_T dataBytesToRead;
  uint32_T sentLength;
  uint16_T status;
  static const uint8_T g[10] = { 109U, 97U, 110U, 117U, 97U, 108U, 32U, 32U, 32U,
    32U };

  static const uint8_T h[10] = { 97U, 99U, 116U, 105U, 118U, 101U, 32U, 32U, 32U,
    32U };

  static const uint8_T i_0[10] = { 108U, 105U, 109U, 105U, 116U, 101U, 114U, 32U,
    32U, 32U };

  static const uint8_T j[10] = { 100U, 114U, 118U, 114U, 95U, 111U, 118U, 114U,
    114U, 100U };

  static const uint8_T k[10] = { 99U, 108U, 117U, 116U, 99U, 104U, 32U, 32U, 32U,
    32U };

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC);

  /* S-Function (fcgen): '<Root>/Function-Call Generator5' incorporates:
   *  SubSystem: '<Root>/data_exchange_HMI'
   */
  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  RateTransition generated from: '<Root>/data_exchange_HMI'
   */
  tmp = floorf(main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInp_gk);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 4.2949673E+9F);
  }

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   */
  main_STM32_H_MATLABFunction(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_e,
    &main_STM32_H743_HIL_DW.sf_MATLABFunction_d);

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  RateTransition generated from: '<Root>/data_exchange_HMI'
   */
  tmp = floorf(main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_d);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 4.2949673E+9F);
  }

  /* MATLAB Function: '<S14>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion2'
   */
  main_STM32__MATLABFunction1(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_j,
    &main_STM32_H743_HIL_DW.sf_MATLABFunction1);

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  RateTransition generated from: '<Root>/data_exchange_HMI'
   */
  tmp = floorf(main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_g);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 4.2949673E+9F);
  }

  /* MATLAB Function: '<S14>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion3'
   */
  main_STM32__MATLABFunction1(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_n,
    &main_STM32_H743_HIL_DW.sf_MATLABFunction2);

  /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
   *  RateTransition generated from: '<Root>/data_exchange_HMI'
   */
  tmp = floorf(main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInport);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 4.2949673E+9F);
  }

  /* MATLAB Function: '<S14>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion5'
   */
  main_STM32_H_MATLABFunction(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_a,
    &main_STM32_H743_HIL_DW.sf_MATLABFunction3);

  /* MATLAB Function: '<S14>/MATLAB Function4' incorporates:
   *  RateTransition generated from: '<Root>/data_exchange_HMI'
   */
  for (i = 0; i < 10; i++) {
    main_STM32_H743_HIL_B.b_m.f1[i] = g[i];
    main_STM32_H743_HIL_B.c.f1[i] = h[i];
    main_STM32_H743_HIL_B.d.f1[i] = i_0[i];
    e.f1[i] = j[i];
    f.f1[i] = k[i];
  }

  main_STM32_H743_HIL_B.b[0] = main_STM32_H743_HIL_B.b_m;
  main_STM32_H743_HIL_B.b[1] = main_STM32_H743_HIL_B.c;
  main_STM32_H743_HIL_B.b[2] = main_STM32_H743_HIL_B.d;
  main_STM32_H743_HIL_B.b[3] = e;
  main_STM32_H743_HIL_B.b[4] = f;
  for (i = 0; i < 10; i++) {
    tmp_0 = (int32_T)(main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_c +
                      1U);
    if (main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_c + 1U > 255U) {
      tmp_0 = 255;
    }

    main_STM32_H743_HIL_B.byte_array[i] = main_STM32_H743_HIL_B.b[tmp_0 - 1]
      .f1[i];
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function4' */

  /* S-Function (any2byte_svd): '<S14>/Byte Pack' */

  /* Pack: <S14>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&main_STM32_H743_HIL_B.uart_tx_data[0] +
                        MW_outputPortOffset), (uint8_T*)
             &main_STM32_H743_HIL_B.byte_array_e[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 2 */
    /* Input data type - uint8_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&main_STM32_H743_HIL_B.uart_tx_data[0] +
                        MW_outputPortOffset), (uint8_T*)
             &main_STM32_H743_HIL_B.byte_array_j[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 3 */
    /* Input data type - uint8_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&main_STM32_H743_HIL_B.uart_tx_data[0] +
                        MW_outputPortOffset), (uint8_T*)
             &main_STM32_H743_HIL_B.byte_array_n[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 4 */
    /* Input data type - uint8_T, size - 4 */
    {
      MW_inputPortWidth = 4 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&main_STM32_H743_HIL_B.uart_tx_data[0] +
                        MW_outputPortOffset), (uint8_T*)
             &main_STM32_H743_HIL_B.byte_array_a[0], MW_inputPortWidth);
    }

    /* Offset calculations based on alignemnt for packing next input */
    MW_remainder1 = MW_inputPortWidth % 1;
    if (MW_remainder1 == 0) {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth;
    } else {
      MW_outputPortOffset = MW_outputPortOffset + MW_inputPortWidth + (1 -
        MW_remainder1);
    }

    /* Packing the values of Input 5 */
    /* Input data type - uint8_T, size - 10 */
    {
      MW_inputPortWidth = 10 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&main_STM32_H743_HIL_B.uart_tx_data[0] +
                        MW_outputPortOffset), (uint8_T*)
             &main_STM32_H743_HIL_B.byte_array[0], MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S14>/UART//USART Write' */
  for (i = 0; i < 26; i++) {
    main_STM32_H743_HIL_B.uartWriteData[i] =
      main_STM32_H743_HIL_B.uart_tx_data[i];
  }

  MW_UART_TransmitUsingInterrupt(main_STM32_H743_HIL_DW.obj_a.UARTHandle,
    &main_STM32_H743_HIL_B.uartWriteData[0], 26U, 0U, &sentLength);

  /* End of MATLABSystem: '<S14>/UART//USART Write' */

  /* MATLABSystem: '<S14>/UART//USART Read' */
  dataBytesToRead = getBytesToBeReadFromBuffer
    (main_STM32_H743_HIL_DW.obj_k.UARTHandle, 1U, 0U);
  if (dataBytesToRead > 0U) {
    status = MW_UART_ReceiveUsingBuffer(main_STM32_H743_HIL_DW.obj_k.UARTHandle,
      &main_STM32_H743_HIL_B.uart_rx_data, dataBytesToRead, &sentLength);
  } else {
    status = getReadErrorStatus(main_STM32_H743_HIL_DW.obj_k.UARTHandle);
  }

  if (dataBytesToRead < 1U) {
    status |= 1;
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  CombinatorialLogic: '<S38>/Logic'
   *  MATLABSystem: '<S14>/UART//USART Read'
   *  Memory: '<S38>/Memory'
   *  RelationalOperator: '<S32>/FixPt Relational Operator'
   *  UnitDelay: '<S14>/Unit Delay'
   *  UnitDelay: '<S32>/Delay Input1'
   * *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  main_STM32_H743_HIL_DW.UnitDelay_DSTATE_h = main_STM32_H743_HIL_P.Logic_table
    [((((uint32_T)(status > main_STM32_H743_HIL_DW.DelayInput1_DSTATE) << 1) +
       main_STM32_H743_HIL_DW.UnitDelay_DSTATE_h) << 1) +
    main_STM32_H743_HIL_DW.Memory_PreviousInput_o];

  /* Product: '<S14>/Product' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion4'
   */
  main_STM32_H743_HIL_B.Product = (uint8_T)((uint32_T)
    main_STM32_H743_HIL_B.uart_rx_data *
    main_STM32_H743_HIL_DW.UnitDelay_DSTATE_h);

  /* Update for UnitDelay: '<S32>/Delay Input1' incorporates:
   *  MATLABSystem: '<S14>/UART//USART Read'
   * *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  main_STM32_H743_HIL_DW.DelayInput1_DSTATE = status;

  /* Update for Memory: '<S38>/Memory' */
  main_STM32_H743_HIL_DW.Memory_PreviousInput_o =
    main_STM32_H743_HIL_DW.UnitDelay_DSTATE_h;
  main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC = 4;

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator5' */

  /* ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.PG6_in_Bremse =
    main_STM32_H743_HIL_DW.TmpRTBAtModelInport6_Buffer;

  /* ModelReference: '<Root>/Model' */
  ECU_RCPTID3(&main_STM32_H743_HIL_B.PG6_in_Bremse,
              &main_STM32_H743_HIL_B.Product,
              &main_STM32_H743_HIL_B.v_soll_chart_kmh,
              &main_STM32_H743_HIL_B.debug_fcn_state,
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));

  /* RateTransition generated from: '<Root>/Memory1' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemory1Inport1_Buffer0 =
    main_STM32_H743_HIL_B.debug_fcn_state;

  /* RateTransition generated from: '<Root>/Memory' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemoryInport1_Buffer0 =
    main_STM32_H743_HIL_B.v_soll_chart_kmh;

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_STM32_H743_HIL_M->Timing.clockTick3++;
}

/* Model step function for TID4 */
void main_STM32_H743_HIL_step4(void)   /* Sample time: [0.1s, 0.0s] */
{
  int32_T j;
  int32_T qY;
  real32_T acc1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_STM32_H743_HIL_DW.FunctionCallSubsystem_SubsysRan);

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* MATLABSystem: '<S9>/Encoder1' */
  main_STM32_H743_HIL_B.count_new = getTimerCounterValue
    (main_STM32_H743_HIL_DW.obj_k2.TimerHandle);

  /* MATLABSystem: '<S9>/Encoder1' */
  main_STM32_H743_HIL_B.dir = ouputDirectionOfCounter
    (main_STM32_H743_HIL_DW.obj_k2.TimerHandle);

  /* ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* UnitDelay: '<S9>/Unit Delay' */
  main_STM32_H743_HIL_B.count_old = main_STM32_H743_HIL_DW.UnitDelay_DSTATE;

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   */
  if ((int32_T)main_STM32_H743_HIL_B.count_new == (int32_T)
      main_STM32_H743_HIL_B.count_old) {
    main_STM32_H743_HIL_B.count_diff_e = 0;
  } else if ((int32_T)main_STM32_H743_HIL_B.count_new > (int32_T)
             main_STM32_H743_HIL_B.count_old) {
    if (!main_STM32_H743_HIL_B.dir) {
      if (((int32_T)main_STM32_H743_HIL_B.count_new >= 0) && ((int32_T)
           main_STM32_H743_HIL_B.count_old < (int32_T)
           main_STM32_H743_HIL_B.count_new - MAX_int32_T)) {
        main_STM32_H743_HIL_B.count_diff_e = MAX_int32_T;
      } else if (((int32_T)main_STM32_H743_HIL_B.count_new < 0) && ((int32_T)
                  main_STM32_H743_HIL_B.count_old > (int32_T)
                  main_STM32_H743_HIL_B.count_new - MIN_int32_T)) {
        main_STM32_H743_HIL_B.count_diff_e = MIN_int32_T;
      } else {
        main_STM32_H743_HIL_B.count_diff_e = (int32_T)
          main_STM32_H743_HIL_B.count_new - (int32_T)
          main_STM32_H743_HIL_B.count_old;
      }
    } else {
      if (((int32_T)main_STM32_H743_HIL_B.count_new >= 0) && (rtP_reload_value <
           (int32_T)main_STM32_H743_HIL_B.count_new - MAX_int32_T)) {
        qY = MAX_int32_T;
      } else if (((int32_T)main_STM32_H743_HIL_B.count_new < 0) &&
                 (rtP_reload_value > (int32_T)main_STM32_H743_HIL_B.count_new -
                  MIN_int32_T)) {
        qY = MIN_int32_T;
      } else {
        qY = (int32_T)main_STM32_H743_HIL_B.count_new - rtP_reload_value;
      }

      if ((qY >= 0) && ((int32_T)main_STM32_H743_HIL_B.count_old < qY -
                        MAX_int32_T)) {
        qY = MAX_int32_T;
      } else if ((qY < 0) && ((int32_T)main_STM32_H743_HIL_B.count_old > qY -
                              MIN_int32_T)) {
        qY = MIN_int32_T;
      } else {
        qY -= (int32_T)main_STM32_H743_HIL_B.count_old;
      }

      if (qY < -2147483647) {
        main_STM32_H743_HIL_B.count_diff_e = MIN_int32_T;
      } else {
        main_STM32_H743_HIL_B.count_diff_e = qY - 1;
      }
    }
  } else if (!main_STM32_H743_HIL_B.dir) {
    if (((int32_T)main_STM32_H743_HIL_B.count_new < 0) && (rtP_reload_value <
         MIN_int32_T - (int32_T)main_STM32_H743_HIL_B.count_new)) {
      qY = MIN_int32_T;
    } else if (((int32_T)main_STM32_H743_HIL_B.count_new > 0) &&
               (rtP_reload_value > MAX_int32_T - (int32_T)
                main_STM32_H743_HIL_B.count_new)) {
      qY = MAX_int32_T;
    } else {
      qY = (int32_T)main_STM32_H743_HIL_B.count_new + rtP_reload_value;
    }

    if ((qY >= 0) && ((int32_T)main_STM32_H743_HIL_B.count_old < qY -
                      MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((qY < 0) && ((int32_T)main_STM32_H743_HIL_B.count_old > qY -
                            MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY -= (int32_T)main_STM32_H743_HIL_B.count_old;
    }

    if (qY > 2147483646) {
      main_STM32_H743_HIL_B.count_diff_e = MAX_int32_T;
    } else {
      main_STM32_H743_HIL_B.count_diff_e = qY + 1;
    }
  } else if (((int32_T)main_STM32_H743_HIL_B.count_new >= 0) && ((int32_T)
              main_STM32_H743_HIL_B.count_old < (int32_T)
              main_STM32_H743_HIL_B.count_new - MAX_int32_T)) {
    main_STM32_H743_HIL_B.count_diff_e = MAX_int32_T;
  } else if (((int32_T)main_STM32_H743_HIL_B.count_new < 0) && ((int32_T)
              main_STM32_H743_HIL_B.count_old > (int32_T)
              main_STM32_H743_HIL_B.count_new - MIN_int32_T)) {
    main_STM32_H743_HIL_B.count_diff_e = MIN_int32_T;
  } else {
    main_STM32_H743_HIL_B.count_diff_e = (int32_T)
      main_STM32_H743_HIL_B.count_new - (int32_T)main_STM32_H743_HIL_B.count_old;
  }

  /* End of MATLAB Function: '<S9>/MATLAB Function' */

  /* DiscreteFir: '<S9>/MAF_1_order' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  main_STM32_H743_HIL_B.count_diff_filt1 = (real32_T)
    main_STM32_H743_HIL_B.count_diff_e *
    main_STM32_H743_HIL_P.MAF_1_order_Coefficients[0] +
    main_STM32_H743_HIL_DW.MAF_1_order_states *
    main_STM32_H743_HIL_P.MAF_1_order_Coefficients[1];

  /* ToAsyncQueueBlock generated from: '<S9>/MAF_1_order' */

  /* DiscreteFir: '<S9>/MAF_3_order' */
  acc1 = main_STM32_H743_HIL_B.count_diff_filt1 *
    main_STM32_H743_HIL_P.MAF_3_order_Coefficients[0];
  qY = 1;
  for (j = main_STM32_H743_HIL_DW.MAF_3_order_circBuf; j < 3; j++) {
    acc1 += main_STM32_H743_HIL_DW.MAF_3_order_states[j] *
      main_STM32_H743_HIL_P.MAF_3_order_Coefficients[qY];
    qY++;
  }

  for (j = 0; j < main_STM32_H743_HIL_DW.MAF_3_order_circBuf; j++) {
    acc1 += main_STM32_H743_HIL_DW.MAF_3_order_states[j] *
      main_STM32_H743_HIL_P.MAF_3_order_Coefficients[qY];
    qY++;
  }

  /* DiscreteFir: '<S9>/MAF_3_order' */
  main_STM32_H743_HIL_B.count_diff_filt2 = acc1;

  /* ToAsyncQueueBlock generated from: '<S9>/MAF_3_order' */

  /* ToAsyncQueueBlock generated from: '<S9>/MATLAB Function' */

  /* ToAsyncQueueBlock generated from: '<S9>/Unit Delay' */

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  main_STM32_H743_HIL_DW.UnitDelay_DSTATE = main_STM32_H743_HIL_B.count_new;

  /* Update for DiscreteFir: '<S9>/MAF_1_order' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  /* Update states */
  main_STM32_H743_HIL_DW.MAF_1_order_states = (real32_T)
    main_STM32_H743_HIL_B.count_diff_e;

  /* Update for DiscreteFir: '<S9>/MAF_3_order' */
  /* Update circular buffer index */
  main_STM32_H743_HIL_DW.MAF_3_order_circBuf--;
  if (main_STM32_H743_HIL_DW.MAF_3_order_circBuf < 0) {
    main_STM32_H743_HIL_DW.MAF_3_order_circBuf = 2;
  }

  /* Update circular buffer */
  main_STM32_H743_HIL_DW.MAF_3_order_states[main_STM32_H743_HIL_DW.MAF_3_order_circBuf]
    = main_STM32_H743_HIL_B.count_diff_filt1;

  /* End of Update for DiscreteFir: '<S9>/MAF_3_order' */
  main_STM32_H743_HIL_DW.FunctionCallSubsystem_SubsysRan = 4;

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* ToAsyncQueueBlock generated from: '<Root>/Function-Call Subsystem' */

  /* RateTransition generated from: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_DW.count_diff_filt2_Buffer0 =
    main_STM32_H743_HIL_B.count_diff_filt2;

  /* Update absolute time */
  /* The "clockTick4" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick4" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_STM32_H743_HIL_M->Timing.clockTick4++;
}

/* Model initialize function */
void main_STM32_H743_HIL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(main_STM32_H743_HIL_M, -1);
  main_STM32_H743_HIL_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  main_STM32_H743_HIL_M->Sizes.checksums[0] = (359690520U);
  main_STM32_H743_HIL_M->Sizes.checksums[1] = (1729338627U);
  main_STM32_H743_HIL_M->Sizes.checksums[2] = (988545811U);
  main_STM32_H743_HIL_M->Sizes.checksums[3] = (1857561320U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[27];
    main_STM32_H743_HIL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[10] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[11] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.TriggeredSubsystem1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.TriggeredSubsystem1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.TriggeredSubsystem1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.TriggeredSubsystem1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &main_STM32_H743_HIL_DW.data_exchange_HMI_SubsysRanBC;
    rteiSetModelMappingInfoPtr(main_STM32_H743_HIL_M->extModeInfo,
      &main_STM32_H743_HIL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(main_STM32_H743_HIL_M->extModeInfo,
                        main_STM32_H743_HIL_M->Sizes.checksums);
    rteiSetTPtr(main_STM32_H743_HIL_M->extModeInfo, rtmGetTPtr
                (main_STM32_H743_HIL_M));
  }

  {
    static uint32_T *clockTickPtrs[6];
    static real_T *taskTimePtrs[6];
    static uint32_T *taskCounterPtrs;
    static boolean_T *rateTransitionPtrs[(6 * 6)];
    main_STM32_H743_HIL_TimingBrdg.nTasks = 6;
    clockTickPtrs[0] = &(main_STM32_H743_HIL_M->Timing.clockTick0);
    clockTickPtrs[1] = &(main_STM32_H743_HIL_M->Timing.clockTick1);
    clockTickPtrs[2] = &(main_STM32_H743_HIL_M->Timing.clockTick2);
    clockTickPtrs[3] = &(main_STM32_H743_HIL_M->Timing.clockTick3);
    clockTickPtrs[4] = &(main_STM32_H743_HIL_M->Timing.clockTick4);
    clockTickPtrs[5] = &(main_STM32_H743_HIL_M->Timing.clockTick5);
    main_STM32_H743_HIL_TimingBrdg.clockTick = clockTickPtrs;
    main_STM32_H743_HIL_TimingBrdg.clockTickH = (NULL);
    taskCounterPtrs = &(main_STM32_H743_HIL_M->Timing.TaskCounters.TID[0]);
    main_STM32_H743_HIL_TimingBrdg.taskCounter = taskCounterPtrs;
    rateTransitionPtrs[0*6 + 1] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1);
    rateTransitionPtrs[0*6 + 2] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_2);
    rateTransitionPtrs[0*6 + 3] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3);
    rateTransitionPtrs[1*6 + 2] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_2);
    rateTransitionPtrs[1*6 + 3] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3);
    rateTransitionPtrs[2*6 + 3] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_3);
    rateTransitionPtrs[2*6 + 4] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_4);
    main_STM32_H743_HIL_TimingBrdg.rateTransition = rateTransitionPtrs;
    taskTimePtrs[0] = &(main_STM32_H743_HIL_M->Timing.taskTime0);
    taskTimePtrs[1] = (NULL);
    taskTimePtrs[2] = (NULL);
    taskTimePtrs[3] = (NULL);
    taskTimePtrs[4] = (NULL);
    taskTimePtrs[5] = (NULL);
    main_STM32_H743_HIL_TimingBrdg.taskTime = taskTimePtrs;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  ECU_RCP_initialize(rtmGetErrorStatusPointer(main_STM32_H743_HIL_M),
                     &main_STM32_H743_HIL_TimingBrdg, 0, 1, 2, 3,
                     &(main_STM32_H743_HIL_DW.Model_InstanceData.rtm));

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter2' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Median Filter2' */

  /* SetupRuntimeResources for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* SetupRuntimeResources for function-call system: '<Root>/Triggered Subsystem1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/Gain7' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/Gain' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/Timer Capture1' */

  /* End of SetupRuntimeResources for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Discrete Transfer Fcn3' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Gain9' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Gain2' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Gain' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic4' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer3' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer2' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/MAF_1_order' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/MAF_3_order' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/MATLAB Function' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/Unit Delay' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Function-Call Subsystem' */

  /* SetupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Triggered Subsystem1' */

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  main_STM32_H743_HIL_DW.obj_n.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_n.matlabCodegenIsDeleted = false;
  main_STM32__SystemCore_setup_cs(&main_STM32_H743_HIL_DW.obj_n);

  /* Start for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.v_ist_kmh =
    main_STM32_H743_HIL_P.v_ist_kmh_InitialCondition;

  /* Start for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.nMot_1pmin =
    main_STM32_H743_HIL_P.TmpRTBAtModelInport5_InitialCon;

  /* Start for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.PG4_in_Kupplung =
    main_STM32_H743_HIL_P.TmpRTBAtModelInport7_InitialCon;

  /* Start for MATLABSystem: '<S29>/PWM Output' */
  main_STM32_H743_HIL_DW.obj_m3.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_m3.matlabCodegenIsDeleted = false;
  main_ST_SystemCore_setup_cslt2a(&main_STM32_H743_HIL_DW.obj_m3);

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter2' */

  /* Start for RateTransition generated from: '<Root>/Memory1' */
  main_STM32_H743_HIL_B.TmpRTBAtMemory1Inport1 =
    main_STM32_H743_HIL_P.TmpRTBAtMemory1Inport1_InitialC;

  /* Start for RateTransition generated from: '<Root>/Memory' */
  main_STM32_H743_HIL_B.TmpRTBAtMemoryInport1 =
    main_STM32_H743_HIL_P.TmpRTBAtMemoryInport1_InitialCo;

  /* Start for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.a_ist_mps2 = main_STM32_H743_HIL_P.xpp_InitialCondition;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  main_STM32_H743_HIL_DW.obj_m.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_m.matlabCodegenIsDeleted = false;
  main_STM32_H_SystemCore_setup_c(&main_STM32_H743_HIL_DW.obj_m);

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter1' */

  /* Start for MATLABSystem: '<Root>/Median Filter2' */
  main_STM32_H743_HIL_DW.obj.matlabCodegenIsDeleted = false;
  main_STM32_H743_HIL_DW.obj.isInitialized = 1;
  main_STM32_H743_HIL_DW.obj.NumChannels = 1;
  main_STM32_H743_HIL_DW.obj.pMID.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj.isSetupComplete = true;

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Median Filter2' */

  /* Start for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* Start for function-call system: '<Root>/Triggered Subsystem1' */

  /* Start for MATLABSystem: '<S13>/Timer Capture1' */
  main_STM32_H743_HIL_DW.obj_o.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_o.matlabCodegenIsDeleted = false;
  main_STM32_H_SystemCore_setup_l(&main_STM32_H743_HIL_DW.obj_o);

  /* Start for ToAsyncQueueBlock generated from: '<S13>/Gain7' */

  /* Start for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function1' */

  /* Start for ToAsyncQueueBlock generated from: '<S13>/Gain' */

  /* Start for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function' */

  /* Start for ToAsyncQueueBlock generated from: '<S13>/Timer Capture1' */

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Start for RateTransition generated from: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_B.count_diff_filt =
    main_STM32_H743_HIL_P.count_diff_filt2_InitialConditi;

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Discrete Transfer Fcn3' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Gain9' */

  /* Start for Atomic SubSystem: '<Root>/Fahrpedalsensor' */
  SPIControllerTransfer_Start(&main_STM32_H743_HIL_DW.SPIControllerTransfer3);

  /* Start for ToAsyncQueueBlock generated from: '<S8>/Gain2' */

  /* Start for ToAsyncQueueBlock generated from: '<S8>/Gain' */

  /* Start for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic4' */

  /* Start for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic1' */

  /* Start for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer3' */
  SPIControllerTransfer_Start(&main_STM32_H743_HIL_DW.SPIControllerTransfer2);

  /* Start for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer2' */

  /* End of Start for SubSystem: '<Root>/Fahrpedalsensor' */

  /* Start for S-Function (fcgen): '<Root>/Function-Call Generator5' incorporates:
   *  SubSystem: '<Root>/data_exchange_HMI'
   */
  /* Start for MATLABSystem: '<S14>/UART//USART Write' */
  main_STM32_H743_HIL_DW.obj_a.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_a.matlabCodegenIsDeleted = false;
  main_STM_SystemCore_setup_cslt2(&main_STM32_H743_HIL_DW.obj_a);

  /* Start for MATLABSystem: '<S14>/UART//USART Read' */
  main_STM32_H743_HIL_DW.obj_k.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_k.matlabCodegenIsDeleted = false;
  main_STM3_SystemCore_setup_cslt(&main_STM32_H743_HIL_DW.obj_k);

  /* End of Start for S-Function (fcgen): '<Root>/Function-Call Generator5' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* Start for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Start for MATLABSystem: '<S9>/Encoder1' */
  main_STM32_H743_HIL_DW.obj_k2.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_k2.matlabCodegenIsDeleted = false;
  main_STM32_SystemCore_setup_csl(&main_STM32_H743_HIL_DW.obj_k2);

  /* Start for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* Start for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* Start for ToAsyncQueueBlock generated from: '<S9>/MAF_1_order' */

  /* Start for ToAsyncQueueBlock generated from: '<S9>/MAF_3_order' */

  /* Start for ToAsyncQueueBlock generated from: '<S9>/MATLAB Function' */

  /* Start for ToAsyncQueueBlock generated from: '<S9>/Unit Delay' */

  /* End of Start for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Function-Call Subsystem' */

  /* Start for ToAsyncQueueBlock generated from: '<Root>/Triggered Subsystem1' */

  /* InitializeConditions for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.v_ist_kmh_Buffer0 =
    main_STM32_H743_HIL_P.v_ist_kmh_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.TmpRTBAtModelInport5_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtModelInport5_InitialCon;

  /* InitializeConditions for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.TmpRTBAtModelInport7_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtModelInport7_InitialCon;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  main_STM32_H743_HIL_DW.Memory_PreviousInput =
    main_STM32_H743_HIL_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  main_STM32_H743_HIL_DW.Memory1_PreviousInput =
    main_STM32_H743_HIL_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory2' */
  main_STM32_H743_HIL_DW.Memory2_PreviousInput =
    main_STM32_H743_HIL_P.Memory2_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<Root>/Memory1' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemory1Inport1_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtMemory1Inport1_InitialC;

  /* InitializeConditions for RateTransition generated from: '<Root>/Memory' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemoryInport1_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtMemoryInport1_InitialCo;

  /* InitializeConditions for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.xpp_Buffer0 =
    main_STM32_H743_HIL_P.xpp_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_DW.count_diff_filt2_Buffer0 =
    main_STM32_H743_HIL_P.count_diff_filt2_InitialConditi;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn3' */
  main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[0] =
    main_STM32_H743_HIL_P.DiscreteTransferFcn3_InitialSta;
  main_STM32_H743_HIL_DW.DiscreteTransferFcn3_states[1] =
    main_STM32_H743_HIL_P.DiscreteTransferFcn3_InitialSta;

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator5' incorporates:
   *  SubSystem: '<Root>/data_exchange_HMI'
   */
  /* InitializeConditions for UnitDelay: '<S32>/Delay Input1'
   *
   * Block description for '<S32>/Delay Input1':
   *
   *  Store in Global RAM
   */
  main_STM32_H743_HIL_DW.DelayInput1_DSTATE =
    main_STM32_H743_HIL_P.DetectIncrease_vinit;

  /* InitializeConditions for DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
   *  UnitDelay: '<S14>/Unit Delay'
   */
  main_STM32_H743_HIL_DW.UnitDelay_DSTATE_h =
    main_STM32_H743_HIL_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for Memory: '<S38>/Memory' */
  main_STM32_H743_HIL_DW.Memory_PreviousInput_o =
    main_STM32_H743_HIL_P.SRFlipFlop_initial_condition;

  /* SystemInitialize for MATLAB Function: '<S14>/MATLAB Function' */
  main_ST_MATLABFunction_Init(&main_STM32_H743_HIL_DW.sf_MATLABFunction_d);

  /* SystemInitialize for MATLAB Function: '<S14>/MATLAB Function1' */
  main_S_MATLABFunction1_Init(&main_STM32_H743_HIL_DW.sf_MATLABFunction1);

  /* SystemInitialize for MATLAB Function: '<S14>/MATLAB Function2' */
  main_S_MATLABFunction1_Init(&main_STM32_H743_HIL_DW.sf_MATLABFunction2);

  /* SystemInitialize for MATLAB Function: '<S14>/MATLAB Function3' */
  main_ST_MATLABFunction_Init(&main_STM32_H743_HIL_DW.sf_MATLABFunction3);

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator5' */

  /* SystemInitialize for ModelReference: '<Root>/Model' */
  ECU_RCP_Init(&main_STM32_H743_HIL_B.v_soll_chart_kmh,
               &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
               &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE = rtP_v_0;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  main_STM32_H743_HIL_DW.UnitDelay_DSTATE =
    main_STM32_H743_HIL_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteFir: '<S9>/MAF_1_order' */
  main_STM32_H743_HIL_DW.MAF_1_order_states =
    main_STM32_H743_HIL_P.MAF_1_order_InitialStates;

  /* InitializeConditions for DiscreteFir: '<S9>/MAF_3_order' */
  main_STM32_H743_HIL_DW.MAF_3_order_states[0] =
    main_STM32_H743_HIL_P.MAF_3_order_InitialStates;
  main_STM32_H743_HIL_DW.MAF_3_order_states[1] =
    main_STM32_H743_HIL_P.MAF_3_order_InitialStates;
  main_STM32_H743_HIL_DW.MAF_3_order_states[2] =
    main_STM32_H743_HIL_P.MAF_3_order_InitialStates;

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* System initialize for function-call system: '<Root>/Triggered Subsystem1' */
  main_STM32_H743_HIL_M->Timing.clockTick5 =
    main_STM32_H743_HIL_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m =
    main_STM32_H743_HIL_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for DiscreteFir: '<S13>/MAF_4_order' */
  main_STM32_H743_HIL_DW.MAF_4_order_states[0] =
    main_STM32_H743_HIL_P.MAF_4_order_InitialStates;
  main_STM32_H743_HIL_DW.MAF_4_order_states[1] =
    main_STM32_H743_HIL_P.MAF_4_order_InitialStates;
  main_STM32_H743_HIL_DW.MAF_4_order_states[2] =
    main_STM32_H743_HIL_P.MAF_4_order_InitialStates;
  main_STM32_H743_HIL_DW.MAF_4_order_states[3] =
    main_STM32_H743_HIL_P.MAF_4_order_InitialStates;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* InitializeConditions for MATLABSystem: '<Root>/Median Filter2' */
  if (main_STM32_H743_HIL_DW.obj.pMID.isInitialized == 1) {
    main_S_MedianFilterCG_resetImpl(&main_STM32_H743_HIL_DW.obj.pMID);
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Median Filter2' */
}

/* Model terminate function */
void main_STM32_H743_HIL_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  if (!main_STM32_H743_HIL_DW.obj_n.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_n.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_n.isSetupComplete) {
      ADC_Handle_Deinit(main_STM32_H743_HIL_DW.obj_n.ADCHandle, ADC_NORMAL_MODE,
                        1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */

  /* Terminate for ModelReference: '<Root>/Model' */
  ECU_RCP_Term(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));

  /* Terminate for MATLABSystem: '<S29>/PWM Output' */
  if (!main_STM32_H743_HIL_DW.obj_m3.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_m3.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_m3.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_m3.isSetupComplete) {
      disableCounter(main_STM32_H743_HIL_DW.obj_m3.TimerHandle);
      disableTimerInterrupts(main_STM32_H743_HIL_DW.obj_m3.TimerHandle, 0);
      disableTimerChannel1(main_STM32_H743_HIL_DW.obj_m3.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S29>/PWM Output' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter2' */

  /* Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  if (!main_STM32_H743_HIL_DW.obj_m.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_m.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_m.isSetupComplete) {
      ADC_Handle_Deinit(main_STM32_H743_HIL_DW.obj_m.ADCHandle, ADC_NORMAL_MODE,
                        1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter1' */

  /* Terminate for MATLABSystem: '<Root>/Median Filter2' */
  if (!main_STM32_H743_HIL_DW.obj.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj.isSetupComplete) {
      main_STM32_H743_HIL_DW.obj.NumChannels = -1;
      if (main_STM32_H743_HIL_DW.obj.pMID.isInitialized == 1) {
        main_STM32_H743_HIL_DW.obj.pMID.isInitialized = 2;
      }
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Median Filter2' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Median Filter2' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* Termination for function-call system: '<Root>/Triggered Subsystem1' */

  /* Terminate for MATLABSystem: '<S13>/Timer Capture1' */
  if (!main_STM32_H743_HIL_DW.obj_o.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_o.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_o.isSetupComplete) {
      disableCounter(main_STM32_H743_HIL_DW.obj_o.TimerHandle);
      disableTimerInterrupts(main_STM32_H743_HIL_DW.obj_o.TimerHandle, 2);
      disableTimerChannel1(main_STM32_H743_HIL_DW.obj_o.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Timer Capture1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S13>/Gain7' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S13>/Gain' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S13>/Timer Capture1' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Discrete Transfer Fcn3' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Gain9' */

  /* Terminate for Atomic SubSystem: '<Root>/Fahrpedalsensor' */
  SPIControllerTransfer2_Term(&main_STM32_H743_HIL_DW.SPIControllerTransfer3);

  /* Terminate for ToAsyncQueueBlock generated from: '<S8>/Gain2' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S8>/Gain' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic4' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer3' */
  SPIControllerTransfer2_Term(&main_STM32_H743_HIL_DW.SPIControllerTransfer2);

  /* Terminate for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer2' */

  /* End of Terminate for SubSystem: '<Root>/Fahrpedalsensor' */

  /* Terminate for S-Function (fcgen): '<Root>/Function-Call Generator5' incorporates:
   *  SubSystem: '<Root>/data_exchange_HMI'
   */
  /* Terminate for MATLABSystem: '<S14>/UART//USART Write' */
  if (!main_STM32_H743_HIL_DW.obj_a.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_a.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_a.isSetupComplete) {
      MW_UART_DeInit(main_STM32_H743_HIL_DW.obj_a.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/UART//USART Write' */

  /* Terminate for MATLABSystem: '<S14>/UART//USART Read' */
  if (!main_STM32_H743_HIL_DW.obj_k.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_k.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_k.isSetupComplete) {
      MW_UART_DeInit(main_STM32_H743_HIL_DW.obj_k.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/UART//USART Read' */
  /* End of Terminate for S-Function (fcgen): '<Root>/Function-Call Generator5' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* Terminate for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Terminate for MATLABSystem: '<S9>/Encoder1' */
  if (!main_STM32_H743_HIL_DW.obj_k2.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_k2.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_k2.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_k2.isSetupComplete) {
      disableCounter(main_STM32_H743_HIL_DW.obj_k2.TimerHandle);
      disableTimerInterrupts(main_STM32_H743_HIL_DW.obj_k2.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(main_STM32_H743_HIL_DW.obj_k2.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(main_STM32_H743_HIL_DW.obj_k2.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Encoder1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S9>/MAF_1_order' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S9>/MAF_3_order' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S9>/MATLAB Function' */

  /* Terminate for ToAsyncQueueBlock generated from: '<S9>/Unit Delay' */

  /* End of Terminate for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Function-Call Subsystem' */

  /* Terminate for ToAsyncQueueBlock generated from: '<Root>/Triggered Subsystem1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter2' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Analog to Digital Converter1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Median Filter2' */

  /* CleanupRuntimeResources for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* CleanupRuntimeResources for function-call system: '<Root>/Triggered Subsystem1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/Gain7' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/Gain' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/MATLAB Function' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S13>/Timer Capture1' */

  /* End of CleanupRuntimeResources for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Subsystem' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Demux1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Discrete Transfer Fcn3' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Gain9' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Gain2' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Gain' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic4' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/Shift Arithmetic1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer3' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S8>/SPI Controller Transfer2' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/data_exchange_HMI' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/Encoder1' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/MAF_1_order' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/MAF_3_order' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/MATLAB Function' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<S9>/Unit Delay' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Function-Call Subsystem' */

  /* CleanupRuntimeResources for ToAsyncQueueBlock generated from: '<Root>/Triggered Subsystem1' */
}

void main_STM32_H743_HIL_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(131,&TIM15_IRQHandler,3);
  MW_NVIC_EnableIRQ(131);
}

/* Hardware Interrupt Block: '<S27>/Hardware Interrupt' */
void TIM15_IRQHandler(void)
{
  /* Event: TIM15 CC1 */
  /* Check event TIM15 CC1 occurred */
  if (0 != (
#if defined(MW_TIM15_ENABLED) && defined(MW_TIM15_CAPTURE_VAR)
            (0 != LL_TIM_IsEnabledIT_CC1(TIM15)) && (0 != TIM_IsActiveFlag_CC1
        (&(MW_TIM15_CAPTURE_VAR)))
#else
            (0 != LL_TIM_IsEnabledIT_CC1(TIM15)) && (0 !=
        LL_TIM_IsActiveFlag_CC1(TIM15))
#endif
            )) {
    /* Clear occurred TIM15 CC1 event */
    LL_TIM_ClearFlag_CC1(TIM15);
    if (1 == runModel) {
      taskTimeStart_main_STM32_H743_HIL(8U);

      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(main_STM32_H743_HIL_DW.TriggeredSubsystem1_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Triggered Subsystem1' */
        {
          int32_T cff;
          int32_T j;
          real32_T acc1;
          uint32_T length;
          main_STM32_H743_HIL_M->Timing.clockTick5 =
            main_STM32_H743_HIL_M->Timing.clockTick0;

          /* MATLABSystem: '<S13>/Timer Capture1' */
          getCCR1RegisterValuePollingMode
            (main_STM32_H743_HIL_DW.obj_o.TimerHandle,
             &main_STM32_H743_HIL_B.TimerCapture1, &length);

          /* MATLAB Function: '<S13>/MATLAB Function' incorporates:
           *  DataTypeConversion: '<S13>/Data Type Conversion2'
           *  UnitDelay: '<S13>/Unit Delay'
           */
          if (main_STM32_H743_HIL_B.TimerCapture1 ==
              main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m) {
            main_STM32_H743_HIL_B.count_diff = 0;
          } else if (main_STM32_H743_HIL_B.TimerCapture1 >
                     main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m) {
            main_STM32_H743_HIL_B.count_diff =
              main_STM32_H743_HIL_B.TimerCapture1 -
              main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m;
          } else {
            main_STM32_H743_HIL_B.count_diff =
              (main_STM32_H743_HIL_B.TimerCapture1 -
               main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m) + 60001;
          }

          /* End of MATLAB Function: '<S13>/MATLAB Function' */

          /* DiscreteFir: '<S13>/MAF_4_order' incorporates:
           *  DataTypeConversion: '<S13>/Data Type Conversion'
           */
          acc1 = (real32_T)main_STM32_H743_HIL_B.count_diff *
            main_STM32_H743_HIL_P.MAF_4_order_Coefficients[0];
          cff = 1;
          for (j = main_STM32_H743_HIL_DW.MAF_4_order_circBuf; j < 4; j++) {
            acc1 += main_STM32_H743_HIL_DW.MAF_4_order_states[j] *
              main_STM32_H743_HIL_P.MAF_4_order_Coefficients[cff];
            cff++;
          }

          for (j = 0; j < main_STM32_H743_HIL_DW.MAF_4_order_circBuf; j++) {
            acc1 += main_STM32_H743_HIL_DW.MAF_4_order_states[j] *
              main_STM32_H743_HIL_P.MAF_4_order_Coefficients[cff];
            cff++;
          }

          /* Gain: '<S13>/Gain7' incorporates:
           *  DiscreteFir: '<S13>/MAF_4_order'
           */
          main_STM32_H743_HIL_B.t_trigger_tim3_ch1 =
            main_STM32_H743_HIL_P.Gain7_Gain * acc1;

          /* ToAsyncQueueBlock generated from: '<S13>/Gain7' */

          /* MATLAB Function: '<S13>/MATLAB Function1' */
          if (main_STM32_H743_HIL_B.t_trigger_tim3_ch1 > 0.0075) {
            main_STM32_H743_HIL_B.f = 1.0F /
              main_STM32_H743_HIL_B.t_trigger_tim3_ch1;
          } else {
            main_STM32_H743_HIL_B.f = 0.0F;
          }

          /* End of MATLAB Function: '<S13>/MATLAB Function1' */

          /* ToAsyncQueueBlock generated from: '<S13>/MATLAB Function1' */

          /* Gain: '<S13>/Gain' */
          main_STM32_H743_HIL_B.f_trigger_tim3_ch1_1pmin =
            main_STM32_H743_HIL_P.Gain_Gain_f * main_STM32_H743_HIL_B.f;

          /* ToAsyncQueueBlock generated from: '<S13>/Gain' */

          /* ToAsyncQueueBlock generated from: '<S13>/MATLAB Function' */

          /* ToAsyncQueueBlock generated from: '<S13>/Timer Capture1' */

          /* Update for UnitDelay: '<S13>/Unit Delay' */
          main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m =
            main_STM32_H743_HIL_B.TimerCapture1;

          /* Update for DiscreteFir: '<S13>/MAF_4_order' incorporates:
           *  DataTypeConversion: '<S13>/Data Type Conversion'
           */
          /* Update circular buffer index */
          main_STM32_H743_HIL_DW.MAF_4_order_circBuf--;
          if (main_STM32_H743_HIL_DW.MAF_4_order_circBuf < 0) {
            main_STM32_H743_HIL_DW.MAF_4_order_circBuf = 3;
          }

          /* Update circular buffer */
          main_STM32_H743_HIL_DW.MAF_4_order_states[main_STM32_H743_HIL_DW.MAF_4_order_circBuf]
            = (real32_T)main_STM32_H743_HIL_B.count_diff;

          /* End of Update for DiscreteFir: '<S13>/MAF_4_order' */
          main_STM32_H743_HIL_DW.TriggeredSubsystem1_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

        /* ToAsyncQueueBlock generated from: '<Root>/Triggered Subsystem1' */
      }

      taskTimeEnd_main_STM32_H743_HIL(8U);
      currentTime = (extmodeSimulationTime_T)
        ((main_STM32_H743_HIL_M->Timing.clockTick5) * 0.001);
      extmodeEvent(5,currentTime);
    }
  }

  __ISB();
  __DSB();
}

void main_STM32_H743_HIL_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(131);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
