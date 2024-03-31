//
// Created by erik on 25.03.24.
//

#include "Game.h"
#include "Macros.h"

#include "Rook.h"

#include <string.h>

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

  DlList_Init(&pGame->moveList);
}

tPieceMethodes const* Game_GetMethodes(tPieceType kind){
  if(kind == cWhiteRook || kind == cBlackRook)
    return &Rook_MethodeTable;
  else
    return NULL;
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