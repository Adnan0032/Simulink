/*
 * File: blinkled.c
 *
 * Code generated for Simulink model 'blinkled'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 08:02:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "blinkled.h"
#include "blinkled_private.h"

/* Block states (default storage) */
DW_blinkled_T blinkled_DW;

/* Real-time model */
RT_MODEL_blinkled_T blinkled_M_;
RT_MODEL_blinkled_T *const blinkled_M = &blinkled_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void blinkled_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(blinkled_M, 1));
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
  (blinkled_M->Timing.TaskCounters.TID[1])++;
  if ((blinkled_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    blinkled_M->Timing.TaskCounters.TID[1] = 0;
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

/* Model step function for TID0 */
void blinkled_step0(void)              /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void blinkled_step1(void)              /* Sample time: [1.0s, 0.0s] */
{
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S2>/Output'
   */
  tmp = rt_roundd_snf
    (blinkled_P.RepeatingSequenceStair_OutValue[blinkled_DW.Output_DSTATE]);
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

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  blinkled_DW.Output_DSTATE = (uint8_T)((uint16_T)blinkled_DW.Output_DSTATE +
    blinkled_P.FixPtConstant_Value);

  /* Switch: '<S4>/FixPt Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  UnitDelay: '<S2>/Output'
   */
  if (blinkled_DW.Output_DSTATE > blinkled_P.LimitedCounter_uplimit) {
    blinkled_DW.Output_DSTATE = blinkled_P.Constant_Value;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void blinkled_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  blinkled_DW.Output_DSTATE = blinkled_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  blinkled_DW.obj.matlabCodegenIsDeleted = false;
  blinkled_DW.obj.isInitialized = 1L;
  digitalIOSetup(4, 1);
  blinkled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void blinkled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCodeg(&blinkled_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
