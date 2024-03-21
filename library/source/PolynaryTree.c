//
// Created by erik on 21.03.24.
//

#include "PolynaryTree.h"

#include <stdlib.h>

typedef PolyTree_Node_t Node_t;

// --------------------
// forward declarations
// --------------------

static void freeSubtree(PolyTree_Node_t* pRoot);

static void freeSubtreeWithoutData(PolyTree_Node_t* pRoot);

// --------------------
// header function definitions
// --------------------
PolyTree_Node_t* PolyTree_New(void* pData){
  PolyTree_Node_t* pNewRoot = malloc(sizeof(Node_t));
  if(pNewRoot == NULL){
    return NULL;
  }
  pNewRoot->pData = pData;
  pNewRoot->pPrev = NULL;
  pNewRoot->pNext = NULL;
  pNewRoot->pFirst = NULL;
  pNewRoot->pLast = NULL;
  return pNewRoot;
}

PolyTree_Node_t* PolyTree_PushBack(PolyTree_Node_t* pRoot, void* pData){
  Node_t* pNewNode;
  if(pRoot == NULL){
    return NULL;
  }

  //allocate memory
  pNewNode = malloc(sizeof(Node_t));
  if(pNewNode == NULL){
    return NULL;
  }

  //change general pointers
  pNewNode->pData = pData;
  pNewNode->pFirst = NULL;
  pNewNode->pLast = NULL;
  pNewNode->pNext = NULL;
  pNewNode->pPrev = pRoot->pLast;

  // edge case: empty branch
  if(pRoot->pFirst == NULL){
    pRoot->pFirst = pNewNode;
    pRoot->pLast = pNewNode;
    return pNewNode;
  }

  //normal case
  pRoot->pLast->pNext = pNewNode;
  pRoot->pLast = pNewNode;
  return pNewNode;
}

void** PolyTree_CreateBack(PolyTree_Node_t* pRoot, size_t n){
  void* pNewData;
  Node_t * pCreatedNode;
  if(pRoot == NULL){
    return NULL;
  }

  //allocate memory
  pNewData = malloc(n);
  if(pNewData == NULL){
    return NULL;
  }

  //push back the created data
  pCreatedNode = PolyTree_PushBack(pRoot, pNewData);
  if(pCreatedNode == NULL){
    free(pNewData);
    return NULL;
  }
  return &(pCreatedNode->pData);
}

void PolyTree_VisitPreOrder(PolyTree_Node_t* pRoot, PolyTree_Visitor_t visitor){
  PolyTree_VisitPreOrderDepth(pRoot, visitor, 0);
}

void PolyTree_VisitPreOrderDepth(PolyTree_Node_t* pRoot, PolyTree_Visitor_t visitor, size_t depth){
  PolyTree_Node_t* pCur;
  if(pRoot == NULL){
    return;
  }
  visitor(pRoot->pData, depth++);

  pCur = pRoot->pFirst;
  while(pCur != NULL){
    PolyTree_VisitPreOrderDepth(pCur, visitor, depth);
    pCur = pCur->pNext;
  }
}

void PolyTree_Free(PolyTree_Node_t* pRoot){
  if(pRoot == NULL){
    return;
  }

  freeSubtree(pRoot);
  free(pRoot->pData);
  free(pRoot);
}

void PolyTree_FreeWithoutData(PolyTree_Node_t* pRoot){
  if(pRoot == NULL){
    return;
  }

  freeSubtreeWithoutData(pRoot);
  free(pRoot);
}

// --------------------
// internal function definitions
// --------------------

static void freeSubtree(PolyTree_Node_t* pRoot){
  PolyTree_Node_t* pCur;
  if(pRoot == NULL){
    return;
  }

  pCur = pRoot->pFirst;
  if(pCur == NULL){
    return;
  }

  while(pCur->pNext != NULL){
    freeSubtree(pCur);
    free(pCur->pData);
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }

  freeSubtree(pCur);
  free(pCur->pData);
  free(pCur);
}

static void freeSubtreeWithoutData(PolyTree_Node_t* pRoot){
  PolyTree_Node_t* pCur;
  if(pRoot == NULL){
    return;
  }

  pCur = pRoot->pFirst;
  if(pCur == NULL){
    return;
  }

  while(pCur->pNext != NULL){
    freeSubtreeWithoutData(pCur);
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }

  freeSubtreeWithoutData(pCur);
  free(pCur);
}