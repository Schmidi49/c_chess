//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_BOARD_H
#define C_CHESS_BOARD_H

#include "Game.h"

#include <stdbool.h>
#include <stdint.h>

#define AT(squares, location) (*(*(squares) + *(uint8_t*)(&(location))))

//forward typedef
typedef struct tGame tGame;

typedef struct tBoard{
  char squares_kind[BOARD_COLS][BOARD_ROWS];
  tPieceID squares_id[BOARD_COLS][BOARD_ROWS];
  tLocation whiteKing;
  tLocation blackKing;
  bool whiteToMove;
}tBoard;

bool Board_SquareUnderAttack(tBoard* pBoard, tLocation loc);

bool Board_SquareDefended(tBoard* pBoard, tLocation loc);

bool Board_IsCheck(tBoard* pBoard);

bool Board_KingCaptureable(tBoard* pBoard);

tLocation Board_CoordsToLocation(uint8_t col, uint8_t row);

char* Board_LocationToStr(tLocation loc);

#endif //C_CHESS_BOARD_H
