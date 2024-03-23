//
// Created by erik on 23.03.24.
//

#include "../include/Board.h"

// --------------------
// forward declarations
// --------------------


// --------------------
// header function definitions
// --------------------
void Board_Init(Board_t* pBoard){
  int i, j;
  if(pBoard == NULL){
    return;
  }
  DlList_Init(&pBoard->activePieceList);
  for(i = 0; i < BOARD_COLS; i++){
    for(j = 0; j < BOARD_ROWS; j++){
      pBoard->squares[i][j] = NULL;
    }
  }
}

// --------------------
// internal function definitions
// --------------------
