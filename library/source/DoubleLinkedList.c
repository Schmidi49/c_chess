//
// Created by erik on 22.03.24.
//

#include "DoubleLinkedList.h"

#include <stdlib.h>
#include <string.h>

typedef DlList_List_t List_t;
typedef DlList_Node_t Node_t;

// --------------------
// forward declarations
// --------------------

// --------------------
// header function definitions
// --------------------
DlList_List_t* DlList_New(void){
  List_t* pNewList = malloc(sizeof(List_t));
  DlList_Init(pNewList);
  return pNewList;
}

void DlList_Init(DlList_List_t* pList){
  if(pList == NULL){
    return;
  }
  pList->pFirst = NULL;
  pList->pLast = NULL;
}

DlList_Node_t* DlList_PushBack(DlList_List_t* pList, void* pData){
  Node_t* pNewNode;
  if(pList == NULL){
    return NULL;
  }

  pNewNode = malloc(sizeof(Node_t));
  if(pNewNode == NULL){
    return NULL;
  }

  pNewNode->pData = pData;
  pNewNode->pPrev = pList->pLast;
  pNewNode->pNext = NULL;

  if(pList->pLast == NULL){
    pList->pLast = pNewNode;
    pList->pFirst = pNewNode;
    return pNewNode;
  }
  pList->pLast->pNext = pNewNode;
  pList->pLast = pNewNode;
  return pNewNode;
}

DlList_Node_t* DlList_PushFront(DlList_List_t* pList, void* pData){
  Node_t* pNewNode;
  if(pList == NULL){
    return NULL;
  }

  pNewNode = malloc(sizeof(Node_t));
  if(pNewNode == NULL){
    return NULL;
  }

  pNewNode->pData = pData;
  pNewNode->pNext = pList->pFirst;
  pNewNode->pPrev = NULL;

  if(pList->pFirst == NULL){
    pList->pFirst = pNewNode;
    pList->pLast = pNewNode;
    return pNewNode;
  }
  pList->pFirst->pPrev = pNewNode;
  pList->pFirst = pNewNode;
  return pNewNode;
}

DlList_Node_t* DlList_CopyBack(DlList_List_t* pList, size_t n, void* pData){
  Node_t* pNewNode = DlList_CreateBack(pList, n);
  if(pNewNode == NULL){
    return NULL;
  }
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

DlList_Node_t* DlList_CopyFront(DlList_List_t* pList, size_t n, void* pData){
  Node_t* pNewNode = DlList_CreateFront(pList, n);
  if(pNewNode == NULL){
    return NULL;
  }
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

DlList_Node_t* DlList_CreateBack(DlList_List_t* pList, size_t n){
  void* pNewData;
  Node_t * pCreatedNode;
  if(pList == NULL){
    return NULL;
  }

  //allocate memory
  pNewData = malloc(n);
  if(pNewData == NULL){
    return NULL;
  }

  //push back the created data
  pCreatedNode = DlList_PushBack(pList, pNewData);
  if(pCreatedNode == NULL){
    free(pNewData);
    return NULL;
  }
  return pCreatedNode;
}

DlList_Node_t* DlList_CreateFront(DlList_List_t* pList, size_t n){
  void* pNewData;
  Node_t * pCreatedNode;
  if(pList == NULL){
    return NULL;
  }

  //allocate memory
  pNewData = malloc(n);
  if(pNewData == NULL){
    return NULL;
  }

  //push back the created data
  pCreatedNode = DlList_PushFront(pList, pNewData);
  if(pCreatedNode == NULL){
    free(pNewData);
    return NULL;
  }
  return pCreatedNode;
}

void DlList_Free(DlList_List_t* pList){
  Node_t* pCur;
  if(pList == NULL){
    return;
  }

  pCur = pList->pFirst;
  if(pCur == NULL){
    return;
  }

  while(pCur->pNext != NULL){
    free(pCur->pData);
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }

  free(pCur->pData);
  free(pCur);
  free(pList);
}

void DlList_FreeWithoutData(DlList_List_t* pList){
  Node_t* pCur;
  if(pList == NULL){
    return;
  }

  pCur = pList->pFirst;
  if(pCur == NULL){
    return;
  }

  while(pCur->pNext != NULL){
    pCur = pCur->pNext;
    free(pCur->pPrev);
  }

  free(pCur);
  free(pList);
}

// --------------------
// internal function definitions
// --------------------