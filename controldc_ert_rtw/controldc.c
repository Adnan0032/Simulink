/*
 * File: controldc.c
 *
 * Code generated for Simulink model 'controldc'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 12:20:47 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controldc.h"
#include "controldc_private.h"
#include "controldc_dt.h"

/* Block states (default storage) */
DW_controldc_T controldc_DW;

/* Real-time model */
RT_MODEL_controldc_T controldc_M_;
RT_MODEL_controldc_T *const controldc_M = &controldc_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
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

/* Model step function */
void controldc_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (controldc_P.ManualSwitch_CurrentSetting == 1) {
    tmp = controldc_P.Constant_Value;
  } else {
    tmp = controldc_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

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

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  if (controldc_P.ManualSwitch1_CurrentSetting == 1) {
    tmp = controldc_P.Constant2_Value;
  } else {
    tmp = controldc_P.Constant3_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* MATLABSystem: '<Root>/Digital Output1' */
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

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)controldc_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(controldc_M)!=-1) &&
        !((rtmGetTFinal(controldc_M)-controldc_M->Timing.taskTime0) >
          controldc_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(controldc_M, "Simulation finished");
    }

    if (rtmGetStopRequested(controldc_M)) {
      rtmSetErrorStatus(controldc_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  controldc_M->Timing.taskTime0 =
    ((time_T)(++controldc_M->Timing.clockTick0)) * controldc_M->Timing.stepSize0;
}

/* Model initialize function */
void controldc_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(controldc_M, -1);
  controldc_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  controldc_M->Sizes.checksums[0] = (61583817U);
  controldc_M->Sizes.checksums[1] = (2640421625U);
  controldc_M->Sizes.checksums[2] = (3092901737U);
  controldc_M->Sizes.checksums[3] = (2699683124U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    controldc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controldc_M->extModeInfo,
      &controldc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controldc_M->extModeInfo, controldc_M->Sizes.checksums);
    rteiSetTPtr(controldc_M->extModeInfo, rtmGetTPtr(controldc_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    controldc_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  controldc_DW.obj.matlabCodegenIsDeleted = false;
  controldc_DW.obj.isInitialized = 1L;
  digitalIOSetup(4, 1);
  controldc_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  controldc_DW.obj_h.matlabCodegenIsDeleted = false;
  controldc_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(8, 1);
  controldc_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void controldc_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&controldc_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCodeg(&controldc_DW.obj_h);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
