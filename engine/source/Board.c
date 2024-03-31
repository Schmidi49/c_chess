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
