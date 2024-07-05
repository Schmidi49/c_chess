//
// Created by erik on 29.03.24.
//

#ifndef C_CHESS_KING_H
#define C_CHESS_KING_H

#define KING_MOVES 8

#include "Game.h"

#include <stdint.h>

int32_t King_GetValue(tBoard* pBoard, tLocation loc);

void King_GenerateMoves(tBoard* pBoard, tLocation loc, Piece_GenerateCB genCB, void* pBase);

typedef struct tKing_MoveInc{
  int8_t colinc;
  int8_t rowinc;
}tKing_MoveInc;

extern const tPieceMethodes King_MethodeTable;
extern const tKing_MoveInc King_MovePattern[KING_MOVES];

#endif //C_CHESS_KING_H
