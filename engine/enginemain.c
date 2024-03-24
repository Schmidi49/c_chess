/******************************************************************************
 * @file main.c
 * @author Erik Schmidthaler
 * @brief testing main for the engine library
 *
 * (C) Erik Schmidthaler (25.11.2023)
 */

#include "Board.h"

#include <stdio.h>
#include <string.h>

int main(){
  printf("chess is cool\n");
  Board_t board;
  Board_Init(&board);

  Piece_NewRook(&board, 1, true);
  Piece_NewRook(&board, 11, true);
  if(board.squares[1][3] != NULL){
    printf("placed a rook succesfully\n");
  }
  if(board.squares[4][1] == NULL){
    printf("square is empty\n");
  }

  return 0;
}
