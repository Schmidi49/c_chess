/******************************************************************************
 * @file DoubleLinkedList.c
 * @author Erik Schmidthaler
 * @brief Source File for the Double Linked List data structure
 *
 * (C) Erik Schmidthaler (22.03.2024)
 */

#include "DoubleLinkedList.h"
#include "Macros.h"

#include <stdlib.h>
#include <string.h>

typedef tDlList_List tList;
typedef tDlList_Node tNode;

// --------------------
// forward declarations
// --------------------

// --------------------
// header function definitions
// --------------------
tList* DlList_New(void){
  //allocate memory
  tList* pNewList;
  ALLOC(pNewList, sizeof(tList))
  //initialize list
  DlList_Init(pNewList);
  return pNewList;
}

void DlList_Init(tList* pList){
  if(pList == NULL){
    return;
  }
  //indicate an empty list
  pList->pFirst = NULL;
  pList->pLast = NULL;
}

tNode* DlList_PushBack(tList* pList, void* pData){
  tNode* pNewNode;
  IF_NULL_RETURN_NULL(pList)
  pNewNode = malloc(sizeof(tNode));
  IF_NULL_RETURN_NULL(pNewNode)

  //initialize new node
  pNewNode->pData = pData;
  pNewNode->pPrev = pList->pLast;
  pNewNode->pNext = NULL;

  //special case if list is empty
  if(pList->pLast == NULL){
    pList->pLast = pNewNode;
    pList->pFirst = pNewNode;
    return pNewNode;
  }
  //normal pointer relinking
  pList->pLast->pNext = pNewNode;
  pList->pLast = pNewNode;
  return pNewNode;
}

tNode* DlList_PushFront(tList* pList, void* pData){
  tNode* pNewNode;
  IF_NULL_RETURN_NULL(pList)

  pNewNode = malloc(sizeof(tNode));
  IF_NULL_RETURN_NULL(pNewNode)

  //initialize new node
  pNewNode->pData = pData;
  pNewNode->pNext = pList->pFirst;
  pNewNode->pPrev = NULL;

  //special case if list is empty
  if(pList->pFirst == NULL){
    pList->pFirst = pNewNode;
    pList->pLast = pNewNode;
    return pNewNode;
  }
  //normal pointer relinking
  pList->pFirst->pPrev = pNewNode;
  pList->pFirst = pNewNode;
  return pNewNode;
}

tNode* DlList_CopyBack(tList* pList, size_t n, void* pData){
  tNode* pNewNode = DlList_CreateBack(pList, n);
  IF_NULL_RETURN_NULL(pNewNode)

  //copy data
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

tNode* DlList_CopyFront(tList* pList, size_t n, void* pData){
  tNode* pNewNode = DlList_CreateFront(pList, n);
  IF_NULL_RETURN_NULL(pNewNode)

  //copy data
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

tNode* DlList_CreateBack(tList* pList, size_t n){
  void* pNewData;
  tNode * pCreatedNode;
  IF_NULL_RETURN_NULL(pList)

  //allocate memory
  pNewData = malloc(n);
  IF_NULL_RETURN_NULL(pList)

  //push back the created data
  pCreatedNode = DlList_PushBack(pList, pNewData);
  if(pCreatedNode == NULL){
    free(pNewData);
    return NULL;
  }
  return pCreatedNode;
}

tNode* DlList_CreateFront(tList* pList, size_t n){
  void* pNewData;
  tNode * pCreatedNode;
  IF_NULL_RETURN_NULL(pList)

  //allocate memory
  pNewData = malloc(n);
  IF_NULL_RETURN_NULL(pNewData)

  //push back the created data
  pCreatedNode = DlList_PushFront(pList, pNewData);
  if(pCreatedNode == NULL){
    free(pNewData);
    return NULL;
  }
  return pCreatedNode;
}

void DlList_Free(tList* pList){
  tNode* pCur;
  IF_NULL_RETURN(pList)
  pCur = pList->pFirst;
  IF_NULL_RETURN(pCur)

  //iterate threw elements
  while(pCur->pNext != NULL){
    free(pCur->pData);
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }

  //free last element
  free(pCur->pData);
  free(pCur);
  free(pList);
}

void DlList_FreeWithoutData(tList* pList){
  tNode* pCur;
  IF_NULL_RETURN(pList)
  pCur = pList->pFirst;
  IF_NULL_RETURN(pCur)

  //iterate threw elements
  while(pCur->pNext != NULL){
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }

  //free last element
  free(pCur);
  free(pList);
}

// --------------------
// internal function definitions
// --------------------