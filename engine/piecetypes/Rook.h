//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_ROOK_H
#define C_CHESS_ROOK_H

#include "Piece.h"

#include <stdint.h>

int32_t Rook_getValue(struct Piece_s* pSelf);

extern PieceMethodes_t Rook_MethodeTable;

#endif //C_CHESS_ROOK_H
