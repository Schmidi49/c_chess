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
  pawn_move_promotion = 4,
  capture = 5,
  pawn_capture_promotion = 6,
  en_passant = 7,
  castle_short = 8,
  castle_long = 9,
} eMovetype;

typedef struct tMove{
  eMovetype type;
  tLocation begin;
  tLocation end;
  tPieceType movingPiece;
  tPieceType takenPiece;

  //TODO check if flags are necessary (promotion prob. is
  bool promotion_rook;
} tMove;

#endif //C_CHESS_MOVE_H
