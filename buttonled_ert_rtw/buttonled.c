/*
 * File: buttonled.c
 *
 * Code generated for Simulink model 'buttonled'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Oct 24 12:13:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buttonled.h"
#include "buttonled_private.h"

/* Block states (default storage) */
DW_buttonled_T buttonled_DW;

/* Real-time model */
RT_MODEL_buttonled_T buttonled_M_;
RT_MODEL_buttonled_T *const buttonled_M = &buttonled_M_;

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
void buttonled_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(buttonled_M, 1));
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
  (buttonled_M->Timing.TaskCounters.TID[1])++;
  if ((buttonled_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    buttonled_M->Timing.TaskCounters.TID[1] = 0;
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
void buttonled_step0(void)             /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void buttonled_step1(void)             /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_Compare;
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (buttonled_DW.obj.SampleTime != buttonled_P.DigitalInput_SampleTime) {
    buttonled_DW.obj.SampleTime = buttonled_P.DigitalInput_SampleTime;
  }

  rtb_Compare = readDigitalPin(9);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   *  MATLABSystem: '<Root>/Digital Input'
   */
  rtb_Compare = ((int16_T)rtb_Compare > (int16_T)buttonled_P.Constant_Value_j);

  /* Switch: '<S2>/Switch' incorporates:
   *  Delay: '<S2>/Delay'
   *  Logic: '<S2>/NOT'
   *  RelationalOperator: '<S5>/FixPt Relational Operator'
   *  UnitDelay: '<S5>/Delay Input1'
   *
   * Block description for '<S5>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((int16_T)rtb_Compare > (int16_T)buttonled_DW.DelayInput1_DSTATE) {
    buttonled_DW.Delay_DSTATE = !buttonled_DW.Delay_DSTATE;
  }

  /* End of Switch: '<S2>/Switch' */

  /* If: '<S1>/If' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Delay: '<S2>/Delay'
   */
  if (buttonled_DW.Delay_DSTATE) {
    tmp = buttonled_P.Constant_Value;
  } else {
    tmp = buttonled_P.Constant1_Value;
  }

  /* End of If: '<S1>/If' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(tmp);
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

  /* Update for UnitDelay: '<S5>/Delay Input1'
   *
   * Block description for '<S5>/Delay Input1':
   *
   *  Store in Global RAM
   */
  buttonled_DW.DelayInput1_DSTATE = rtb_Compare;
}

/* Model initialize function */
void buttonled_initialize(void)
{
  /* InitializeConditions for Delay: '<S2>/Delay' */
  buttonled_DW.Delay_DSTATE = buttonled_P.Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Delay Input1'
   *
   * Block description for '<S5>/Delay Input1':
   *
   *  Store in Global RAM
   */
  buttonled_DW.DelayInput1_DSTATE = buttonled_P.DetectRisePositive_vinit;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  buttonled_DW.obj.matlabCodegenIsDeleted = false;
  buttonled_DW.obj.SampleTime = buttonled_P.DigitalInput_SampleTime;
  buttonled_DW.obj.isInitialized = 1L;
  digitalIOSetup(9, 0);
  buttonled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  buttonled_DW.obj_g.matlabCodegenIsDeleted = false;
  buttonled_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(4, 1);
  buttonled_DW.obj_g.isSetupComplete = true;
}

/* Model terminate function */
void buttonled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabCod_l(&buttonled_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&buttonled_DW.obj_g);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
