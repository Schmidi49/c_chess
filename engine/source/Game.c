//
// Created by erik on 25.03.24.
//

#include "Game.h"
#include "Macros.h"

#include "Rook.h"

#include <string.h>
#include <stdlib.h>

// --------------------
// forward declarations
// --------------------
static void setupPieces(tGame* pGame);

// --------------------
// header function definitions
// --------------------
void Game_Init(tGame* pGame){
  int i;
  IF_NULL_RETURN(pGame)

  memset(pGame->currentBoard.squares_kind, cNoPiece, BOARD_ROWS * BOARD_COLS);
  for(i = 0; i < BOARD_ROWS * BOARD_COLS; i++){
    AT(pGame->currentBoard.squares_id, i) = cNoID;
  }

  setupPieces(pGame);
  pGame->currentBoard.whiteToMove = true;
  pGame->currentBoard.pGame = pGame;

  DlList_Init(&pGame->moveList);
}

tPieceMethodes const* Game_GetMethodes(tPieceType kind){
  if(kind == cWhiteRook || kind == cBlackRook)
    return &Rook_MethodeTable;
  else
    return NULL;
}

tLocation Game_CoordsToLocation(uint8_t col, uint8_t row){
  tLocation loc;
  loc.col = col;
  loc.row = row;
  return loc;
}

char* Game_LocationToStr(tLocation loc){
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
static void setupPieces(tGame* pGame){
  tPieceID count = 0;

  pGame->currentBoard.squares_kind[5][2] = cWhiteRook;
  pGame->currentBoard.squares_id[5][2] = count;
  count++;

//  pGame->currentBoard.squares_kind[0][7] = cBlackRook;
//  pGame->currentBoard.squares_id[0][7] = count;
//  count++;
}