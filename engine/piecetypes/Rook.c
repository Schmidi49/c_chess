//
// Created by erik on 23.03.24.
//

#include "Rook.h"

const tPieceMethodes Rook_MethodeTable = {
  .getValue = Rook_GetValue,
  .generateMoves = Rook_GenerateMoves
};

// --------------------
// forward declarations
// --------------------
bool finishMove(int col, int row, tBoard* pBoard, tMove* pMove, Piece_GenerateCB genCB, void* pBase);


// --------------------
// header function definitions
// --------------------
int32_t Rook_GetValue(tBoard* pBoard, tLocation loc){
  return Piece_isWhite(pBoard, loc) ? 500 : -500;
}

void Rook_GenerateMoves(tBoard* pBoard, tLocation loc, Piece_GenerateCB genCB, void* pBase){
  int c, r;
  tMove move = {
    .begin = loc,
    .movingPiece = AT(pBoard->squares_kind, loc),
    .check = false,
    .mate = false,
    .promotion = false};
  //upwards
  c = loc.col;
  for(r = loc.row + 1; r < BOARD_ROWS; r++){
    if(finishMove(c, r, pBoard, &move, genCB, pBase))
      break;
  }
  //downwards
  for(r = loc.row - 1; r >= 0; r--){
    if(finishMove(c, r, pBoard, &move, genCB, pBase))
      break;
  }
  //rightwards
  r = loc.row;
  for(c = loc.col + 1; c < BOARD_COLS; c++){
    if(finishMove(c, r, pBoard, &move, genCB, pBase))
      break;
  }
  //downwards
  for(c = loc.col - 1; c >= 0; c--){
    if(finishMove(c, r, pBoard, &move, genCB, pBase))
      break;
  }
}

// --------------------
// internal function definitions
// --------------------
bool finishMove(int col, int row, tBoard* pBoard, tMove* pMove, Piece_GenerateCB genCB, void* pBase){
  pMove->end = Game_CoordsToLocation(col, row);
  pMove->takenPiece = AT(pBoard->squares_kind, pMove->end);
  if(pMove->takenPiece == cNoPiece){
    pMove->type = piece_move;
    genCB(pBase, pMove);
  }
  else{
    pMove->type = capture;
    genCB(pBase, pMove);
    return true;
  }
  return false;
}