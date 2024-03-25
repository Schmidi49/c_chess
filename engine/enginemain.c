/******************************************************************************
 * @file main.c
 * @author Erik Schmidthaler
 * @brief testing main for the engine library
 *
 * (C) Erik Schmidthaler (25.11.2023)
 */

#include "include/Game.h"
#include "DoubleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void visitor(void* null, tMove* move){
  char* begin = Game_LocationToStr(move->begin);
  char* end = Game_LocationToStr(move->end);

  printf("Got move from %s to %s\n", begin, end);

  free(begin);
  free(end);
}

int main(){
  tGame game;
  tDlList_List list;
  Game_Init(&game);
  DlList_Init(&list);

  tLocation loc = Game_CoordsToLocation(5,2);
  int i = *(uint8_t *)(&(loc));
  char *p = *(game.currentBoard.squares_kind) + i;
  char c = (*(p));
  tPieceMethodes const* m = Game_GetMethodes(AT(game.currentBoard.squares_kind, loc));
  m->generateMoves(&game.currentBoard, loc, visitor, NULL);

  return 0;
}
