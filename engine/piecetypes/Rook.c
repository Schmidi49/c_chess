//
// Created by erik on 23.03.24.
//

#include "Rook.h"

const tPieceMethodes Rook_MethodeTable = {
  .getValue = Rook_getValue,
};

// --------------------
// forward declarations
// --------------------


// --------------------
// header function definitions
// --------------------
int32_t Rook_getValue(tBoard* pBoard, tLocation loc){
  return Piece_isWhite(pBoard, loc) ? 500 : -500;
}

// --------------------
// internal function definitions
// --------------------
