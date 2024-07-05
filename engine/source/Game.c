//
// Created by erik on 25.03.24.
//

#include "Game.h"
#include "Macros.h"

#include <string.h>

// --------------------
// forward declarations
// --------------------
static void setupPieces(tGame* pGame);

struct pieces{
  char field[2];
  char kind;
} const pieceLocations[] = {  {.field = "f3", .kind = 'R'},
                              {.field = "e4", .kind = 'K'},
                              {.field = "h8", .kind = 'k'}};

const size_t cPieceNumber = (sizeof pieceLocations) / (sizeof(struct pieces));



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

// --------------------
// internal function definitions
// --------------------
static void setupPieces(tGame* pGame){
  for(tPieceID count = 0; count < cPieceNumber; count++){
    tLocation loc = Board_StrToLocation(pieceLocations[count].field);
    pGame->currentBoard.squares_kind[loc.col][loc.row] = pieceLocations[count].kind;
    pGame->currentBoard.squares_id[loc.col][loc.row] = count;

    if(pieceLocations[count].kind == 'K')
      pGame->currentBoard.whiteKing = loc;
    else if(pieceLocations[count].kind == 'k')
      pGame->currentBoard.blackKing = loc;

  }
}