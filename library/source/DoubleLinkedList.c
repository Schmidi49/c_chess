//
// Created by erik on 22.03.24.
//

#include "DoubleLinkedList.h"

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
  tList* pNewList = malloc(sizeof(tList));
  DlList_Init(pNewList);
  return pNewList;
}

void DlList_Init(tList* pList){
  if(pList == NULL){
    return;
  }
  pList->pFirst = NULL;
  pList->pLast = NULL;
}

tNode* DlList_PushBack(tList* pList, void* pData){
  tNode* pNewNode;
  if(pList == NULL){
    return NULL;
  }

  pNewNode = malloc(sizeof(tNode));
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

tNode* DlList_PushFront(tList* pList, void* pData){
  tNode* pNewNode;
  if(pList == NULL){
    return NULL;
  }

  pNewNode = malloc(sizeof(tNode));
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

tNode* DlList_CopyBack(tList* pList, size_t n, void* pData){
  tNode* pNewNode = DlList_CreateBack(pList, n);
  if(pNewNode == NULL){
    return NULL;
  }
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

tNode* DlList_CopyFront(tList* pList, size_t n, void* pData){
  tNode* pNewNode = DlList_CreateFront(pList, n);
  if(pNewNode == NULL){
    return NULL;
  }
  memcpy(pNewNode->pData, pData, n);
  return pNewNode;
}

tNode* DlList_CreateBack(tList* pList, size_t n){
  void* pNewData;
  tNode * pCreatedNode;
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

tNode* DlList_CreateFront(tList* pList, size_t n){
  void* pNewData;
  tNode * pCreatedNode;
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

void DlList_Free(tList* pList){
  tNode* pCur;
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

void DlList_FreeWithoutData(tList* pList){
  tNode* pCur;
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