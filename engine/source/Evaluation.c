//
// Created by erik on 29.03.24.
//

#include "Game.h"

// --------------------
// forward declarations
// --------------------

// --------------------
// header function definitions
// --------------------

bool Evaluation_GT(tEvaluation* pFirst, tEvaluation* pSecond){
  if(NO_WIN(pFirst) && NO_WIN(pSecond)){
    return pFirst->eval > pSecond->eval;
  }
  if(!NO_WIN(pFirst) && NO_WIN(pSecond)){
    return pFirst->mateIn >= 0;
  }
  if(NO_WIN(pFirst) && !NO_WIN(pSecond)){
    return pSecond < 0;
  }
  //both positions have mate clocks
  return EVAL_UINT(pFirst) < EVAL_UINT(pSecond); //use properties of 2s complement
}

bool Evaluation_ST(tEvaluation* pFirst, tEvaluation* pSecond){
  return Evaluation_GT(pSecond, pFirst);
}

bool Evaluation_EQ(tEvaluation* pFirst, tEvaluation* pSecond){
  return (pFirst->mateIn == pSecond->mateIn) == (pFirst->eval == pSecond->eval);
}

int Evaluation_Comp(tEvaluation* pFirst, tEvaluation* pSecond){
  if(Evaluation_EQ(pFirst, pSecond))
    return 0;
  if(Evaluation_GT(pFirst, pSecond))
    return 1;
  else
    return -1;
}

// --------------------
// internal function definitions
// --------------------