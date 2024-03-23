//
// Created by erik on 23.03.24.
//

#ifndef C_CHESS_PIECE_H
#define C_CHESS_PIECE_H

#define AT(pBoard, offset) *(*(pBoard->squares) + offset)

#include "Board.h"
#include "Piece.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct Piece_s{
  char kind;
  bool isWhite;
  bool active;

  int8_t onBoardOffset;

  struct PieceMethodes_s* pMethods;
  struct Board_s* pBoard;
} Piece_t;

typedef struct PieceMethodes_s{
  int32_t (*getValue)(struct Piece_s* pSelf);
} PieceMethodes_t;

Piece_t* Piece_NewRook(struct Board_s* pBoard, int8_t offset, bool isWhite);


#endif //C_CHESS_PIECE_H
