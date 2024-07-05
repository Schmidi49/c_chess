/******************************************************************************
 * @file PolynaryTree.c
 * @author Erik Schmidthaler
 * @brief source File for the Polynary Tree data structure
 *
 * (C) Erik Schmidthaler (21.03.2024)
 */

#include "PolynaryTree.h"
#include "Macros.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef tPolyTree_Node tNode;

// --------------------
// forward declarations
// --------------------
/// @brief default compare, compares by pointer addresses
/// @param pFirst first pointer to be compared
/// @param pSecond seconds pointer to be compared
/// @return compare result
static bool defaultCompare(void* pFirst, void* pSecond);

/// @brief frees the whole subtree (data and nodes), but not the root pointer itself
/// @param pRoot root pointer
static void freeSubtree(tNode* pRoot);

/// @brief frees the whole subtree (only nodes, not the data), but not the root pointer itself
/// @param pRoot root pointer
static void freeSubtreeWithoutData(tNode* pRoot);

// --------------------
// header function definitions
// --------------------
tNode* PolyTree_New(void* pData){
  tNode* pNewRoot;
  ALLOC(pNewRoot, sizeof(tNode))

  PolyTree_Init(pNewRoot, pData);
  return pNewRoot;
}

void PolyTree_Init(tNode* pRoot, void* pData){
  IF_NULL_RETURN(pRoot)
  pRoot->pData = pData;
  pRoot->pPrev = NULL;
  pRoot->pNext = NULL;
  pRoot->pFirst = NULL;
  pRoot->pLast = NULL;
}

tNode* PolyTree_PushBack(tNode* pRoot, void* pData){
  tNode* pNewNode;
  IF_NULL_RETURN_NULL(pRoot)
  ALLOC(pNewNode, sizeof(tNode))

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

size_t PolyTree_PushBackHorizontal(tNode* pRoot, size_t count, ...){
  tNode* pCur;
  void* arg;
  va_list args;
  IF_NULL_RETURN_VAL(pRoot, count)

  //initialize the argument list
  va_start(args, count);
  //iterate threw the arguments
  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_PushBack(pRoot, arg);
    //if the pushback fails, return failed args number
    IF_NULL_RETURN_VAL(pCur, count + 1)
  }
  va_end(args);
  return count;
}

size_t PolyTree_PushBackVertical(tNode* pRoot, size_t count, ...){
  tNode* pCur = pRoot;
  void* arg;
  va_list args;
  IF_NULL_RETURN_VAL(pRoot, count)

  //initialize the argument list
  va_start(args, count);
  //iterate threw the arguments
  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_PushBack(pCur, arg);
    //if the pushback fails, return failed args number
    IF_NULL_RETURN_VAL(pCur, count + 1)
  }
  va_end(args);
  return count;
}

tNode* PolyTree_CopyBack(tNode* pRoot, size_t n, void* pData){
  //allocate memory by CreateBack
  tNode* pNewNode = PolyTree_CreateBack(pRoot, n);
  IF_NULL_RETURN_NULL(pNewNode)
  //copies bytes
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

size_t PolyTree_CopyBackHorizontal(tNode* pRoot, size_t n, size_t count, ...){
  tNode* pCur;
  void* arg;
  va_list args;
  IF_NULL_RETURN_VAL(pRoot, count)

  //initialize the argument list
  va_start(args, count);
  //iterate threw the arguments
  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_CopyBack(pRoot, n, arg);
    //if the copyback fails, return failed args number
    IF_NULL_RETURN_VAL(pCur, count + 1)
  }
  va_end(args);
  return count;
}

size_t PolyTree_CopyBackVertical(tNode* pRoot, size_t n, size_t count, ...){
  tNode* pCur = pRoot;
  void* arg;
  va_list args;
  IF_NULL_RETURN_VAL(pRoot, count)

  //initialize the argument list
  va_start(args, count);
  //iterate threw the arguments
  while(count--){
    arg = va_arg(args, void*);
    pCur = PolyTree_CopyBack(pCur, n, arg);
    //if the copyback fails, return failed args number
    IF_NULL_RETURN_VAL(pCur, count + 1)
  }
  va_end(args);
  return count;
}

