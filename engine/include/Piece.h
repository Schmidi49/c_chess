//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_PIECE_H
#define C_CHESS_PIECE_H

#include "Game.h"

#include <stdbool.h>
#include <stdint.h>

//forward typedef
typedef struct tBoard tBoard;
typedef struct tMove tMove;

typedef void (*Piece_GenerateCB)(void* pBase, tMove* pGeneratedMove);

static const tPieceType cNoPiece   = ' ';
static const tPieceType cWhiteKing = 'K';
static const tPieceType cWhiteRook = 'R';
static const tPieceType cBlackKing = 'k';
static const tPieceType cBlackRook = 'r';

typedef struct tPieceMethodes{
  int32_t (*getValue)(tBoard* pBoard, tLocation loc);
  void (*generateMoves)(tBoard* pBoard, tLocation loc, Piece_GenerateCB genCB, void* pBase);
}tPieceMethodes;

bool Piece_isWhite(tBoard* pBoard, tLocation loc);

bool Piece_SameColor(tBoard* pBoard, tLocation first, tLocation second);

bool Piece_DifferentColor(tBoard* pBoard, tLocation first, tLocation second);

#endif //C_CHESS_PIECE_H
