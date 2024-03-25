//
// Created by erik on 25.03.24.
//

#ifndef C_CHESS_MOVE_H
#define C_CHESS_MOVE_H

typedef enum eMovetype{
  null_move,
  piece_move,
  pawn_move,
  capture,
  en_passant,
  castle_short,
  castle_long,
}eMovetype;

typedef struct tMove{
  eMovetype type;
  tLocation begin;
  tLocation end;
  tPieceType movingPiece;
  tPieceType takenPiece;

  bool check;
  bool mate;
  bool stalemate;
  bool promotion;
}tMove;

#endif //C_CHESS_MOVE_H
