/*
 * File: stateflow4.c
 *
 * Code generated for Simulink model 'stateflow4'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec  5 11:36:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateflow4.h"
#include "stateflow4_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define stateflow4_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define stateflow4_IN_RIGHT            ((uint8_T)1U)
#define stateflow4_IN_Stop             ((uint8_T)1U)
#define stateflow4_IN_WRONG            ((uint8_T)2U)
#define stateflow4_IN_power            ((uint8_T)2U)

/* Block states (default storage) */
DW_stateflow4_T stateflow4_DW;

/* Real-time model */
RT_MODEL_stateflow4_T stateflow4_M_;
RT_MODEL_stateflow4_T *const stateflow4_M = &stateflow4_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabC_h3b(codertarget_arduinobase_blo_h_T *obj);
static void matlabCodegenHandle_matlabCod_h(codertarget_arduinobase_block_T *obj);
static void stateflow4_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void stateflow4_SystemCore_delete(codertarget_arduinobase_inter_T *obj);
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
void stateflow4_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(stateflow4_M, 1));
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
  (stateflow4_M->Timing.TaskCounters.TID[1])++;
  if ((stateflow4_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    stateflow4_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void matlabCodegenHandle_matlabC_h3b(codertarget_arduinobase_blo_h_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCod_h(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void stateflow4_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void stateflow4_SystemCore_delete(codertarget_arduinobase_inter_T *obj)
{
  stateflow4_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    stateflow4_SystemCore_delete(obj);
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
  obj->PinPWM = 9UL;
}

/* Model step function for TID0 */
void stateflow4_step0(void)            /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void stateflow4_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_DigitalInput_0;
  boolean_T rtb_DigitalInput1_0;
  codertarget_arduinobase_inter_T *obj;
  int16_T rtb_out2;
  int16_T rtb_out1;
  int16_T rtb_pwm;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (stateflow4_DW.obj_n.SampleTime != stateflow4_P.DigitalInput_SampleTime) {
    stateflow4_DW.obj_n.SampleTime = stateflow4_P.DigitalInput_SampleTime;
  }

  rtb_DigitalInput_0 = readDigitalPin(8);

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (stateflow4_DW.obj_j.SampleTime != stateflow4_P.DigitalInput1_SampleTime) {
    stateflow4_DW.obj_j.SampleTime = stateflow4_P.DigitalInput1_SampleTime;
  }

  rtb_DigitalInput1_0 = readDigitalPin(5);

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   *  MATLABSystem: '<Root>/Digital Input1'
   */
  if (stateflow4_DW.is_active_c3_stateflow4 == 0U) {
    stateflow4_DW.is_active_c3_stateflow4 = 1U;
    stateflow4_DW.is_c3_stateflow4 = stateflow4_IN_Stop;
    rtb_out1 = 0;
    rtb_out2 = 0;
    rtb_pwm = 0;
  } else if (stateflow4_DW.is_c3_stateflow4 == stateflow4_IN_Stop) {
    if (!rtb_DigitalInput1_0) {
      stateflow4_DW.is_c3_stateflow4 = stateflow4_IN_power;
      stateflow4_DW.is_power = stateflow4_IN_RIGHT;
      rtb_out1 = 1;
      rtb_out2 = 0;
      rtb_pwm = 255;
    } else {
      rtb_out1 = 0;
      rtb_out2 = 0;
      rtb_pwm = 0;
    }
  } else {
    /* case IN_power: */
    if (rtb_DigitalInput1_0) {
      stateflow4_DW.is_power = stateflow4_IN_NO_ACTIVE_CHILD;
      stateflow4_DW.is_c3_stateflow4 = stateflow4_IN_Stop;
      rtb_out1 = 0;
      rtb_out2 = 0;
      rtb_pwm = 0;
    } else if (stateflow4_DW.is_power == stateflow4_IN_RIGHT) {
      if (rtb_DigitalInput_0) {
        stateflow4_DW.is_power = stateflow4_IN_WRONG;
        rtb_out1 = 0;
        rtb_out2 = 1;
        rtb_pwm = 255;
      } else {
        rtb_out1 = 1;
        rtb_out2 = 0;
        rtb_pwm = 255;
      }
    } else {
      /* case IN_WRONG: */
      if (!rtb_DigitalInput_0) {
        stateflow4_DW.is_power = stateflow4_IN_RIGHT;
        rtb_out1 = 1;
        rtb_out2 = 0;
        rtb_pwm = 255;
      } else {
        rtb_out1 = 0;
        rtb_out2 = 1;
        rtb_pwm = 255;
      }
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(2, (uint8_T)rtb_out1);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(3, (uint8_T)rtb_out2);

  /* MATLABSystem: '<Root>/PWM' */
  obj = &stateflow4_DW.obj;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(stateflow4_DW.obj.PinPWM);
  MW_PWM_SetDutyCycle(stateflow4_DW.obj.MW_PWM_HANDLE, (real_T)rtb_pwm);
}

/* Model initialize function */
void stateflow4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    stateflow4_DW.obj_n.matlabCodegenIsDeleted = false;
    stateflow4_DW.obj_n.SampleTime = stateflow4_P.DigitalInput_SampleTime;
    stateflow4_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(8, 0);
    stateflow4_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input1' */
    stateflow4_DW.obj_j.matlabCodegenIsDeleted = false;
    stateflow4_DW.obj_j.SampleTime = stateflow4_P.DigitalInput1_SampleTime;
    stateflow4_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(5, 0);
    stateflow4_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    stateflow4_DW.obj_h.matlabCodegenIsDeleted = false;
    stateflow4_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(2, 1);
    stateflow4_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    stateflow4_DW.obj_hy.matlabCodegenIsDeleted = false;
    stateflow4_DW.obj_hy.isInitialized = 1L;
    digitalIOSetup(3, 1);
    stateflow4_DW.obj_hy.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    stateflow4_DW.obj.matlabCodegenIsDeleted = true;
    stateflow4_DW.obj.isInitialized = 0L;
    stateflow4_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&stateflow4_DW.obj, &stateflow4_DW.gobj_2);
    obj = &stateflow4_DW.obj;
    stateflow4_DW.obj.isSetupComplete = false;
    stateflow4_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(stateflow4_DW.obj.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(stateflow4_DW.obj.PinPWM);
    MW_PWM_Start(stateflow4_DW.obj.MW_PWM_HANDLE);
    stateflow4_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void stateflow4_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  matlabCodegenHandle_matlabC_h3b(&stateflow4_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  matlabCodegenHandle_matlabC_h3b(&stateflow4_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCod_h(&stateflow4_DW.obj_h);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCod_h(&stateflow4_DW.obj_hy);

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  matlabCodegenHandle_matlabCodeg(&stateflow4_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
