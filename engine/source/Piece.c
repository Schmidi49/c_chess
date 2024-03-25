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

bool Piece_SameColor(tBoard* pBoard, tLocation first, tLocation second){
  const char pieceKind1 = AT(pBoard->squares_kind, first);
  const char pieceKind2 = AT(pBoard->squares_kind, second);
  return !((pieceKind1 < 'a') ^ (pieceKind2 < 'a'));
}

bool Piece_DifferentColor(tBoard* pBoard, tLocation first, tLocation second){
  const char pieceKind1 = AT(pBoard->squares_kind, first);
  const char pieceKind2 = AT(pBoard->squares_kind, second);
  return (pieceKind1 < 'a') ^ (pieceKind2 < 'a');
}

// --------------------
// internal function definitions
// --------------------
