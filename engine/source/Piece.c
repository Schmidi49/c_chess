//
// Created by erik on 23.03.24.
//

#include "Game.h"

// --------------------
// forward declarations
// --------------------


// --------------------
// header function definitions
// --------------------
bool Piece_isWhite(tBoard* pBoard, tLocation loc){
  const char pieceKind = AT(pBoard->squares_kind, loc);
  return pieceKind < 'a';
}

// --------------------
// internal function definitions
// --------------------
