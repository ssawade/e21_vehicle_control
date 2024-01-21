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
 * C/C++ source code generated on : Mon Jan 15 20:57:32 2024
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

  /* tid 0 shares data with slower tid rates: 1, 3 */
  main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1 =
    (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1] == 0);
  main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3 =
    (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] == 0);

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[1] == 0) {
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_2 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2] == 0);
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* tid 2 shares data with slower tid rate: 3 */
  if (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[2] == 0) {
    main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_3 =
      (main_STM32_H743_HIL_M->Timing.TaskCounters.TID[3] == 0);
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
void main_SPIControllerTransfer2(uint16_T rtu_0, DW_SPIControllerTransfer2_mai_T
  *localDW)
{
  uint16_T rdDataRaw;
  uint8_T status;

  /* MATLABSystem: '<S8>/SPI Controller Transfer2' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0, true);
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_2);
  if (status == 0) {
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0,
      &rdDataRaw, 1, 1U, 0, 1U);
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
 * Output and update for atomic system:
 *    '<S14>/MATLAB Function'
 *    '<S14>/MATLAB Function3'
 */
void main_STM32_H_MATLABFunction(int32_T rtu_u, uint8_T rty_byte_array[4])
{
  int32_T saturatedUnaryMinus;
  uint32_T qY;
  uint32_T qY_tmp;
  uint8_T byte2;
  uint8_T byte3;
  uint8_T num_abs;
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
 * Output and update for atomic system:
 *    '<S14>/MATLAB Function1'
 *    '<S14>/MATLAB Function2'
 */
void main_STM32__MATLABFunction1(int32_T rtu_u, uint8_T rty_byte_array[4])
{
  uint32_T num_abs;
  uint32_T qY;
  uint32_T temp1;
  uint32_T temp2;
  uint8_T byte2;
  uint8_T byte3;
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
  for (main_STM32_H743_HIL_B.i = 0; main_STM32_H743_HIL_B.i < 10;
       main_STM32_H743_HIL_B.i++) {
    /* Start for MATLABSystem: '<Root>/Median Filter2' */
    obj->pBuf[main_STM32_H743_HIL_B.i] = 0.0F;
    obj->pPos[main_STM32_H743_HIL_B.i] = 0.0F;
    obj->pHeap[main_STM32_H743_HIL_B.i] = 0.0F;
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
  for (main_STM32_H743_HIL_B.i = 0; main_STM32_H743_HIL_B.i < 10;
       main_STM32_H743_HIL_B.i++) {
    /* Start for MATLABSystem: '<Root>/Median Filter2' */
    if (fmodf(10.0F - (real32_T)main_STM32_H743_HIL_B.i, 2.0F) == 0.0F) {
      obj->pPos[9 - main_STM32_H743_HIL_B.i] = main_STM32_H743_HIL_B.cnt1;
      main_STM32_H743_HIL_B.cnt1++;
    } else {
      obj->pPos[9 - main_STM32_H743_HIL_B.i] = main_STM32_H743_HIL_B.cnt2;
      main_STM32_H743_HIL_B.cnt2--;
    }

    obj->pHeap[(int32_T)obj->pPos[9 - main_STM32_H743_HIL_B.i] - 1] = 10.0F -
      (real32_T)main_STM32_H743_HIL_B.i;
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
    main_STM32_H743_HIL_B.ind2_k = i + obj->pMidHeap;
    main_STM32_H743_HIL_B.f2 = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1_c
      - 1];
    main_STM32_H743_HIL_B.f3 = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2_k
      - 1];
    if (!(obj->pBuf[(int32_T)main_STM32_H743_HIL_B.f2 - 1] < obj->pBuf[(int32_T)
          main_STM32_H743_HIL_B.f3 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1_c - 1] =
        main_STM32_H743_HIL_B.f3;
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2_k - 1] =
        main_STM32_H743_HIL_B.f2;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1_c - 1] -
        1] = main_STM32_H743_HIL_B.ind1_c;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2_k - 1] -
        1] = main_STM32_H743_HIL_B.ind2_k;
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
    main_STM32_H743_HIL_B.f = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1 - 1];
    main_STM32_H743_HIL_B.f1 = obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2 -
      1];
    if (!(obj->pBuf[(int32_T)main_STM32_H743_HIL_B.f - 1] < obj->pBuf[(int32_T)
          main_STM32_H743_HIL_B.f1 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind1 - 1] =
        main_STM32_H743_HIL_B.f1;
      obj->pHeap[(int32_T)main_STM32_H743_HIL_B.ind2 - 1] =
        main_STM32_H743_HIL_B.f;
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
                       ADC_TRIGGER_AND_READ, &main_STM32_H743_HIL_B.data);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  MATLABSystem: '<S18>/Analog to Digital Converter'
   */
  main_STM32_H743_HIL_B.DataTypeConversion3 = (real32_T)
    main_STM32_H743_HIL_B.data;

  /* ModelReference: '<Root>/Model' incorporates:
   *  Constant: '<Root>/phi3_driver_norm'
   */
  profileStart_m_0d34002402f40824(1U); /* original_line:651 */
  ECU_RCPTID0(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtm),
              &main_STM32_H743_HIL_B.DataTypeConversion3,
              &main_STM32_H743_HIL_P.phi3_driver_norm_Value,
              &main_STM32_H743_HIL_B.u_ref,
              &main_STM32_H743_HIL_B.phi3_M_filt_norm,
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));
  profileEnd_main_STM32_H743_HIL(1U);  /* original_line:657 */

  /* MATLABSystem: '<S24>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  main_STM32_H743_HIL_B.portNameLoc = GPIOA;
  if (main_STM32_H743_HIL_B.u_ref >= main_STM32_H743_HIL_P.Constant_Value_m) {
    main_STM32_H743_HIL_B.c_c = 1024;
  } else {
    main_STM32_H743_HIL_B.c_c = 0;
  }

  LL_GPIO_SetOutputPin(main_STM32_H743_HIL_B.portNameLoc, (uint32_T)
                       main_STM32_H743_HIL_B.c_c);
  LL_GPIO_ResetOutputPin(main_STM32_H743_HIL_B.portNameLoc, ~(uint32_T)
    main_STM32_H743_HIL_B.c_c & 1024U);

  /* End of MATLABSystem: '<S24>/Digital Port Write' */

  /* MATLABSystem: '<S29>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   *  Gain: '<Root>/Gain1'
   */
  setDutyCycleInPercentageChannel1(main_STM32_H743_HIL_DW.obj_m3.TimerHandle,
    main_STM32_H743_HIL_P.Gain1_Gain * fabsf(main_STM32_H743_HIL_B.u_ref));

  /* RateTransition generated from: '<Root>/Memory1' incorporates:
   *  RateTransition generated from: '<Root>/Memory'
   */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3) {
    /* RateTransition generated from: '<Root>/Memory1' */
    main_STM32_H743_HIL_B.TmpRTBAtMemory1Inport1 =
      main_STM32_H743_HIL_DW.TmpRTBAtMemory1Inport1_Buffer0;

    /* RateTransition generated from: '<Root>/Memory' */
    main_STM32_H743_HIL_B.TmpRTBAtMemoryInport1 =
      main_STM32_H743_HIL_DW.TmpRTBAtMemoryInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Memory1' */

  /* RateTransition generated from: '<Root>/Memory2' incorporates:
   *  RateTransition generated from: '<Root>/Subsystem'
   */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Memory2' */
    main_STM32_H743_HIL_B.TmpRTBAtMemory2Inport1 =
      main_STM32_H743_HIL_DW.TmpRTBAtMemory2Inport1_Buffer0;
    main_STM32_H743_HIL_DW.TmpRTBAtSubsystemInport1_Buffer =
      main_STM32_H743_HIL_B.phi3_M_filt_norm;
  }

  /* End of RateTransition generated from: '<Root>/Memory2' */

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

  /* RateTransition generated from: '<Root>/Subsystem' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Subsystem' */
    main_STM32_H743_HIL_B.a_ist_mps2 = main_STM32_H743_HIL_DW.a_ist_mps2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Subsystem' */

  /* MATLABSystem: '<S16>/Analog to Digital Converter' */
  regularReadADCNormal(main_STM32_H743_HIL_DW.obj_m.ADCHandle,
                       ADC_TRIGGER_AND_READ, &main_STM32_H743_HIL_B.data);

  /* MATLABSystem: '<Root>/Median Filter2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<S16>/Analog to Digital Converter'
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
    main_STM32_H743_HIL_B.data;
  main_STM32_H743_HIL_B.p = main_STM32_H743_HIL_DW.obj.pMID.pPos[(int32_T)
    main_STM32_H743_HIL_DW.obj.pMID.pIdx - 1];
  main_STM32_H743_HIL_DW.obj.pMID.pIdx++;
  if (main_STM32_H743_HIL_DW.obj.pMID.pWinLen + 1.0F ==
      main_STM32_H743_HIL_DW.obj.pMID.pIdx) {
    main_STM32_H743_HIL_DW.obj.pMID.pIdx = 1.0F;
  }

  if (main_STM32_H743_HIL_B.p > main_STM32_H743_HIL_DW.obj.pMID.pMidHeap) {
    if (main_STM32_H743_HIL_B.vprev < main_STM32_H743_HIL_B.data) {
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
    if (main_STM32_H743_HIL_B.data < main_STM32_H743_HIL_B.vprev) {
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

  /* End of MATLABSystem: '<Root>/Median Filter2' */

  /* MATLABSystem: '<S22>/Digital Port Write' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  main_STM32_H743_HIL_B.portNameLoc = GPIOC;
  if (main_STM32_H743_HIL_P.Constant_Value_p !=
      main_STM32_H743_HIL_P.Constant_Value) {
    main_STM32_H743_HIL_B.c_c = 64;
  } else {
    main_STM32_H743_HIL_B.c_c = 0;
  }

  LL_GPIO_SetOutputPin(main_STM32_H743_HIL_B.portNameLoc, (uint32_T)
                       main_STM32_H743_HIL_B.c_c);
  LL_GPIO_ResetOutputPin(main_STM32_H743_HIL_B.portNameLoc, ~(uint32_T)
    main_STM32_H743_HIL_B.c_c & 64U);

  /* End of MATLABSystem: '<S22>/Digital Port Write' */

  /* Update for Memory: '<Root>/Memory' */
  main_STM32_H743_HIL_DW.Memory_PreviousInput =
    main_STM32_H743_HIL_B.TmpRTBAtMemoryInport1;

  /* Update for Memory: '<Root>/Memory1' */
  main_STM32_H743_HIL_DW.Memory1_PreviousInput =
    main_STM32_H743_HIL_B.TmpRTBAtMemory1Inport1;

  /* Update for Memory: '<Root>/Memory2' */
  main_STM32_H743_HIL_DW.Memory2_PreviousInput =
    main_STM32_H743_HIL_B.TmpRTBAtMemory2Inport1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_STM32_H743_HIL_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void main_STM32_H743_HIL_step1(void)   /* Sample time: [0.005s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Constant: '<S12>/Constant' incorporates:
   *  Constant: '<Root>/gear'
   *  Selector: '<S12>/Selector'
   */
  main_STM32_H743_HIL_B.xpp = (real32_T)rtP_iG_car[(int32_T)
    main_STM32_H743_HIL_P.gear_Value];

  /* Gain: '<S12>/Gain8' incorporates:
   *  Constant: '<S12>/Constant'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Gain: '<S12>/Gain6'
   *  Gain: '<S12>/Gain7'
   *  Product: '<S12>/Product2'
   */
  main_STM32_H743_HIL_B.n_Mot1min = (real32_T)(1.0 / rtP_r_dyn) *
    main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE * (real32_T)rtP_iD_car *
    main_STM32_H743_HIL_B.xpp * main_STM32_H743_HIL_P.Gain8_Gain;

  /* Signum: '<S12>/Sign' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   */
  if (rtIsNaNF(main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE)) {
    main_STM32_H743_HIL_B.f4 = (rtNaNF);
  } else if (main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE < 0.0F) {
    main_STM32_H743_HIL_B.f4 = -1.0F;
  } else {
    main_STM32_H743_HIL_B.f4 = (real32_T)
      (main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE > 0.0F);
  }

  /* Gain: '<S12>/Gain12' incorporates:
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S12>/Gain4'
   */
  main_STM32_H743_HIL_B.rtb_xpp_tmp = rtP_m_F + rtP_m_Zu;

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
    rtP_eta * main_STM32_H743_HIL_B.xpp * (real32_T)rtP_iD_car * (real32_T)(1.0 /
    rtP_r_stat) - (real32_T)(main_STM32_H743_HIL_B.rtb_xpp_tmp * rtP_g) * sinf
    (atanf(main_STM32_H743_HIL_P.gradient_relative_Value))) - ((real32_T)(0.5 *
    rtP_c_W * rtP_A * rtP_p_L) *
    (main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE *
     main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE) + (real32_T)
    (main_STM32_H743_HIL_B.rtb_xpp_tmp * rtP_f_R * rtP_g) *
    main_STM32_H743_HIL_B.f4)) * (real32_T)(1.0 /
    main_STM32_H743_HIL_B.rtb_xpp_tmp);

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

  /* RateTransition generated from: '<Root>/Model' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<Root>/Model' */
    main_STM32_H743_HIL_B.PG4_in_Kupplung =
      main_STM32_H743_HIL_DW.TmpRTBAtModelInport7_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Model' */

  /* ModelReference: '<Root>/Model' */
  profileStart_m_0d34002402f40824(2U); /* original_line:1014 */
  ECU_RCPTID1(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtm),
              &main_STM32_H743_HIL_B.Gain13, &main_STM32_H743_HIL_B.n_Mot1min,
              &main_STM32_H743_HIL_B.PG4_in_Kupplung,
              &main_STM32_H743_HIL_B.i_calc_ext,
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));
  profileEnd_main_STM32_H743_HIL(2U);  /* original_line:1019 */

  /* RateTransition generated from: '<Root>/Memory2' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemory2Inport1_Buffer0 =
    main_STM32_H743_HIL_B.i_calc_ext;

  /* RateTransition generated from: '<Root>/data_exchange_HMI' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3) {
    main_STM32_H743_HIL_DW.TmpRTBAtdata_exchange_HMIInpo_d =
      main_STM32_H743_HIL_B.n_Mot1min;
  }

  /* End of RateTransition generated from: '<Root>/data_exchange_HMI' */

  /* RateTransition generated from: '<Root>/Subsystem' */
  main_STM32_H743_HIL_DW.a_ist_mps2_Buffer0 = main_STM32_H743_HIL_B.xpp;

  /* RateTransition generated from: '<Root>/data_exchange_HMI' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3) {
    main_STM32_H743_HIL_DW.v_ist_kmh_Buffer = main_STM32_H743_HIL_B.Gain13;
  }

  /* End of RateTransition generated from: '<Root>/data_exchange_HMI' */

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
  GPIO_TypeDef * portNameLoc;
  int32_T i;
  uint32_T pinReadLoc;
  int8_T rtb_DataTypeConversion7[5];
  boolean_T pinReadArrayLoc[5];

  /* MATLABSystem: '<S20>/Digital Port Read' */
  portNameLoc = GPIOG;
  pinReadLoc = LL_GPIO_ReadInputPort(portNameLoc);
  pinReadArrayLoc[0] = ((pinReadLoc & 16U) != 0U);
  pinReadArrayLoc[1] = ((pinReadLoc & 32U) != 0U);
  pinReadArrayLoc[2] = ((pinReadLoc & 64U) != 0U);
  pinReadArrayLoc[3] = ((pinReadLoc & 128U) != 0U);
  pinReadArrayLoc[4] = ((pinReadLoc & 256U) != 0U);

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  MATLABSystem: '<S20>/Digital Port Read'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
   */
  for (i = 0; i < 5; i++) {
    rtb_DataTypeConversion7[i] = (int8_T)(boolean_T)(pinReadArrayLoc[i] ^ 1);
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion7' */

  /* ModelReference: '<Root>/Model' */
  profileStart_m_0d34002402f40824(3U); /* original_line:1081 */
  ECU_RCPTID2();
  profileEnd_main_STM32_H743_HIL(3U);  /* original_line:1081 */

  /* RateTransition generated from: '<Root>/Model' */
  if (main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_3) {
    main_STM32_H743_HIL_DW.TmpRTBAtModelInport6_Buffer = (uint8_T)
      rtb_DataTypeConversion7[2];
  }

  /* End of RateTransition generated from: '<Root>/Model' */

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.TmpRTBAtModelInport7_Buffer0 = (uint8_T)
    rtb_DataTypeConversion7[0];

  /* Outputs for Atomic SubSystem: '<Root>/Fahrpedalsensor' */
  /* S-Function (sfix_bitop): '<S8>/Bitwise Operator' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   */
  main_SPIControllerTransfer2((uint16_T)(main_STM32_H743_HIL_P.Constant_Value_i |
    main_STM32_H743_HIL_P.Constant1_Value),
    &main_STM32_H743_HIL_DW.SPIControllerTransfer2);

  /* S-Function (sfix_bitop): '<S8>/Bitwise Operator1' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   */
  main_SPIControllerTransfer2((uint16_T)(main_STM32_H743_HIL_P.Constant2_Value |
    main_STM32_H743_HIL_P.Constant3_Value),
    &main_STM32_H743_HIL_DW.SPIControllerTransfer3);

  /* End of Outputs for SubSystem: '<Root>/Fahrpedalsensor' */

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
  uint8_T uartReadData;
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

  /* S-Function (fcgen): '<Root>/Function-Call Generator5' incorporates:
   *  SubSystem: '<Root>/data_exchange_HMI'
   */
  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  RateTransition generated from: '<Root>/data_exchange_HMI'
   */
  tmp = floorf(main_STM32_H743_HIL_DW.v_ist_kmh_Buffer);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 4.2949673E+9F);
  }

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   */
  profileStart_m_0d34002402f40824(4U); /* original_line:1166 */
  main_STM32_H_MATLABFunction(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_e);
  profileEnd_main_STM32_H743_HIL(4U);  /* original_line:1167 */

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
  profileStart_m_0d34002402f40824(5U); /* original_line:1182 */
  main_STM32__MATLABFunction1(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_j);
  profileEnd_main_STM32_H743_HIL(5U);  /* original_line:1183 */

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
  profileStart_m_0d34002402f40824(6U); /* original_line:1198 */
  main_STM32__MATLABFunction1(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_n);
  profileEnd_main_STM32_H743_HIL(6U);  /* original_line:1199 */

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
  profileStart_m_0d34002402f40824(7U); /* original_line:1214 */
  main_STM32_H_MATLABFunction(tmp < 0.0F ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, main_STM32_H743_HIL_B.byte_array_a);
  profileEnd_main_STM32_H743_HIL(7U);  /* original_line:1215 */

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
      &uartReadData, dataBytesToRead, &sentLength);
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
   *  MATLABSystem: '<S14>/UART//USART Read'
   * */
  main_STM32_H743_HIL_B.Product = (uint8_T)((uint32_T)uartReadData *
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

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator5' */

  /* RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.PG6_in_Bremse =
    main_STM32_H743_HIL_DW.TmpRTBAtModelInport6_Buffer;

  /* ModelReference: '<Root>/Model' */
  profileStart_m_0d34002402f40824(8U); /* original_line:1406 */
  ECU_RCPTID3(&main_STM32_H743_HIL_B.PG6_in_Bremse,
              &main_STM32_H743_HIL_B.Product,
              &main_STM32_H743_HIL_B.v_soll_chart_kmh,
              &main_STM32_H743_HIL_B.debug_fcn_state,
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
              &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));
  profileEnd_main_STM32_H743_HIL(8U);  /* original_line:1411 */

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
  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* MATLABSystem: '<S9>/Encoder1' */
  getTimerCounterValue(main_STM32_H743_HIL_DW.obj_k2.TimerHandle);
  ouputDirectionOfCounter(main_STM32_H743_HIL_DW.obj_k2.TimerHandle);

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

