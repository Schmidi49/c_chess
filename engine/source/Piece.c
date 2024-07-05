//
// Created by erik on 23.03.24.
//

#include "Game.h"

#include "Rook.h"
#include "King.h"

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

bool Piece_isKind(tBoard* pBoard, tLocation loc, uint8_t kindmask){
  if(kindmask & cMaskNoPiece){
    if(AT(pBoard->squares_kind, loc) == cNoPiece)
      return true;
  }
  if(kindmask & cMaskKing){
    if(AT(pBoard->squares_kind, loc) == cWhiteKing || AT(pBoard->squares_kind, loc) == cBlackKing)
      return true;
  }
  if(kindmask & cMaskRook){
    if(AT(pBoard->squares_kind, loc) == cWhiteRook || AT(pBoard->squares_kind, loc) == cBlackRook)
      return true;
  }
  return false;
}

tPieceMethodes const* Piece_GetMethodes(tBoard* pBoard, tLocation loc){
  if(Piece_isKind(pBoard, loc, cMaskRook))
    return &Rook_MethodeTable;
  else if(Piece_isKind(pBoard, loc, cMaskKing))
    return &King_MethodeTable;
  else
    return NULL;
}

// --------------------
// internal function definitions
// --------------------
