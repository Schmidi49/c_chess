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
static void genMoveTree(tPolyTree_Node* pRoot, const size_t depth, size_t cur);

static void treeInserter(void* pBase, tMove* move);

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

void Position_GenerateMoveTree(tPolyTree_Node* pRoot, tBoard* pBoard, const size_t depth){
  tPosition* initialPos = Position_New();
  initialPos->board = *pBoard;

  pRoot->pData = initialPos;
  genMoveTree(pRoot, depth, 0);
}

// --------------------
// internal function definitions
// --------------------
static void genMoveTree(tPolyTree_Node* pRoot, const size_t depth, size_t cur) {
  tPolyTree_Node * pCur;
  IF_NULL_RETURN(pRoot)

  if (cur >= depth)
    return;

  tPosition* pCurPos = pRoot->pData;
  Board_GenerateMoves(&pCurPos->board, treeInserter, pRoot);

  //iterate threw leafs
  pCur = pRoot->pFirst;
  while(pCur != NULL){
    genMoveTree(pCur, depth, cur+1);
    pCur = pCur->pNext;
  }
}

static void treeInserter(void* pBase, tMove* move){
  tPolyTree_Node* pRoot = pBase;
  tPosition pos;
  Position_Init(&pos);

  pos.moveToReach = *move;
  pos.pPrevPos = (tPosition*) (pRoot->pData);
  pos.board = ((tPosition*) (pRoot->pData))->board;
  Board_Advance(&pos.board, move);

  PolyTree_CopyBack(pRoot, sizeof(tPosition), &pos);
}