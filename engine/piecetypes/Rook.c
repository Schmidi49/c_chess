//
// Created by erik on 23.03.24.
//

#include "Rook.h"

PieceMethodes_t Rook_MethodeTable = {
  .getValue = Rook_getValue,
};

// --------------------
// forward declarations
// --------------------


// --------------------
// header function definitions
// --------------------
int32_t Rook_getValue(struct Piece_s* pSelf){
  return pSelf->isWhite ? 500 : -500;
}

// --------------------
// internal function definitions
// --------------------
