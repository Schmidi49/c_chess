//
// Created by erik on 25.03.24.
//

#ifndef C_CHESS_GAME_H
#define C_CHESS_GAME_H

#define BOARD_COLS 8
#define BOARD_ROWS 8

#define NUM_OF_PIECES 3

#include "DoubleLinkedList.h"

#include <stdint.h>

typedef char tPieceType;
typedef uint8_t tPieceID;

static const tPieceID cNoID = -1;

typedef struct tLocation{
  uint8_t row: 3;
  uint8_t col: 3;
  uint8_t: 2;
}tLocation;

#include "Board.h"
#include "Piece.h"
#include "Move.h"
#include "Evaluation.h"

//forward typedef
typedef struct tBoard tBoard;
typedef struct tPiece tPiece;

typedef struct tGame{
  tBoard currentBoard;
  tDlList_List moveList;
}tGame;

void Game_Init(tGame* pGame);

tPieceMethodes const* Game_GetMethodes(tPieceType kind);

tLocation Game_CoordsToLocation(uint8_t col, uint8_t row);

char* Game_LocationToStr(tLocation loc);

#endif //C_CHESS_GAME_H
