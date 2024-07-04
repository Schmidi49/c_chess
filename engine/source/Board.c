//
// Created by erik on 23.03.24.
//

#include "Game.h"
#include "Macros.h"

#include <stdlib.h>

// --------------------
// forward declarations
// --------------------
bool SquareAttackedBy(tBoard* pBoard, tLocation loc, bool whiteAttacks);

// --------------------
// header function definitions
// --------------------
bool Board_SquareUnderAttack(tBoard* pBoard, tLocation loc){
  return SquareAttackedBy(pBoard, loc, pBoard->whiteToMove);
}

bool Board_SquareDefended(tBoard* pBoard, tLocation loc){
  return SquareAttackedBy(pBoard, loc, !pBoard->whiteToMove);
}

bool Board_IsCheck(tBoard* pBoard){
  if(pBoard->whiteToMove){
    return Board_SquareUnderAttack(pBoard, pBoard->whiteKing);
  }
  else{
    return Board_SquareUnderAttack(pBoard, pBoard->blackKing);
  }
}

bool Board_KingCaptureable(tBoard* pBoard){
  if(pBoard->whiteToMove){
    return Board_SquareUnderAttack(pBoard, pBoard->blackKing);
  }
  else{
    return Board_SquareUnderAttack(pBoard, pBoard->whiteKing);
  }
}

tLocation Board_CoordsToLocation(uint8_t col, uint8_t row){
  tLocation loc;
  loc.col = col;
  loc.row = row;
  return loc;
}

char* Board_LocationToStr(tLocation loc){
  char* pChar = malloc(3);
  IF_NULL_RETURN_NULL(pChar);

  pChar[0] = 'a' + (char)(loc.col);
  pChar[1] = '1' + (char)(loc.row);
  pChar[2] = '\0';

  return pChar;
}

// --------------------
// internal function definitions
// --------------------
bool SquareAttackedBy(tBoard* pBoard, tLocation loc, bool whiteAttacks){
  int i;

  // up
  i = 1;
  while (loc.row + i < BOARD_ROWS){
    tLocation newLoc = {loc.row + i, loc.col};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskRook | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // down
  i = 1;
  while (loc.row + i >= 0){
    tLocation newLoc = {loc.row - i, loc.col};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskRook | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // right
  i = 1;
  while (loc.col + i < BOARD_COLS){
    tLocation newLoc = {loc.row, loc.col + i};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskRook | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // left
  i = 1;
  while (loc.col - i >= 0){
    tLocation newLoc = {loc.row, loc.col - i};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskRook | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // up right
  i = 1;
  while (loc.row + i < BOARD_ROWS && loc.col + i < BOARD_COLS){
    tLocation newLoc = {loc.row + i, loc.col + i};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskBishop | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // up left
  i = 1;
  while (loc.row + i < BOARD_ROWS && loc.col - i >= 0){
    tLocation newLoc = {loc.row + i, loc.col - i};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskBishop | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // down right
  i = 1;
  while (loc.row - i >= 0 && loc.col + i < BOARD_COLS){
    tLocation newLoc = {loc.row - i, loc.col + i};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskBishop | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  // down left
  i = 1;
  while (loc.row - i >= 0 && loc.col - i >= 0){
    tLocation newLoc = {loc.row - i, loc.col - i};
    if(AT(pBoard->squares_kind, newLoc) != cNoPiece){
      if((Piece_isWhite(pBoard, newLoc) == whiteAttacks)){
        if(i == 1){
          if(Piece_isKind(pBoard, newLoc, cMaskKing))
            return true;
        }
        if(Piece_isKind(pBoard, newLoc, cMaskBishop | cMaskQueen))
          return true;
      }
    }
    i++;
  }

  return false;
}
