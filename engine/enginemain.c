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
#include "BoardViz.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void treeVisitor(void* pData, size_t depth){
  tPosition* pos = pData;

  for(int i = 0; i < depth; i++){
    printf("    ");
  }

  if(pos->moveToReach.type == no_move){
    printf("<init>\n");
    return;
  }

  char* begin = Board_LocationToStr(pos->moveToReach.begin);
  char* end = Board_LocationToStr(pos->moveToReach.end);

  printf("%c %s - %s\n", pos->moveToReach.movingPiece,begin, end);

  free(begin);
  free(end);
}

#include "Macros.h"

int main(){
  tGame game;
  Game_Init(&game);
  BoardViz_PrintBoard(&game.currentBoard, stdout);

  tPolyTree_Node* pTree = PolyTree_New(NULL);

  printf("\nInserting into tree...\n");
  Position_GenerateMoveTree(pTree, &game.currentBoard, 3);

  printf("\nVisiting tree:\n");
  PolyTree_VisitPreOrder(pTree, treeVisitor);

  return 0;
}
