/******************************************************************************
 * @file main.c
 * @author Erik Schmidthaler
 * @brief testing main for the engine library
 *
 * (C) Erik Schmidthaler (25.11.2023)
 */

#include "include/Game.h"
#include "DoubleLinkedList.h"
#include "PolynaryTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void treeVisitor(void* pData, size_t depth){
  tPosition* pos = pData;

  for(int i = 0; i < depth; i++){
    printf("    ");
  }

  if(pos->moveToReach.type == no_move){
    printf("nomove\n");
    return;
  }

  char* begin = Board_LocationToStr(pos->moveToReach.begin);
  char* end = Board_LocationToStr(pos->moveToReach.end);

  printf("%c %s - %s\n", pos->moveToReach.movingPiece,begin, end);

  free(begin);
  free(end);
}

void treeInserter(void* pData, tMove* move){
  tPolyTree_Node* pTree = pData;
  tPosition pos;
  Position_Init(&pos);

  pos.moveToReach = *move;
  pos.pPrevPos = (tPosition*)(pTree->pData);
  pos.board = ((tPosition*)(pTree->pData))->board;
  Board_Advance(&pos.board, move);

  PolyTree_CopyBack(pTree, sizeof(tPosition), &pos);

  char* begin = Board_LocationToStr(move->begin);
  char* end = Board_LocationToStr(move->end);

  printf("Inserted move of %c from %s to %s into the tree\n", move->movingPiece, begin, end);

  free(begin);
  free(end);
}

#include "Macros.h"

int main(){
  tGame game;
  Game_Init(&game);

  tPosition* initialPos = Position_New();
  initialPos->board = game.currentBoard;
  tPolyTree_Node* pTree = PolyTree_New(initialPos);

  printf("Inserting into tree:\n");
  Board_GenerateMoves(&game.currentBoard, treeInserter, pTree);

  printf("\nVisiting tree\n");
  PolyTree_VisitPreOrder(pTree, treeVisitor);

  return 0;
}
