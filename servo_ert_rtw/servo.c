/*
 * File: servo.c
 *
 * Code generated for Simulink model 'servo'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 08:34:22 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "servo.h"
#include "servo_private.h"

/* Block states (default storage) */
DW_servo_T servo_DW;

/* Real-time model */
RT_MODEL_servo_T servo_M_;
RT_MODEL_servo_T *const servo_M = &servo_M_;

/* Forward declaration for local functions */
static void arduino_ServoWrite_set_pinNumbe(codertarget_arduinobase_inter_T *obj,
  i_codertarget_arduinobase_int_T *iobj_0);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void servo_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(servo_M, 1));
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
  (servo_M->Timing.TaskCounters.TID[1])++;
  if ((servo_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    servo_M->Timing.TaskCounters.TID[1] = 0;
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
void servo_step0(void)                 /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void servo_step1(void)                 /* Sample time: [1.0s, 0.0s] */
{
  uint8_T tmp;
  real_T tmp_0;

  /* MATLABSystem: '<Root>/Standard Servo Write' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S2>/Output'
   */
  if (servo_P.RepeatingSequenceStair_OutValue[servo_DW.Output_DSTATE] < 0.0) {
    tmp = 0U;
  } else if (servo_P.RepeatingSequenceStair_OutValue[servo_DW.Output_DSTATE] >
             180.0) {
    tmp = 180U;
  } else {
    tmp_0 = rt_roundd_snf
      (servo_P.RepeatingSequenceStair_OutValue[servo_DW.Output_DSTATE]);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint8_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, tmp);

  /* End of MATLABSystem: '<Root>/Standard Servo Write' */

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  servo_DW.Output_DSTATE = (uint8_T)((uint16_T)servo_DW.Output_DSTATE +
    servo_P.FixPtConstant_Value);

  /* Switch: '<S4>/FixPt Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  UnitDelay: '<S2>/Output'
   */
  if (servo_DW.Output_DSTATE > servo_P.LimitedCounter_uplimit) {
    servo_DW.Output_DSTATE = servo_P.Constant_Value;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void servo_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  servo_DW.Output_DSTATE = servo_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Standard Servo Write' */
  servo_DW.obj.isInitialized = 0L;
  arduino_ServoWrite_set_pinNumbe(&servo_DW.obj, &servo_DW.gobj_2);
  servo_DW.obj.isInitialized = 1L;
  MW_servoAttach(0, 4);
}

/* Model terminate function */
void servo_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
