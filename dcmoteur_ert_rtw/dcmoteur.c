/*
 * File: dcmoteur.c
 *
 * Code generated for Simulink model 'dcmoteur'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 11:30:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dcmoteur.h"
#include "dcmoteur_private.h"

/* Block states (default storage) */
DW_dcmoteur_T dcmoteur_DW;

/* Real-time model */
RT_MODEL_dcmoteur_T dcmoteur_M_;
RT_MODEL_dcmoteur_T *const dcmoteur_M = &dcmoteur_M_;

/* Forward declaration for local functions */
static void dcmoteur_SystemCore_release_o(codertarget_arduinobase_inter_T *obj);
static void dcmoteur_SystemCore_delete_o(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCod_o(codertarget_arduinobase_inter_T *obj);
static void dcmoteur_SystemCore_release(codertarget_arduinobase_int_o_T *obj);
static void dcmoteur_SystemCore_delete(codertarget_arduinobase_int_o_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_o_T *obj);
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_int_o_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void dcmoteur_SystemCore_release_o(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void dcmoteur_SystemCore_delete_o(codertarget_arduinobase_inter_T *obj)
{
  dcmoteur_SystemCore_release_o(obj);
}

static void matlabCodegenHandle_matlabCod_o(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    dcmoteur_SystemCore_delete_o(obj);
  }
}

static void dcmoteur_SystemCore_release(codertarget_arduinobase_int_o_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void dcmoteur_SystemCore_delete(codertarget_arduinobase_int_o_T *obj)
{
  dcmoteur_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_o_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    dcmoteur_SystemCore_delete(obj);
  }
}

static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_int_o_T *obj,
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

/* Model step function */
void dcmoteur_step(void)
{
  uint16_T rtb_AnalogInput_0;
  codertarget_arduinobase_inter_T *obj;
  codertarget_arduinobase_int_o_T *obj_0;
  real_T rtb_AnalogInput_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (dcmoteur_DW.obj_g.SampleTime != dcmoteur_P.AnalogInput_SampleTime) {
    dcmoteur_DW.obj_g.SampleTime = dcmoteur_P.AnalogInput_SampleTime;
  }

  obj = &dcmoteur_DW.obj_g;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (dcmoteur_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput_0,
     3);

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   */
  obj_0 = &dcmoteur_DW.obj;
  obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(dcmoteur_DW.obj.PinPWM);
  if (rtb_AnalogInput_0 < 255.0) {
    rtb_AnalogInput_1 = rtb_AnalogInput_0;
  } else {
    rtb_AnalogInput_1 = 255.0;
  }

  MW_PWM_SetDutyCycle(dcmoteur_DW.obj.MW_PWM_HANDLE, rtb_AnalogInput_1);

  /* End of MATLABSystem: '<Root>/PWM' */
}

/* Model initialize function */
void dcmoteur_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_inter_T *obj;
    codertarget_arduinobase_int_o_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    dcmoteur_DW.obj_g.matlabCodegenIsDeleted = true;
    dcmoteur_DW.obj_g.isInitialized = 0L;
    dcmoteur_DW.obj_g.SampleTime = -1.0;
    dcmoteur_DW.obj_g.matlabCodegenIsDeleted = false;
    dcmoteur_DW.obj_g.SampleTime = dcmoteur_P.AnalogInput_SampleTime;
    obj = &dcmoteur_DW.obj_g;
    dcmoteur_DW.obj_g.isSetupComplete = false;
    dcmoteur_DW.obj_g.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    dcmoteur_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    dcmoteur_DW.obj.matlabCodegenIsDeleted = true;
    dcmoteur_DW.obj.isInitialized = 0L;
    dcmoteur_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&dcmoteur_DW.obj, &dcmoteur_DW.gobj_2);
    obj_0 = &dcmoteur_DW.obj;
    dcmoteur_DW.obj.isSetupComplete = false;
    dcmoteur_DW.obj.isInitialized = 1L;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(dcmoteur_DW.obj.PinPWM, 0.0, 0.0);
    obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(dcmoteur_DW.obj.PinPWM);
    MW_PWM_Start(dcmoteur_DW.obj.MW_PWM_HANDLE);
    dcmoteur_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void dcmoteur_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCod_o(&dcmoteur_DW.obj_g);

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  matlabCodegenHandle_matlabCodeg(&dcmoteur_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
