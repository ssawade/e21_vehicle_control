/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[5] = { 0, 0, 0, 0, 0 };

boolean_T need2runFlags[5] = { 0, 0, 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[5];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  main_STM32_H743_HIL_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  main_STM32_H743_HIL_step0();

  /* Get model outputs here */
  __disable_irq();
  isRateRunning[0]--;
  for (i = 1; i < 5; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 5; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;
      __enable_irq();

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        main_STM32_H743_HIL_step1();

        /* Get model outputs here */
        break;

       case 2 :
        main_STM32_H743_HIL_step2();

        /* Get model outputs here */
        break;

       case 3 :
        main_STM32_H743_HIL_step3();

        /* Get model outputs here */
        break;

       case 4 :
        main_STM32_H743_HIL_step4();

        /* Get model outputs here */
        break;

       default :
        break;
      }

      __disable_irq();
      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(int argc, char **argv)
{
  float modelBaseRate = 0.001;
  float systemClock = 480.0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  MW_EnableNVICPeripheral();

#if !defined(MW_FREERTOS) && defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;

  // Peripheral initialization imported from STM32CubeMX project;
  HAL_Init();
  SystemClock_Config();
  PeriphCommonClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_ADC1_Init();
  configureADCChannelPreselectionRegister(ADC1,1 ,0);
  MX_ADC3_Init();
  configureADCChannelPreselectionRegister(ADC3,1 ,0);
  MX_SPI3_Init();
  MX_TIM3_Init();
  MX_TIM13_Init();
  MX_TIM17_Init();
  MX_TIM15_Init();
  MX_USART2_UART_Init();
  rtmSetErrorStatus(main_STM32_H743_HIL_M, 0);
  main_STM32_H743_HIL_configure_interrupts();
  main_STM32_H743_HIL_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = rtmGetErrorStatus(main_STM32_H743_HIL_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(main_STM32_H743_HIL_M) == (NULL));
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  main_STM32_H743_HIL_terminate();

#if !defined(MW_FREERTOS) && !defined(USE_RTX)

  (void) systemClock;

#endif

  ;
  main_STM32_H743_HIL_unconfigure_interrupts();
  MW_DisableNVICPeripheral();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
