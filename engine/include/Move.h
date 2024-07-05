//
// Created by erik on 25.03.24.
//

#ifndef C_CHESS_MOVE_H
#define C_CHESS_MOVE_H

typedef enum eMovetype{
  no_move = 0, // state where the move is unconfigured
  null_move,
  piece_move,
  pawn_move,
  pawn_move_double,
  pawn_move_promotion,
  capture,
  pawn_capture_promotion,
  en_passant,
  castle_short,
  castle_long,
} eMovetype;

typedef struct tMove{
  eMovetype type;
  tLocation begin;
  tLocation end;
  tPieceType movingPiece;
  tPieceType takenPiece;
  tPieceID movingID;
  tPieceID takenID;

  //TODO check if flags are necessary (promotion prob. is
  bool promotion_rook;
} tMove;

#endif //C_CHESS_MOVE_H
