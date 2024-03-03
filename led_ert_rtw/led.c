/*
 * File: led.c
 *
 * Code generated for Simulink model 'led'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Oct 24 11:44:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led.h"
#include "led_private.h"

/* Block states (default storage) */
DW_led_T led_DW;

/* Real-time model */
RT_MODEL_led_T led_M_;
RT_MODEL_led_T *const led_M = &led_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCod_l(codertarget_arduinobase_blo_l_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void led_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(led_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (led_M->Timing.TaskCounters.TID[1])++;
  if ((led_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    led_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void matlabCodegenHandle_matlabCod_l(codertarget_arduinobase_blo_l_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function for TID0 */
void led_step0(void)                   /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void led_step1(void)                   /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_DigitalInput_0;
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (led_DW.obj.SampleTime != led_P.DigitalInput_SampleTime) {
    led_DW.obj.SampleTime = led_P.DigitalInput_SampleTime;
  }

  rtb_DigitalInput_0 = readDigitalPin(8);

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Delay: '<S1>/Delay'
   *  MATLABSystem: '<Root>/Digital Input'
   */
  if (rtb_DigitalInput_0) {
    led_DW.Delay_DSTATE = led_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Delay: '<S1>/Delay'
   */
  tmp = rt_roundd_snf(led_DW.Delay_DSTATE);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */
}

/* Model initialize function */
void led_initialize(void)
{
  /* InitializeConditions for Delay: '<S1>/Delay' */
  led_DW.Delay_DSTATE = led_P.Delay_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  led_DW.obj.matlabCodegenIsDeleted = false;
  led_DW.obj.SampleTime = led_P.DigitalInput_SampleTime;
  led_DW.obj.isInitialized = 1L;
  digitalIOSetup(8, 0);
  led_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  led_DW.obj_l.matlabCodegenIsDeleted = false;
  led_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(4, 1);
  led_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void led_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabCod_l(&led_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&led_DW.obj_l);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
