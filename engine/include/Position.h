/******************************************************************************
 * @file Position.h
 * @author Erik Schmidthaler
 * @brief 
 *
 * (C) Erik Schmidthaler (29.03.24)
 */

#ifndef C_CHESS_POSITION_H
#define C_CHESS_POSITION_H

#include "Game.h"
#include "PolynaryTree.h"

typedef enum eResult{
  NoWin = 0,
  KingCaptureable = 1,
  WhiteMate = 2,
  BlackMate = 3,
  Stalemate = 4,
  DrawBy50Moves = 5,
  DrawByThreefold = 6,
  DrawByMaterial = 7
} eResult;

typedef struct tPosition{
  tBoard board;
  tEvaluation eval;
  eResult result;

  struct tPosition* pPrevPos;
  struct tPosition* pBestContinuation;
  tMove moveToBest;
  tMove moveToReach;

} tPosition;

tPosition* Position_New(void);
void Position_Init(tPosition* pPos);

void Position_GenerateMoveTree(tPolyTree_Node* pRoot, tBoard* pBoard, const size_t depth);

#endif //C_CHESS_POSITION_H
