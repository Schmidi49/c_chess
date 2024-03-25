//
// Created by erik on 22.03.24.
//

#ifndef C_CHESS_DOUBLELINKEDLIST_H
#define C_CHESS_DOUBLELINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct tDlList_List {
  struct tDlList_Node* pFirst;
  struct tDlList_Node* pLast;
} tDlList_List;

typedef struct tDlList_Node {
  void* pData;
  struct tDlList_Node* pPrev;
  struct tDlList_Node* pNext;
} tDlList_Node;

typedef void (*DlList_VisitorCB)(void*, size_t);
typedef bool (*DlList_CompareCB)(void* pFirst, void* pSecond);

tDlList_List* DlList_New(void);
void DlList_Init(tDlList_List* pList);

tDlList_Node* DlList_PushBack(tDlList_List* pList, void* pData);

tDlList_Node* DlList_PushFront(tDlList_List* pList, void* pData);

tDlList_Node* DlList_CopyBack(tDlList_List* pList, size_t n, void* pData);

tDlList_Node* DlList_CopyFront(tDlList_List* pList, size_t n, void* pData);

tDlList_Node* DlList_CreateBack(tDlList_List* pList, size_t n);

tDlList_Node* DlList_CreateFront(tDlList_List* pList, size_t n);

void DlList_Free(tDlList_List* pList);

void DlList_FreeWithoutData(tDlList_List* pList);

#endif //C_CHESS_DOUBLELINKEDLIST_H
