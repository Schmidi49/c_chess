//
// Created by erik on 25.03.24.
//

#ifndef C_CHESS_MOVE_H
#define C_CHESS_MOVE_H

typedef enum eMovetype{
  null_move = 0,
  piece_move = 1,
  pawn_move = 2,
  pawn_move_double = 3,
  capture = 4,
  en_passant = 5,
  castle_short = 6,
  castle_long = 7,
} eMovetype;

typedef struct tMove{
  eMovetype type;
  tLocation begin;
  tLocation end;
  tPieceType movingPiece;
  tPieceType takenPiece;

  //TODO check if flags are necessary (promotion prob. is
  bool check;
  bool mate;
  bool stalemate;
  bool promotion;
} tMove;

#endif //C_CHESS_MOVE_H
