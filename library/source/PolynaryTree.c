//
// Created by erik on 21.03.24.
//

#include "PolynaryTree.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef PolyTree_Node_t Node_t;

// --------------------
// forward declarations
// --------------------
static bool defaultCompare(void* pFirst, void* pSecond);

static void freeSubtree(PolyTree_Node_t* pRoot);

static void freeSubtreeWithoutData(PolyTree_Node_t* pRoot);

// --------------------
// header function definitions
// --------------------
PolyTree_Node_t* PolyTree_New(void* pData){
  Node_t* pNewRoot = malloc(sizeof(Node_t));
  PolyTree_Init(pNewRoot, pData);
  return pNewRoot;
}

void PolyTree_Init(PolyTree_Node_t* pRoot, void* pData){
  if(pRoot == NULL){
    return;
  }
  pRoot->pData = pData;
  pRoot->pPrev = NULL;
  pRoot->pNext = NULL;
  pRoot->pFirst = NULL;
  pRoot->pLast = NULL;
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

size_t PolyTree_PushBackHorizontal(PolyTree_Node_t* pRoot, size_t count, ...){
  Node_t* pCur;
  void* arg;
  va_list args;

  if(pRoot == NULL){
    return count;
  }

  va_start(args, count);

  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_PushBack(pRoot, arg);
    if(pCur == NULL){
      return count + 1;
    }
  }
  va_end(args);
  return count;
}

size_t PolyTree_PushBackVertical(PolyTree_Node_t* pRoot, size_t count, ...){
  Node_t* pCur;
  void* arg;
  va_list args;

  if(pRoot == NULL){
    return count;
  }

  pCur = pRoot;
  va_start(args, count);

  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_PushBack(pCur, arg);
    if(pCur == NULL){
      return count + 1;
    }
  }
  va_end(args);
  return count;
}

PolyTree_Node_t* PolyTree_CopyBack(PolyTree_Node_t* pRoot, size_t n, void* pData){
  Node_t* pNewNode = PolyTree_CreateBack(pRoot, n);
  if(pNewNode == NULL){
    return NULL;
  }
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

size_t PolyTree_CopyBackHorizontal(PolyTree_Node_t* pRoot, size_t n, size_t count, ...){
  Node_t* pCur;
  void* arg;
  va_list args;

  if(pRoot == NULL){
    return count;
  }

  va_start(args, count);

  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_CopyBack(pRoot, n, arg);
    if(pCur == NULL){
      return count + 1;
    }
  }
  va_end(args);
  return count;
}

size_t PolyTree_CopyBackVertical(PolyTree_Node_t* pRoot, size_t n, size_t count, ...){
  Node_t* pCur;
  void* arg;
  va_list args;

  if(pRoot == NULL){
    return count;
  }

  pCur = pRoot;
  va_start(args, count);

  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_CopyBack(pCur, n, arg);
    if(pCur == NULL){
      return count + 1;
    }
  }
  va_end(args);
  return count;
}

PolyTree_Node_t* PolyTree_CreateBack(PolyTree_Node_t* pRoot, size_t n){
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
  return pCreatedNode;
}

void PolyTree_VisitPreOrder(PolyTree_Node_t* pRoot, PolyTree_VisitorCB_t visitor){
  PolyTree_VisitPreOrderDepth(pRoot, visitor, 0);
}

void PolyTree_VisitPreOrderDepth(PolyTree_Node_t* pRoot, PolyTree_VisitorCB_t visitor, size_t depth){
  Node_t* pCur;
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

PolyTree_Node_t* PolyTree_Find(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp){
  Node_t* pCur;
  if(pRoot == NULL){
    return NULL;
  }
  if(comp == NULL){
    comp = defaultCompare;
  }

  pCur = pRoot->pFirst;
  while(pCur != NULL){
    if(comp(pItem, pCur->pData)){
      return pCur;
    }
    pCur = pCur->pNext;
  }
  return NULL;
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
static bool defaultCompare(void* pFirst, void* pSecond){
  return pFirst == pSecond;
}

static void freeSubtree(PolyTree_Node_t* pRoot){
  Node_t* pCur;
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
  Node_t* pCur;
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