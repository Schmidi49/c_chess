//
// Created by erik on 21.03.24.
//

#include "PolynaryTree.h"

#include <stdio.h>

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

  PolyTree_Node_t* e4 = PolyTree_CopyBack(root, 5, "e4");
  PolyTree_Node_t* d4 = PolyTree_CopyBack(root, 5, "d4");
  PolyTree_Node_t* c4 = PolyTree_CopyBack(root, 5, "c4");

  PolyTree_Node_t* e4e5 = PolyTree_CopyBack(e4, 5, "e5");
  PolyTree_Node_t* e4d5 = PolyTree_CopyBack(e4, 5, "d5");
  PolyTree_Node_t* e4c5 = PolyTree_CopyBack(e4, 5, "c5");
  PolyTree_Node_t* e4c6 = PolyTree_CopyBack(e4, 5, "c6");

  PolyTree_Node_t* e4e5Sf3 = PolyTree_CopyBack(e4e5, 5, "Sf3");
  PolyTree_Node_t* russian = PolyTree_CopyBack(e4e5Sf3, 5, "Sf6");

  PolyTree_Node_t* alapin = PolyTree_CopyBack(e4c5, 5, "c3");

  PolyTree_CopyBackHorizontal(d4, 5, 4, "d5", "Sf6", "e6", "f5");
  PolyTree_CopyBackVertical(e4c6, 5, 8, "Sf3", "d6", "d4", "cxd5", "Nxd5", "Sf6", "Sc3", "a6");

  PolyTree_VisitPreOrder(root, move_visitor);
  PolyTree_Free(root);

  return 0;
}