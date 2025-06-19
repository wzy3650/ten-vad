#ifndef __BIQUAD_ST_H__
#define __BIQUAD_ST_H__

#include <stdio.h>
#include "biquad.h"

typedef struct Biquad_St_ {
  void* dynamMemPtr;          // memory pointer holding the dynamic memory
  size_t dynamMemSize;        // size of the buffer *dynamMemPtr

  // Static Configuration
  Biquad_StaticCfg stCfg;

  // ---------------------------------------------------------------
  // Internal Static Config Registers, which are generated from stCfg
  int maxNSample;
  int nsect;
  float BCoeff[AGORA_UAP_BIQUAD_MAX_SECTION][3];
  float ACoeff[AGORA_UAP_BIQUAD_MAX_SECTION][3];
  float GCoeff[AGORA_UAP_BIQUAD_MAX_SECTION];  // gain for each section

  // Variables
  float* inputTempBuf;  // [maxNSample]
  float sectW[AGORA_UAP_BIQUAD_MAX_SECTION][2];
  // each section's register
  float* sectOutputBuf[AGORA_UAP_BIQUAD_MAX_SECTION];  //[AGORA_UAP_BIQUAD_MAX_SECTION][maxNSample]
                                                       // each section's output buffer

} Biquad_St;

#endif  // __BIQUAD_ST_H__
