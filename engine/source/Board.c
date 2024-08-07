//
// Created by erik on 23.03.24.
//

#include "Game.h"
#include "Macros.h"

#include <stdlib.h>

// --------------------
// forward declarations
// --------------------
static bool SquareAttackedBy(tBoard* pBoard, tLocation loc, bool whiteAttacks);

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

tLocation Board_CoordsToLocation(const uint8_t col, const uint8_t row){
  tLocation loc;
  loc.col = col;
  loc.row = row;
  return loc;
}

tLocation Board_StrToLocation(const char* field){
  tLocation loc;
  loc.col = *(field+0) - 'a';
  loc.row = *(field+1) - '1';
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

void Board_Advance(tBoard* pBoard, tMove* pMove){
  pBoard->squares_id[pMove->end.col][pMove->end.row] = AT(pBoard->squares_id, pMove->begin);
  pBoard->squares_kind[pMove->end.col][pMove->end.row] = pMove->movingPiece;
  pBoard->squares_id[pMove->begin.col][pMove->begin.row] = cNoID;
  pBoard->squares_kind[pMove->begin.col][pMove->begin.row] = cNoPiece;

  if(pMove->movingPiece == cWhiteKing){
    pBoard->whiteKing = pMove->end;
  }
  else if(pMove->movingPiece == cBlackKing){
    pBoard->blackKing = pMove->end;
  }

  pBoard->whiteToMove = !pBoard->whiteToMove;
}

void Board_GenerateMoves(tBoard* pBoard, Piece_GenerateCB genCB, void* pBase){
  for(uint8_t r = 0; r < BOARD_ROWS; r++){
    for(uint8_t c = 0; c < BOARD_COLS; c++){
      tLocation loc = Board_CoordsToLocation(c, r);

      if(Piece_isWhite(pBoard, loc) == pBoard->whiteToMove){
        const tPieceMethodes* methodes = Piece_GetMethodes(pBoard, loc);
        if(methodes != NULL){
          methodes->generateMoves(pBoard, loc, genCB, pBase);
        }
      }
    }
  }
}

// --------------------
// internal function definitions
// --------------------
static bool SquareAttackedBy(tBoard* pBoard, tLocation loc, bool whiteAttacks){
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
