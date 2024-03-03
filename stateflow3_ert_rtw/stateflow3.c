/*
 * File: stateflow3.c
 *
 * Code generated for Simulink model 'stateflow3'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec  5 09:29:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateflow3.h"
#include "stateflow3_private.h"
#include "stateflow3_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define stateflow3_IN_RIGHT            (1UL)
#define stateflow3_IN_WRONG            (2UL)

/* Block signals (default storage) */
B_stateflow3_T stateflow3_B;

/* Block states (default storage) */
DW_stateflow3_T stateflow3_DW;

/* Real-time model */
RT_MODEL_stateflow3_T stateflow3_M_;
RT_MODEL_stateflow3_T *const stateflow3_M = &stateflow3_M_;

/* Forward declaration for local functions */
static void stateflow3_SystemCore_release_b(codertarget_arduinobase_inter_T *obj);
static void stateflo_SystemCore_delete_bpzl(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlab_bpzl(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCod_b(codertarget_arduinobase_block_T *obj);
static void stateflow3_SystemCore_release(codertarget_arduinobase_int_b_T *obj);
static void stateflow3_SystemCore_delete(codertarget_arduinobase_int_b_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj);
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_int_b_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void stateflow3_SystemCore_release_b(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
    MW_AnalogIn_Close(obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
  }
}

static void stateflo_SystemCore_delete_bpzl(codertarget_arduinobase_inter_T *obj)
{
  stateflow3_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlab_bpzl(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    stateflo_SystemCore_delete_bpzl(obj);
  }
}

static void matlabCodegenHandle_matlabCod_b(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void stateflow3_SystemCore_release(codertarget_arduinobase_int_b_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void stateflow3_SystemCore_delete(codertarget_arduinobase_int_b_T *obj)
{
  stateflow3_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    stateflow3_SystemCore_delete(obj);
  }
}

static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_int_b_T *obj,
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
  obj->PinPWM = 8UL;
}

/* Model step function */
void stateflow3_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  codertarget_arduinobase_int_b_T *obj_0;
  int16_T buzzer;
  int16_T out2;
  int16_T out1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (stateflow3_DW.obj_j.SampleTime != stateflow3_P.AnalogInput_SampleTime) {
    stateflow3_DW.obj_j.SampleTime = stateflow3_P.AnalogInput_SampleTime;
  }

  obj = &stateflow3_DW.obj_j;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (stateflow3_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &stateflow3_B.AnalogInput, 3);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* Chart: '<Root>/Chart' */
  if (stateflow3_DW.is_active_c3_stateflow3 == 0U) {
    stateflow3_DW.is_active_c3_stateflow3 = 1U;
    stateflow3_DW.is_c3_stateflow3 = stateflow3_IN_RIGHT;
    out1 = 1;
    out2 = 0;
    buzzer = 1;
  } else if (stateflow3_DW.is_c3_stateflow3 == stateflow3_IN_RIGHT) {
    if (stateflow3_B.AnalogInput == 1U) {
      stateflow3_DW.is_c3_stateflow3 = stateflow3_IN_WRONG;
      out1 = 0;
      out2 = 1;
      buzzer = 0;
    } else {
      out1 = 1;
      out2 = 0;
      buzzer = 1;
    }
  } else {
    /* case IN_WRONG: */
    if (stateflow3_B.AnalogInput == 0U) {
      stateflow3_DW.is_c3_stateflow3 = stateflow3_IN_RIGHT;
      out1 = 1;
      out2 = 0;
      buzzer = 1;
    } else {
      out1 = 0;
      out2 = 1;
      buzzer = 0;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(2, (uint8_T)out1);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(3, (uint8_T)out2);

  /* MATLABSystem: '<Root>/Digital Output2' */
  writeDigitalPin(9, (uint8_T)buzzer);

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &stateflow3_DW.obj;
  obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(stateflow3_DW.obj.PinPWM);
  MW_PWM_SetDutyCycle(stateflow3_DW.obj.MW_PWM_HANDLE, 255.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.4s, 0.0s] */
    rtExtModeUpload(0, (real_T)stateflow3_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.4s, 0.0s] */
    if ((rtmGetTFinal(stateflow3_M)!=-1) &&
        !((rtmGetTFinal(stateflow3_M)-stateflow3_M->Timing.taskTime0) >
          stateflow3_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(stateflow3_M, "Simulation finished");
    }

    if (rtmGetStopRequested(stateflow3_M)) {
      rtmSetErrorStatus(stateflow3_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  stateflow3_M->Timing.taskTime0 =
    ((time_T)(++stateflow3_M->Timing.clockTick0)) *
    stateflow3_M->Timing.stepSize0;
}

/* Model initialize function */
void stateflow3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(stateflow3_M, 20.0);
  stateflow3_M->Timing.stepSize0 = 0.4;

  /* External mode info */
  stateflow3_M->Sizes.checksums[0] = (3993092445U);
  stateflow3_M->Sizes.checksums[1] = (1905869076U);
  stateflow3_M->Sizes.checksums[2] = (524604283U);
  stateflow3_M->Sizes.checksums[3] = (18246830U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    stateflow3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(stateflow3_M->extModeInfo,
      &stateflow3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(stateflow3_M->extModeInfo, stateflow3_M->Sizes.checksums);
    rteiSetTPtr(stateflow3_M->extModeInfo, rtmGetTPtr(stateflow3_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    stateflow3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_inter_T *obj;
    codertarget_arduinobase_int_b_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    stateflow3_DW.obj_j.matlabCodegenIsDeleted = true;
    stateflow3_DW.obj_j.isInitialized = 0L;
    stateflow3_DW.obj_j.SampleTime = -1.0;
    stateflow3_DW.obj_j.matlabCodegenIsDeleted = false;
    stateflow3_DW.obj_j.SampleTime = stateflow3_P.AnalogInput_SampleTime;
    obj = &stateflow3_DW.obj_j;
    stateflow3_DW.obj_j.isSetupComplete = false;
    stateflow3_DW.obj_j.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    stateflow3_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    stateflow3_DW.obj_b.matlabCodegenIsDeleted = false;
    stateflow3_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(2, 1);
    stateflow3_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    stateflow3_DW.obj_l.matlabCodegenIsDeleted = false;
    stateflow3_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(3, 1);
    stateflow3_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    stateflow3_DW.obj_i.matlabCodegenIsDeleted = false;
    stateflow3_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(9, 1);
    stateflow3_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    stateflow3_DW.obj.matlabCodegenIsDeleted = true;
    stateflow3_DW.obj.isInitialized = 0L;
    stateflow3_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&stateflow3_DW.obj, &stateflow3_DW.gobj_2);
    obj_0 = &stateflow3_DW.obj;
    stateflow3_DW.obj.isSetupComplete = false;
    stateflow3_DW.obj.isInitialized = 1L;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(stateflow3_DW.obj.PinPWM, 0.0, 0.0);
    obj_0->MW_PWM_HANDLE = MW_PWM_GetHandle(stateflow3_DW.obj.PinPWM);
    MW_PWM_Start(stateflow3_DW.obj.MW_PWM_HANDLE);
    stateflow3_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void stateflow3_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlab_bpzl(&stateflow3_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCod_b(&stateflow3_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCod_b(&stateflow3_DW.obj_l);

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  matlabCodegenHandle_matlabCod_b(&stateflow3_DW.obj_i);

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  matlabCodegenHandle_matlabCodeg(&stateflow3_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
