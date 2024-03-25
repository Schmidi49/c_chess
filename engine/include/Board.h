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
  tGame* pGame;
  bool whiteToMove;
}tBoard;

#endif //C_CHESS_BOARD_H
