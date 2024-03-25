//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_PIECE_H
#define C_CHESS_PIECE_H

#include "Game.h"

#include <stdbool.h>
#include <stdint.h>

const char cNoPiece   = ' ';
const char cWhiteKing = 'K';
const char cWhiteRook = 'R';
const char cBlackKing = 'k';
const char cBlackRook = 'r';

//forward typedef
typedef struct tBoard tBoard;

typedef struct tPieceMethodes{
  int32_t (*getValue)(tBoard* pBoard, tLocation loc);
}tPieceMethodes;

typedef struct tPiece{
  char kind;
  tPieceMethodes const* pMethodes;
}tPiece;

bool Piece_isWhite(tBoard* pBoard, tLocation loc);

#endif //C_CHESS_PIECE_H
