/*
 * File: stateflowLED.c
 *
 * Code generated for Simulink model 'stateflowLED'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov 21 09:10:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateflowLED.h"
#include "stateflowLED_private.h"
#include "stateflowLED_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define stateflowLED_IN_state01        (1UL)
#define stateflowLED_IN_state02        (2UL)

/* Block states (default storage) */
DW_stateflowLED_T stateflowLED_DW;

/* Real-time model */
RT_MODEL_stateflowLED_T stateflowLED_M_;
RT_MODEL_stateflowLED_T *const stateflowLED_M = &stateflowLED_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void stateflowLED_step(void)
{
  int16_T LED;

  /* Chart: '<Root>/Chart' */
  if (stateflowLED_DW.temporalCounter_i1 < 255U) {
    stateflowLED_DW.temporalCounter_i1++;
  }

  if (stateflowLED_DW.is_active_c3_stateflowLED == 0U) {
    stateflowLED_DW.is_active_c3_stateflowLED = 1U;
    stateflowLED_DW.is_c3_stateflowLED = stateflowLED_IN_state01;
    stateflowLED_DW.temporalCounter_i1 = 0U;
    LED = 0;
  } else if (stateflowLED_DW.is_c3_stateflowLED == stateflowLED_IN_state01) {
    if (stateflowLED_DW.temporalCounter_i1 >= 200U) {
      stateflowLED_DW.is_c3_stateflowLED = stateflowLED_IN_state02;
      stateflowLED_DW.temporalCounter_i1 = 0U;
      LED = 1;
    } else {
      LED = 0;
    }
  } else {
    /* case IN_state02: */
    if (stateflowLED_DW.temporalCounter_i1 >= 200U) {
      stateflowLED_DW.is_c3_stateflowLED = stateflowLED_IN_state01;
      stateflowLED_DW.temporalCounter_i1 = 0U;
      LED = 0;
    } else {
      LED = 1;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(4, (uint8_T)LED);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)stateflowLED_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(stateflowLED_M)!=-1) &&
        !((rtmGetTFinal(stateflowLED_M)-stateflowLED_M->Timing.taskTime0) >
          stateflowLED_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(stateflowLED_M, "Simulation finished");
    }

    if (rtmGetStopRequested(stateflowLED_M)) {
      rtmSetErrorStatus(stateflowLED_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  stateflowLED_M->Timing.taskTime0 =
    ((time_T)(++stateflowLED_M->Timing.clockTick0)) *
    stateflowLED_M->Timing.stepSize0;
}

/* Model initialize function */
void stateflowLED_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(stateflowLED_M, 10.0);
  stateflowLED_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  stateflowLED_M->Sizes.checksums[0] = (3177353278U);
  stateflowLED_M->Sizes.checksums[1] = (1523017889U);
  stateflowLED_M->Sizes.checksums[2] = (1060752211U);
  stateflowLED_M->Sizes.checksums[3] = (2277485068U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    stateflowLED_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(stateflowLED_M->extModeInfo,
      &stateflowLED_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(stateflowLED_M->extModeInfo,
                        stateflowLED_M->Sizes.checksums);
    rteiSetTPtr(stateflowLED_M->extModeInfo, rtmGetTPtr(stateflowLED_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    stateflowLED_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  stateflowLED_DW.obj.matlabCodegenIsDeleted = false;
  stateflowLED_DW.obj.isInitialized = 1L;
  digitalIOSetup(4, 1);
  stateflowLED_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void stateflowLED_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&stateflowLED_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
