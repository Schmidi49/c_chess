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

static const uint8_t cMaskNoPiece = 1 << 0;
static const uint8_t cMaskKing = 1 << 1;
static const uint8_t cMaskRook = 1 << 2;
static const uint8_t cMaskBishop = 1 << 3;
static const uint8_t cMaskQueen = 1 << 4;
static const uint8_t cMaskKnight = 1 << 5;
static const uint8_t cMaskPawn = 1 << 6;

typedef struct tPieceMethodes{
  int32_t (*getValue)(tBoard* pBoard, tLocation loc);
  void (*generateMoves)(tBoard* pBoard, tLocation loc, Piece_GenerateCB genCB, void* pBase);
  //for debugging
  uint8_t kindMask;
}tPieceMethodes;

bool Piece_isWhite(tBoard* pBoard, tLocation loc);

bool Piece_SameColor(tBoard* pBoard, tLocation first, tLocation second);

bool Piece_DifferentColor(tBoard* pBoard, tLocation first, tLocation second);

bool Piece_isKind(tBoard* pBoard, tLocation loc, uint8_t kindmask);

tPieceMethodes const* Piece_GetMethodes(tBoard* pBoard, tLocation loc);

#endif //C_CHESS_PIECE_H
