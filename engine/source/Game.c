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
  IF_NULL_RETURN(pGame)

  memset(pGame->currentBoard.squares_kind, cNoPiece, BOARD_ROWS * BOARD_COLS);
  memset(pGame->currentBoard.squares_id, cNoPiece, BOARD_ROWS * BOARD_COLS * sizeof(tPieceID));
  memset(pGame->globalPieces, 0, sizeof pGame->globalPieces);

  setupPieces(pGame);
  pGame->currentBoard.whiteToMove = true;
  pGame->currentBoard.pGame = pGame;

  DlList_Init(&pGame->moveList);
}

// --------------------
// internal function definitions
// --------------------
static void setupPieces(tGame* pGame){
  tPieceID count = 0;

  pGame->globalPieces[count].kind = cWhiteRook;
  pGame->globalPieces[count].pMethodes = &Rook_MethodeTable;
  pGame->currentBoard.squares_kind[7][0] = cWhiteRook;
  pGame->currentBoard.squares_id[7][0] = count;
  count++;

  pGame->globalPieces[count].kind = cBlackRook;
  pGame->globalPieces[count].pMethodes = &Rook_MethodeTable;
  pGame->currentBoard.squares_kind[0][7] = cBlackRook;
  pGame->currentBoard.squares_id[0][7] = count;
  count++;
}