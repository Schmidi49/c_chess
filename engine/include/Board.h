//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_BOARD_H
#define C_CHESS_BOARD_H

#include "Piece.h"
#include "DoubleLinkedList.h"

typedef struct Board_s{
  struct Piece_s* squares[BOARD_COLS][BOARD_ROWS];
  DlList_List_t activePieceList;
} Board_t;

void Board_Init(Board_t* pBoard);

#endif //C_CHESS_BOARD_H
