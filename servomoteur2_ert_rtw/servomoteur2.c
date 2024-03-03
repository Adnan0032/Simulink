/*
 * File: servomoteur2.c
 *
 * Code generated for Simulink model 'servomoteur2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 11:24:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "servomoteur2.h"
#include "servomoteur2_private.h"

/* Block states (default storage) */
DW_servomoteur2_T servomoteur2_DW;

/* Real-time model */
RT_MODEL_servomoteur2_T servomoteur2_M_;
RT_MODEL_servomoteur2_T *const servomoteur2_M = &servomoteur2_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCod_o(codertarget_arduinobase_block_T *obj);
static void servomoteur2_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void servomoteur2_SystemCore_delete(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj);
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void servomoteur2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(servomoteur2_M, 1));
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
  (servomoteur2_M->Timing.TaskCounters.TID[1])++;
  if ((servomoteur2_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    servomoteur2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void matlabCodegenHandle_matlabCod_o(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void servomoteur2_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void servomoteur2_SystemCore_delete(codertarget_arduinobase_inter_T *obj)
{
  servomoteur2_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    servomoteur2_SystemCore_delete(obj);
  }
}

static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0)
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
  obj->PinPWM = 5UL;
}

/* Model step function for TID0 */
void servomoteur2_step0(void)          /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void servomoteur2_step1(void)          /* Sample time: [0.1s, 0.0s] */
{
  codertarget_arduinobase_inter_T *obj;
  boolean_T rtb_Compare;
  real_T y;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (servomoteur2_DW.obj_l.SampleTime != servomoteur2_P.DigitalInput_SampleTime)
  {
    servomoteur2_DW.obj_l.SampleTime = servomoteur2_P.DigitalInput_SampleTime;
  }

  rtb_Compare = readDigitalPin(4);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  MATLABSystem: '<Root>/Digital Input'
   */
  rtb_Compare = ((int16_T)rtb_Compare > (int16_T)servomoteur2_P.Constant_Value_m);

  /* Switch: '<Root>/Switch' incorporates:
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((int16_T)rtb_Compare > (int16_T)servomoteur2_DW.DelayInput1_DSTATE) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Delay: '<Root>/Delay'
     */
    if (servomoteur2_DW.Delay_DSTATE > servomoteur2_P.Switch1_Threshold) {
      servomoteur2_DW.Delay_DSTATE = servomoteur2_P.Constant_Value;
    } else {
      servomoteur2_DW.Delay_DSTATE = servomoteur2_P.Constant1_Value;
    }

    /* End of Switch: '<Root>/Switch1' */
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Delay: '<Root>/Delay'
   */
  obj = &servomoteur2_DW.obj;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(servomoteur2_DW.obj.PinPWM);
  if (servomoteur2_DW.Delay_DSTATE < 255.0) {
    y = servomoteur2_DW.Delay_DSTATE;
  } else {
    y = 255.0;
  }

  if (!(y > 0.0)) {
    y = 0.0;
  }

  MW_PWM_SetDutyCycle(servomoteur2_DW.obj.MW_PWM_HANDLE, y);

  /* End of MATLABSystem: '<Root>/PWM' */

  /* Update for UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  servomoteur2_DW.DelayInput1_DSTATE = rtb_Compare;
}

/* Model initialize function */
void servomoteur2_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    servomoteur2_DW.Delay_DSTATE = servomoteur2_P.Delay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S1>/Delay Input1'
     *
     * Block description for '<S1>/Delay Input1':
     *
     *  Store in Global RAM
     */
    servomoteur2_DW.DelayInput1_DSTATE = servomoteur2_P.DetectRisePositive_vinit;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    servomoteur2_DW.obj_l.matlabCodegenIsDeleted = false;
    servomoteur2_DW.obj_l.SampleTime = servomoteur2_P.DigitalInput_SampleTime;
    servomoteur2_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(4, 0);
    servomoteur2_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    servomoteur2_DW.obj.matlabCodegenIsDeleted = true;
    servomoteur2_DW.obj.isInitialized = 0L;
    servomoteur2_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&servomoteur2_DW.obj,
      &servomoteur2_DW.gobj_2);
    obj = &servomoteur2_DW.obj;
    servomoteur2_DW.obj.isSetupComplete = false;
    servomoteur2_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(servomoteur2_DW.obj.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(servomoteur2_DW.obj.PinPWM);
    MW_PWM_Start(servomoteur2_DW.obj.MW_PWM_HANDLE);
    servomoteur2_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void servomoteur2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabCod_o(&servomoteur2_DW.obj_l);

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  matlabCodegenHandle_matlabCodeg(&servomoteur2_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
