//
// Created by erik on 25.03.24.
//

#ifndef C_CHESS_GAME_H
#define C_CHESS_GAME_H

#define BOARD_COLS 8
#define BOARD_ROWS 8

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
#include "Position.h"

//forward typedef
typedef struct tBoard tBoard;
typedef struct tPiece tPiece;
typedef struct tMove tMove;

typedef struct tGame{
  tBoard currentBoard;

  //initial Position
  tDlList_List moveList;
}tGame;

void Game_Init(tGame* pGame);

tPieceMethodes const* Game_GetMethodes(tPieceType kind);

#endif //C_CHESS_GAME_H
