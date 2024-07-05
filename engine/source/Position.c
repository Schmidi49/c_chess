/******************************************************************************
 * @file Position.c
 * @author Erik Schmidthaler
 * @brief 
 *
 * (C) Erik Schmidthaler (29.03.24)
 */

#include "Game.h"
#include "Macros.h"

#include <string.h>
#include <stdlib.h>

// --------------------
// forward declarations
// --------------------

// --------------------
// header function definitions
// --------------------
tPosition* Position_New(void){
  tPosition* pos;
  ALLOC(pos, sizeof(tPosition))

  Position_Init(pos);
  return pos;
}

void Position_Init(tPosition* pPos){
  memset(pPos, 0, sizeof(tPosition));

  pPos->pBestContinuation = NULL;
  pPos->pPrevPos = NULL;
}

// --------------------
// internal function definitions
// --------------------