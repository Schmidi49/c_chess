//
// Created by erik on 21.03.24.
//

#include "PolynaryTree.h"

#include <stdio.h>
#include <stdlib.h>

void move_visitor(void* move, size_t indent){
  size_t i;
  if(move == NULL){
    printf("init\n");
    return;
  }
  for(i = 0; i < indent; i++){
    putchar('-');
  }
  printf("%s\n", (char*)(move));
}

int main(){
  PolyTree_Node_t* root = PolyTree_New(NULL);

  char* E4 = malloc(5);
  char* D4 = malloc(5);
  char* C4 = malloc(5);
  char* E5 = malloc(5);
  char* D5 = malloc(5);
  char* C5 = malloc(5);
  char* C6 = malloc(5);
  char* SF3 = malloc(5);
  char* SF6 = malloc(5);
  char* C3 = malloc(5);

  sprintf(E4, "e4");
  sprintf(D4, "d4");
  sprintf(C4, "c4");
  sprintf(E5, "e5");
  sprintf(D5, "d5");
  sprintf(C5, "c5");
  sprintf(C6, "c6");
  sprintf(SF3, "Sf3");
  sprintf(SF6, "Sf6");
  sprintf(C3, "c3");

  PolyTree_Node_t* e4 = PolyTree_PushBack(root, E4);
  PolyTree_Node_t* d4 = PolyTree_PushBack(root, D4);
  PolyTree_Node_t* c4 = PolyTree_PushBack(root, C4);

  PolyTree_Node_t* e4e5 = PolyTree_PushBack(e4, E5);
  PolyTree_Node_t* e4d5 = PolyTree_PushBack(e4, D5);
  PolyTree_Node_t* e4c5 = PolyTree_PushBack(e4, C5);
  PolyTree_Node_t* e4c6 = PolyTree_PushBack(e4, C6);

  PolyTree_Node_t* e4e5Sf3 = PolyTree_PushBack(e4e5, SF3);
  PolyTree_Node_t* russian = PolyTree_PushBack(e4e5Sf3, SF6);

  PolyTree_Node_t* alapin = PolyTree_PushBack(e4c5, C3);

  PolyTree_VisitPreOrder(root, move_visitor);
  PolyTree_Free(root);

  return 0;
}