/* Model initialize function */
void main_STM32_H743_HIL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static uint32_T *clockTickPtrs[6];
    static uint32_T *taskCounterPtrs;
    static boolean_T *rateTransitionPtrs[(6 * 6)];
    main_STM32_H743_HIL_TimingBrdg.nTasks = 6;
    clockTickPtrs[0] = &(main_STM32_H743_HIL_M->Timing.clockTick0);
    clockTickPtrs[1] = &(main_STM32_H743_HIL_M->Timing.clockTick1);
    clockTickPtrs[2] = &(main_STM32_H743_HIL_M->Timing.clockTick2);
    clockTickPtrs[3] = &(main_STM32_H743_HIL_M->Timing.clockTick3);
    clockTickPtrs[4] = (NULL);
    clockTickPtrs[5] = (NULL);
    main_STM32_H743_HIL_TimingBrdg.clockTick = clockTickPtrs;
    main_STM32_H743_HIL_TimingBrdg.clockTickH = (NULL);
    taskCounterPtrs = &(main_STM32_H743_HIL_M->Timing.TaskCounters.TID[0]);
    main_STM32_H743_HIL_TimingBrdg.taskCounter = taskCounterPtrs;
    rateTransitionPtrs[0*6 + 1] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_1);
    rateTransitionPtrs[0*6 + 3] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID0_3);
    rateTransitionPtrs[1*6 + 2] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_2);
    rateTransitionPtrs[1*6 + 3] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID1_3);
    rateTransitionPtrs[2*6 + 3] =
      &(main_STM32_H743_HIL_M->Timing.RateInteraction.TID2_3);
    main_STM32_H743_HIL_TimingBrdg.rateTransition = rateTransitionPtrs;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  ECU_RCP_initialize(rtmGetErrorStatusPointer(main_STM32_H743_HIL_M),
                     &main_STM32_H743_HIL_TimingBrdg, 0, 1, 2, 3,
                     &(main_STM32_H743_HIL_DW.Model_InstanceData.rtm));

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  main_STM32_H743_HIL_DW.obj_n.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_n.matlabCodegenIsDeleted = false;
  main_STM32__SystemCore_setup_cs(&main_STM32_H743_HIL_DW.obj_n);

  /* Start for MATLABSystem: '<S29>/PWM Output' */
  main_STM32_H743_HIL_DW.obj_m3.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_m3.matlabCodegenIsDeleted = false;
  main_ST_SystemCore_setup_cslt2a(&main_STM32_H743_HIL_DW.obj_m3);

  /* Start for RateTransition generated from: '<Root>/Memory1' */
  main_STM32_H743_HIL_B.TmpRTBAtMemory1Inport1 =
    main_STM32_H743_HIL_P.TmpRTBAtMemory1Inport1_InitialC;

  /* Start for RateTransition generated from: '<Root>/Memory2' */
  main_STM32_H743_HIL_B.TmpRTBAtMemory2Inport1 =
    main_STM32_H743_HIL_P.TmpRTBAtMemory2Inport1_InitialC;

  /* Start for RateTransition generated from: '<Root>/Memory' */
  main_STM32_H743_HIL_B.TmpRTBAtMemoryInport1 =
    main_STM32_H743_HIL_P.TmpRTBAtMemoryInport1_InitialCo;

  /* Start for RateTransition generated from: '<Root>/Subsystem' */
  main_STM32_H743_HIL_B.a_ist_mps2 =
    main_STM32_H743_HIL_P.a_ist_mps2_InitialCondition;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  main_STM32_H743_HIL_DW.obj_m.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_m.matlabCodegenIsDeleted = false;
  main_STM32_H_SystemCore_setup_c(&main_STM32_H743_HIL_DW.obj_m);

  /* Start for MATLABSystem: '<Root>/Median Filter2' */
  main_STM32_H743_HIL_DW.obj.matlabCodegenIsDeleted = false;
  main_STM32_H743_HIL_DW.obj.isInitialized = 1;
  main_STM32_H743_HIL_DW.obj.NumChannels = 1;
  main_STM32_H743_HIL_DW.obj.pMID.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj.isSetupComplete = true;

  /* Start for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* Start for function-call system: '<Root>/Triggered Subsystem1' */

  /* Start for MATLABSystem: '<S13>/Timer Capture1' */
  profileStart_m_0d34002402f40824(11U);/* original_line:1529 */
  main_STM32_H743_HIL_DW.obj_o.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_o.matlabCodegenIsDeleted = false;
  main_STM32_H_SystemCore_setup_l(&main_STM32_H743_HIL_DW.obj_o);
  profileEnd_main_STM32_H743_HIL(11U); /* original_line:1531 */

  /* End of Start for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* Start for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_B.PG4_in_Kupplung =
    main_STM32_H743_HIL_P.TmpRTBAtModelInport7_InitialCon;

  /* Start for Atomic SubSystem: '<Root>/Fahrpedalsensor' */
  SPIControllerTransfer_Start(&main_STM32_H743_HIL_DW.SPIControllerTransfer2);
  SPIControllerTransfer_Start(&main_STM32_H743_HIL_DW.SPIControllerTransfer3);

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

  /* Start for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Start for MATLABSystem: '<S9>/Encoder1' */
  main_STM32_H743_HIL_DW.obj_k2.isInitialized = 0;
  main_STM32_H743_HIL_DW.obj_k2.matlabCodegenIsDeleted = false;
  main_STM32_SystemCore_setup_csl(&main_STM32_H743_HIL_DW.obj_k2);

  /* End of Start for S-Function (fcgen): '<Root>/Function-Call Generator' */

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

  /* InitializeConditions for RateTransition generated from: '<Root>/Memory2' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemory2Inport1_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtMemory2Inport1_InitialC;

  /* InitializeConditions for RateTransition generated from: '<Root>/Memory' */
  main_STM32_H743_HIL_DW.TmpRTBAtMemoryInport1_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtMemoryInport1_InitialCo;

  /* InitializeConditions for RateTransition generated from: '<Root>/Subsystem' */
  main_STM32_H743_HIL_DW.a_ist_mps2_Buffer0 =
    main_STM32_H743_HIL_P.a_ist_mps2_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<Root>/Model' */
  main_STM32_H743_HIL_DW.TmpRTBAtModelInport7_Buffer0 =
    main_STM32_H743_HIL_P.TmpRTBAtModelInport7_InitialCon;

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

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator5' */

  /* SystemInitialize for ModelReference: '<Root>/Model' */
  profileStart_m_0d34002402f40824(12U);/* original_line:1627 */
  ECU_RCP_Init(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtb),
               &(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));
  profileEnd_main_STM32_H743_HIL(12U); /* original_line:1628 */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  main_STM32_H743_HIL_DW.DiscreteTimeIntegrator_DSTATE = rtP_v_0;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* System initialize for function-call system: '<Root>/Triggered Subsystem1' */

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  profileStart_m_0d34002402f40824(13U);/* original_line:1643 */
  main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m =
    main_STM32_H743_HIL_P.UnitDelay_InitialCondition_f;
  profileEnd_main_STM32_H743_HIL(13U); /* original_line:1644 */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* InitializeConditions for MATLABSystem: '<Root>/Median Filter2' */
  if (main_STM32_H743_HIL_DW.obj.pMID.isInitialized == 1) {
    main_S_MedianFilterCG_resetImpl(&main_STM32_H743_HIL_DW.obj.pMID);
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Median Filter2' */

  /* Enable for ModelReference: '<Root>/Model' */
  profileStart_m_0d34002402f40824(14U);/* original_line:1656 */
  ECU_RCP_Enable(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));
  profileEnd_main_STM32_H743_HIL(14U); /* original_line:1656 */
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
  profileStart_m_0d34002402f40824(9U); /* original_line:1677 */
  ECU_RCP_Term(&(main_STM32_H743_HIL_DW.Model_InstanceData.rtdw));
  profileEnd_main_STM32_H743_HIL(9U);  /* original_line:1677 */

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

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */

  /* Termination for function-call system: '<Root>/Triggered Subsystem1' */

  /* Terminate for MATLABSystem: '<S13>/Timer Capture1' */
  profileStart_m_0d34002402f40824(10U);/* original_line:1725 */
  if (!main_STM32_H743_HIL_DW.obj_o.matlabCodegenIsDeleted) {
    main_STM32_H743_HIL_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((main_STM32_H743_HIL_DW.obj_o.isInitialized == 1) &&
        main_STM32_H743_HIL_DW.obj_o.isSetupComplete) {
      disableCounter(main_STM32_H743_HIL_DW.obj_o.TimerHandle);
      disableTimerInterrupts(main_STM32_H743_HIL_DW.obj_o.TimerHandle, 2);
      disableTimerChannel1(main_STM32_H743_HIL_DW.obj_o.TimerHandle, ENABLE_CH);
    }
  }

  profileEnd_main_STM32_H743_HIL(10U); /* original_line:1733 */

  /* End of Terminate for MATLABSystem: '<S13>/Timer Capture1' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Fahrpedalsensor' */
  SPIControllerTransfer2_Term(&main_STM32_H743_HIL_DW.SPIControllerTransfer2);
  SPIControllerTransfer2_Term(&main_STM32_H743_HIL_DW.SPIControllerTransfer3);

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
  /* End of Terminate for S-Function (fcgen): '<Root>/Function-Call Generator' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Triggered Subsystem1' */
        {
          uint32_T length;

          /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
           *  MATLABSystem: '<S13>/Timer Capture1'
           * */
          getCCR1RegisterValuePollingMode
            (main_STM32_H743_HIL_DW.obj_o.TimerHandle,
             &main_STM32_H743_HIL_DW.UnitDelay_DSTATE_m, &length);

          /* Update for DiscreteFir: '<S13>/MAF_4_order' */
          /* Update circular buffer index */
          main_STM32_H743_HIL_DW.MAF_4_order_circBuf--;
          if (main_STM32_H743_HIL_DW.MAF_4_order_circBuf < 0) {
            main_STM32_H743_HIL_DW.MAF_4_order_circBuf = 3;
          }

          /* End of Update for DiscreteFir: '<S13>/MAF_4_order' */
          /* Update circular buffer */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S27>/Hardware Interrupt' */
      }

      taskTimeEnd_main_STM32_H743_HIL(8U);
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
