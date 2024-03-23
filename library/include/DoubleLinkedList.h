//
// Created by erik on 22.03.24.
//

#ifndef C_CHESS_DOUBLELINKEDLIST_H
#define C_CHESS_DOUBLELINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct DlList_List_s {
  struct DlList_Node_s* pFirst;
  struct DlList_Node_s* pLast;
} DlList_List_t;

typedef struct DlList_Node_s {
  void* pData;
  struct DlList_Node_s* pPrev;
  struct DlList_Node_s* pNext;
} DlList_Node_t;

typedef void (*DlList_VisitorCB_t)(void*, size_t);
typedef bool (*DlList_CompareCB_t)(void* pFirst, void* pSecond);

DlList_List_t* DlList_New(void);
void DlList_Init(DlList_List_t* pList);

DlList_Node_t* DlList_PushBack(DlList_List_t* pList, void* pData);

DlList_Node_t* DlList_PushFront(DlList_List_t* pList, void* pData);

DlList_Node_t* DlList_CopyBack(DlList_List_t* pList, size_t n, void* pData);

DlList_Node_t* DlList_CopyFront(DlList_List_t* pList, size_t n, void* pData);

DlList_Node_t* DlList_CreateBack(DlList_List_t* pList, size_t n);

DlList_Node_t* DlList_CreateFront(DlList_List_t* pList, size_t n);

void DlList_Free(DlList_List_t* pList);

void DlList_FreeWithoutData(DlList_List_t* pList);

#endif //C_CHESS_DOUBLELINKEDLIST_H
