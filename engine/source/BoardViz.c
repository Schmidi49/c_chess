#include "BoardViz.h"

#include <stdio.h>

// --------------------
// forward declarations
// --------------------

static const char* hor = "═";
static const char* ver =  "║";

static const char* tLeft =  "╠";
static const char* tRight =  "╣";
static const char* tUp =  "╦";
static const char* tDown =  "╩";

static const char* cornUpLeft =  "╔";
static const char* cornUpRight =  "╗";
static const char* cornDownLeft =  "╚";
static const char* cornDownRight =  "╝";

static const char* cross =  "╬";

static void drawUpLine(FILE* f);
static void drawMidLine(FILE* f);
static void drawInbetweenLine(FILE* f);
static void drawBotLine(FILE* f);

static void printHeader(FILE* f);
static void printFooter(FILE* f);

// --------------------
// header function definitions
// --------------------
void BoardViz_PrintBoard(tBoard* pBoard, FILE* f){
  printHeader(f);

  for(int row = BOARD_ROWS - 1; row >= 0; row--){
    drawMidLine(f);
    drawInbetweenLine(f);

    fprintf(f, "%s %1i %s", ver, row + 1, ver);
    for(int col = 0; col < BOARD_COLS; col++){
      fprintf(f, "   %c   %s", pBoard->squares_kind[col][row], ver);
    }
    fprintf(f, " %1i %s\n", row + 1, ver);

    drawInbetweenLine(f);
  }
  drawMidLine(f);
  printFooter(f);
}

// --------------------
// internal function definitions
// --------------------

static void drawUpLine(FILE* f){
  fprintf(f, "%s%s%s%s%s", cornUpLeft, hor, hor, hor, tUp);
  for(int i = 0; i < 8; i++){
    fprintf(f, "%s%s%s%s%s%s%s%s", hor, hor, hor, hor, hor, hor, hor, tUp);
  }
  fprintf(f, "%s%s%s%s\n", hor, hor, hor, cornUpRight);
}

static void drawMidLine(FILE* f){
  fprintf(f, "%s%s%s%s%s", tLeft, hor, hor, hor, cross);
  for(int i = 0; i < 8; i++){
    fprintf(f, "%s%s%s%s%s%s%s%s", hor, hor, hor, hor, hor, hor, hor, cross);
  }
  fprintf(f, "%s%s%s%s\n", hor, hor, hor, tRight);
}

static void drawInbetweenLine(FILE* f){
  fprintf(f, "%s   %s", ver, ver);
  for(int i = 0; i < 8; i++){
    fprintf(f, "       %s", ver);
  }
  fprintf(f, "   %s\n", ver);
}

static void drawBotLine(FILE* f){
  fprintf(f, "%s%s%s%s%s", cornDownLeft, hor, hor, hor, tDown);
  for(int i = 0; i < 8; i++){
    fprintf(f, "%s%s%s%s%s%s%s%s", hor, hor, hor, hor, hor, hor, hor, tDown);
  }
  fprintf(f, "%s%s%s%s\n", hor, hor, hor, cornDownRight);
}

static void printHeader(FILE* f){
  drawUpLine(f);
  fprintf(f, "%s   %s", ver, ver);
  for(int col = 0; col < BOARD_COLS; col++){
    fprintf(f, "   %c   %s", 'a' + col, ver);
  }
  fprintf(f, "   %s\n", ver);
}

static void printFooter(FILE* f){
  fprintf(f, "%s   %s", ver, ver);
  for(int col = 0; col < BOARD_COLS; col++){
    fprintf(f, "   %c   %s", 'a' + col, ver);
  }
  fprintf(f, "   %s\n", ver);
  drawBotLine(f);
}