tNode* PolyTree_CreateBack(tNode* pRoot, size_t n){
  void* pNewData;
  tNode* pCreatedNode;
  IF_NULL_RETURN_NULL(pRoot)

  //allocate memory
  pNewData = malloc(n);
  IF_NULL_RETURN_NULL(pNewData)

  //push back the created data
  pCreatedNode = PolyTree_PushBack(pRoot, pNewData);
  if(pCreatedNode == NULL){
    free(pNewData);
    return NULL;
  }
  return pCreatedNode;
}

void PolyTree_VisitPreOrder(tNode* pRoot, PolyTree_VisitorCB visitor){
  PolyTree_VisitPreOrderDepth(pRoot, visitor, 0);
}

void PolyTree_VisitPreOrderDepth(tNode* pRoot, PolyTree_VisitorCB visitor, size_t depth){
  tNode* pCur;
  IF_NULL_RETURN(pRoot)

  //visit the root node
  visitor(pRoot->pData, depth++);
  //iterate threw leafs
  pCur = pRoot->pFirst;
  while(pCur != NULL){
    PolyTree_VisitPreOrderDepth(pCur, visitor, depth);
    pCur = pCur->pNext;
  }
}

void PolyTree_VisitLeafs(tPolyTree_Node* pRoot, PolyTree_VisitorCB visitor, size_t depth){
  tNode* pCur;
  IF_NULL_RETURN(pRoot)

  //iterate threw leafs
  pCur = pRoot->pFirst;
  while(pCur != NULL){
    visitor(pCur, 0);
    pCur = pCur->pNext;
  }
}

tNode* PolyTree_Find(tNode* pRoot, void* pItem, PolyTree_CompareCB comp){
  tNode* pCur;
  IF_NULL_RETURN_NULL(pRoot)
  // use the default comparator when no is given
  if(comp == NULL){
    comp = defaultCompare;
  }

  //iterate and compare
  pCur = pRoot->pFirst;
  while(pCur != NULL){
    if(comp(pItem, pCur->pData)){
      return pCur;
    }
    pCur = pCur->pNext;
  }
  return NULL;
}

void PolyTree_Free(tNode* pRoot){
  IF_NULL_RETURN(pRoot)
  //frees the subtree, then the root
  freeSubtree(pRoot);
  free(pRoot->pData);
  free(pRoot);
}

void PolyTree_FreeWithoutData(tNode* pRoot){
  IF_NULL_RETURN(pRoot)
  //frees the subtree, then the root
  freeSubtreeWithoutData(pRoot);
  free(pRoot);
}

// --------------------
// internal function definitions
// --------------------
static bool defaultCompare(void* pFirst, void* pSecond){
  return pFirst == pSecond;
}

static void freeSubtree(tNode* pRoot){
  tNode* pCur;
  IF_NULL_RETURN(pRoot)
  // check for leafs
  pCur = pRoot->pFirst;
  IF_NULL_RETURN(pCur)
  // iterate
  while(pCur->pNext != NULL){
    freeSubtree(pCur);
    free(pCur->pData);
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }
  //free last leaf
  freeSubtree(pCur);
  free(pCur->pData);
  free(pCur);
}

static void freeSubtreeWithoutData(tNode* pRoot){
  tNode* pCur;
  IF_NULL_RETURN(pRoot)
  // check for leafs
  pCur = pRoot->pFirst;
  IF_NULL_RETURN(pCur)
  // iterate
  while(pCur->pNext != NULL){
    freeSubtreeWithoutData(pCur);
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }
  //free last leaf
  freeSubtreeWithoutData(pCur);
  free(pCur);
}