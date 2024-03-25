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
    move.end = Game_CoordsToLocation(c, r);
    if(pBoard->squares_kind[c][r] == cNoPiece){
      move.takenPiece = cNoPiece;
      move.type = piece_move;
      genCB(pBase, &move);
    }
    else{
      move.takenPiece = AT(pBoard->squares_kind, loc);
      move.type = capture;
      genCB(pBase, &move);
      break;
    }
  }
  //downwards
  for(r = loc.row - 1; r >= 0; r--){
    move.end = Game_CoordsToLocation(c, r);
    if(pBoard->squares_kind[c][r] == cNoPiece){
      move.takenPiece = cNoPiece;
      move.type = piece_move;
      genCB(pBase, &move);
    }
    else{
      move.takenPiece = AT(pBoard->squares_kind, loc);
      move.type = capture;
      genCB(pBase, &move);
      break;
    }
  }
  //rightwards
  r = loc.row;
  for(c = loc.col + 1; c < BOARD_COLS; c++){
    move.end = Game_CoordsToLocation(c, r);
    if(pBoard->squares_kind[c][r] == cNoPiece){
      move.takenPiece = cNoPiece;
      move.type = piece_move;
      genCB(pBase, &move);
    }
    else{
      move.takenPiece = AT(pBoard->squares_kind, loc);
      move.type = capture;
      genCB(pBase, &move);
      break;
    }
  }
  //downwards
  for(c = loc.col - 1; c >= 0; c--){
    move.end = Game_CoordsToLocation(c, r);
    if(pBoard->squares_kind[c][r] == cNoPiece){
      move.takenPiece = cNoPiece;
      move.type = piece_move;
      genCB(pBase, &move);
    }
    else{
      move.takenPiece = AT(pBoard->squares_kind, loc);
      move.type = capture;
      genCB(pBase, &move);
      break;
    }
  }
}

// --------------------
// internal function definitions
// --------------------
