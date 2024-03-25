//
// Created by erik on 25.03.24.
//

#ifndef C_CHESS_GAME_H
#define C_CHESS_GAME_H

#define BOARD_COLS 8
#define BOARD_ROWS 8

#define NUM_OF_PIECES 3

#include <stdint.h>

typedef int8_t tPieceID;
typedef int8_t tLocation;

#include "DoubleLinkedList.h"
#include "Board.h"
#include "Piece.h"

//forward typedef
typedef struct tBoard tBoard;
typedef struct tPiece tPiece;

typedef struct tGame{
  tBoard currentBoard;
  tDlList_List moveList;
  tPiece globalPieces[NUM_OF_PIECES];
}tGame;

void Game_Init(tGame* pGame);

#endif //C_CHESS_GAME_H
