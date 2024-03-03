/*
 * File: servomoteur.c
 *
 * Code generated for Simulink model 'servomoteur'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 10:01:43 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "servomoteur.h"
#include "servomoteur_private.h"

/* Block states (default storage) */
DW_servomoteur_T servomoteur_DW;

/* Real-time model */
RT_MODEL_servomoteur_T servomoteur_M_;
RT_MODEL_servomoteur_T *const servomoteur_M = &servomoteur_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_inter_T *obj,
  i_codertarget_arduinobase_int_T *iobj_0);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void servomoteur_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(servomoteur_M, 1));
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
  (servomoteur_M->Timing.TaskCounters.TID[1])++;
  if ((servomoteur_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    servomoteur_M->Timing.TaskCounters.TID[1] = 0;
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

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_inter_T *obj,
  i_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
}

/* Model step function for TID0 */
void servomoteur_step0(void)           /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void servomoteur_step1(void)           /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_DigitalInput_0;
  real_T rtb_Switch;
  uint8_T rtb_Switch_0;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (servomoteur_DW.obj.SampleTime != servomoteur_P.DigitalInput_SampleTime) {
    servomoteur_DW.obj.SampleTime = servomoteur_P.DigitalInput_SampleTime;
  }

  rtb_DigitalInput_0 = readDigitalPin(2);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLABSystem: '<Root>/Digital Input'
   */
  if (rtb_DigitalInput_0) {
    rtb_Switch = servomoteur_P.Constant_Value;
  } else {
    rtb_Switch = servomoteur_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<Root>/Standard Servo Write' */
  if (rtb_Switch < 0.0) {
    rtb_Switch_0 = 0U;
  } else if (rtb_Switch > 180.0) {
    rtb_Switch_0 = 180U;
  } else {
    rtb_Switch = rt_roundd_snf(rtb_Switch);
    if (rtb_Switch < 256.0) {
      rtb_Switch_0 = (uint8_T)rtb_Switch;
    } else {
      rtb_Switch_0 = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, rtb_Switch_0);

  /* End of MATLABSystem: '<Root>/Standard Servo Write' */
}

/* Model initialize function */
void servomoteur_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Input' */
  servomoteur_DW.obj.matlabCodegenIsDeleted = false;
  servomoteur_DW.obj.SampleTime = servomoteur_P.DigitalInput_SampleTime;
  servomoteur_DW.obj.isInitialized = 1L;
  digitalIOSetup(2, 0);
  servomoteur_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Standard Servo Write' */
  servomoteur_DW.obj_i.isInitialized = 0L;
  arduino_ServoWrite_set_pinNumbe(&servomoteur_DW.obj_i, &servomoteur_DW.gobj_2);
  servomoteur_DW.obj_i.isInitialized = 1L;
  MW_servoAttach(0, 4);
}

/* Model terminate function */
void servomoteur_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&servomoteur_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
