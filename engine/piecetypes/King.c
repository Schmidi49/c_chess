//
// Created by erik on 29.03.24.
//

#include "King.h"

const tPieceMethodes King_MethodeTable = {
  .getValue = King_GetValue,
  .generateMoves = King_GenerateMoves,
  .kindMask = cMaskKing
};

tKing_MoveInc const King_MovePattern[KING_MOVES] = {
  {.rowinc = -1, .colinc = 1},
  {.rowinc = -1, .colinc = 0},
  {.rowinc = -1, .colinc = -1},

  {.rowinc = 0, .colinc = 1},
  {.rowinc = 0, .colinc = -1},

  {.rowinc = 1, .colinc = 1},
  {.rowinc = 1, .colinc = 0},
  {.rowinc = 1, .colinc = -1},
};

// --------------------
// forward declarations
// --------------------

// --------------------
// header function definitions
// --------------------

int32_t King_GetValue(tBoard* pBoard, tLocation loc){
  return Piece_isWhite(pBoard, loc) ? 100000 : -100000;
}

void King_GenerateMoves(tBoard* pBoard, tLocation loc, Piece_GenerateCB genCB, void* pBase){
  int8_t i, r, c;
  tMove move = {
    .begin = loc,
    .movingPiece = AT(pBoard->squares_kind, loc),
    .movingID = AT(pBoard->squares_id, loc),
    .promotion_rook = false};

  for(i = 0; i < KING_MOVES; i++){
    r = King_MovePattern[i].rowinc + loc.row;
    if(r >= BOARD_ROWS || r < 0){
      continue;
    }
    c = King_MovePattern[i].colinc + loc.col;
    if(c >= BOARD_COLS || c < 0){
      continue;
    }
    // legal move check (field attacked)

    move.end = Board_CoordsToLocation(c, r);
    move.takenPiece = AT(pBoard->squares_kind, move.end);
    move.takenID = AT(pBoard->squares_id, move.end);
    if(move.takenPiece == cNoPiece){
      move.type = piece_move;
    }
    else{
      move.type = capture;
    }
    genCB(pBase, &move);
  }
}

// --------------------
// internal function definitions
// --------------------