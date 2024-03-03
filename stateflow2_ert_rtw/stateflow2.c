/*
 * File: stateflow2.c
 *
 * Code generated for Simulink model 'stateflow2'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov 21 09:36:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateflow2.h"
#include "stateflow2_private.h"
#include "stateflow2_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define stateflow2_IN_BLEU             (1UL)
#define stateflow2_IN_ROUGE            (2UL)
#define stateflow2_IN_VERT             (3UL)

/* Block states (default storage) */
DW_stateflow2_T stateflow2_DW;

/* Real-time model */
RT_MODEL_stateflow2_T stateflow2_M_;
RT_MODEL_stateflow2_T *const stateflow2_M = &stateflow2_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void stateflow2_step(void)
{
  int16_T B;
  int16_T R;
  int16_T V;

  /* Chart: '<Root>/Chart' */
  if (stateflow2_DW.temporalCounter_i1 < 1023U) {
    stateflow2_DW.temporalCounter_i1++;
  }

  if (stateflow2_DW.is_active_c3_stateflow2 == 0U) {
    stateflow2_DW.is_active_c3_stateflow2 = 1U;
    stateflow2_DW.is_c3_stateflow2 = stateflow2_IN_ROUGE;
    stateflow2_DW.temporalCounter_i1 = 0U;
    R = 1;
    B = 0;
    V = 0;
  } else {
    switch (stateflow2_DW.is_c3_stateflow2) {
     case stateflow2_IN_BLEU:
      if (stateflow2_DW.temporalCounter_i1 >= 1000U) {
        stateflow2_DW.is_c3_stateflow2 = stateflow2_IN_VERT;
        stateflow2_DW.temporalCounter_i1 = 0U;
        R = 0;
        B = 0;
        V = 1;
      } else {
        R = 0;
        B = 1;
        V = 0;
      }
      break;

     case stateflow2_IN_ROUGE:
      if (stateflow2_DW.temporalCounter_i1 >= 1000U) {
        stateflow2_DW.is_c3_stateflow2 = stateflow2_IN_BLEU;
        stateflow2_DW.temporalCounter_i1 = 0U;
        R = 0;
        B = 1;
        V = 0;
      } else {
        R = 1;
        B = 0;
        V = 0;
      }
      break;

     default:
      /* case IN_VERT: */
      if (stateflow2_DW.temporalCounter_i1 >= 300U) {
        stateflow2_DW.is_c3_stateflow2 = stateflow2_IN_ROUGE;
        stateflow2_DW.temporalCounter_i1 = 0U;
        R = 1;
        B = 0;
        V = 0;
      } else {
        R = 0;
        B = 0;
        V = 1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(7, (uint8_T)V);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(9, (uint8_T)R);

  /* MATLABSystem: '<Root>/Digital Output2' */
  writeDigitalPin(4, (uint8_T)B);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)stateflow2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(stateflow2_M)!=-1) &&
        !((rtmGetTFinal(stateflow2_M)-stateflow2_M->Timing.taskTime0) >
          stateflow2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(stateflow2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(stateflow2_M)) {
      rtmSetErrorStatus(stateflow2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  stateflow2_M->Timing.taskTime0 =
    ((time_T)(++stateflow2_M->Timing.clockTick0)) *
    stateflow2_M->Timing.stepSize0;
}

/* Model initialize function */
void stateflow2_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(stateflow2_M, 10.0);
  stateflow2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  stateflow2_M->Sizes.checksums[0] = (3357532804U);
  stateflow2_M->Sizes.checksums[1] = (2785444492U);
  stateflow2_M->Sizes.checksums[2] = (1873990834U);
  stateflow2_M->Sizes.checksums[3] = (2261845329U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    stateflow2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(stateflow2_M->extModeInfo,
      &stateflow2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(stateflow2_M->extModeInfo, stateflow2_M->Sizes.checksums);
    rteiSetTPtr(stateflow2_M->extModeInfo, rtmGetTPtr(stateflow2_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    stateflow2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  stateflow2_DW.obj.matlabCodegenIsDeleted = false;
  stateflow2_DW.obj.isInitialized = 1L;
  digitalIOSetup(7, 1);
  stateflow2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  stateflow2_DW.obj_h.matlabCodegenIsDeleted = false;
  stateflow2_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(9, 1);
  stateflow2_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  stateflow2_DW.obj_hy.matlabCodegenIsDeleted = false;
  stateflow2_DW.obj_hy.isInitialized = 1L;
  digitalIOSetup(4, 1);
  stateflow2_DW.obj_hy.isSetupComplete = true;
}

/* Model terminate function */
void stateflow2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&stateflow2_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  matlabCodegenHandle_matlabCodeg(&stateflow2_DW.obj_h);

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  matlabCodegenHandle_matlabCodeg(&stateflow2_DW.obj_hy);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
