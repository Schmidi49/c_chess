//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_ROOK_H
#define C_CHESS_ROOK_H

#include "Game.h"

#include <stdint.h>

int32_t Rook_getValue(tBoard* pBoard, tLocation loc);

extern const tPieceMethodes Rook_MethodeTable;

#endif //C_CHESS_ROOK_H
