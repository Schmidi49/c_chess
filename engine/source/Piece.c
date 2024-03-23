//
// Created by erik on 23.03.24.
//

#include "Piece.h"
#include "Rook.h"

#include <stdlib.h>

// --------------------
// forward declarations
// --------------------


// --------------------
// header function definitions
// --------------------

Piece_t* Piece_NewRook(struct Board_s* pBoard, int8_t offset, bool isWhite){
  Piece_t* pNewRook = malloc(sizeof(Piece_t));
  if(pNewRook == NULL){
    return NULL;
  }
  if(DlList_PushBack(&pBoard->activePieceList, (void*)(pNewRook)) == NULL){
    free(pNewRook);
    return NULL;
  }

  pNewRook->kind = isWhite ? 'R' : 'r';
  pNewRook->isWhite = true;
  pNewRook->active = true;
  pNewRook->onBoardOffset = offset;
  pNewRook->pBoard = pBoard;
  pNewRook->pMethods = &Rook_MethodeTable;

  AT(pBoard, offset) = pNewRook;

  return pNewRook;
}

// --------------------
// internal function definitions
// --------------------
