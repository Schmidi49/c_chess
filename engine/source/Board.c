//
// Created by erik on 23.03.24.
//

#include "Game.h"
#include "Macros.h"

#include <stdlib.h>

// --------------------
// forward declarations
// --------------------


// --------------------
// header function definitions
// --------------------
bool Board_SquareUnderAttack(tBoard* pBoard, tLocation loc){
  
}

bool Board_SquareDefended(tBoard* pBoard, tLocation loc){

}

bool Board_IsCheck(tBoard* pBoard){
  if(pBoard->whiteToMove){
    return Board_SquareUnderAttack(pBoard, pBoard->whiteKing);
  }
  else{
    return Board_SquareUnderAttack(pBoard, pBoard->blackKing);
  }
}

bool Board_KingCaptureable(tBoard* pBoard){
  if(pBoard->whiteToMove){
    return Board_SquareUnderAttack(pBoard, pBoard->blackKing);
  }
  else{
    return Board_SquareUnderAttack(pBoard, pBoard->whiteKing);
  }
}

tLocation Board_CoordsToLocation(uint8_t col, uint8_t row){
  tLocation loc;
  loc.col = col;
  loc.row = row;
  return loc;
}

char* Board_LocationToStr(tLocation loc){
  char* pChar = malloc(3);
  IF_NULL_RETURN_NULL(pChar);

  pChar[0] = 'a' + (char)(loc.col);
  pChar[1] = '1' + (char)(loc.row);
  pChar[2] = '\0';

  return pChar;
}

// --------------------
// internal function definitions
// --------------------
