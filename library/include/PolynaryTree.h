//
// Created by erik on 21.03.24.
//

#ifndef C_CHESS_POLYNARYTREE_H
#define C_CHESS_POLYNARYTREE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct PolyTree_Node_s {
  void* pData;
  struct PolyTree_Node_s* pFirst;
  struct PolyTree_Node_s* pLast;
  struct PolyTree_Node_s* pPrev;
  struct PolyTree_Node_s* pNext;
} PolyTree_Node_t;

typedef void (*PolyTree_VisitorCB_t)(void*, size_t);
typedef bool (*PolyTree_CompareCB_t)(void* pFirst, void* pSecond);

PolyTree_Node_t* PolyTree_New(void* pData);
void PolyTree_Init(PolyTree_Node_t* pRoot, void* pData);

PolyTree_Node_t* PolyTree_PushBack(PolyTree_Node_t* pRoot, void* pData);
size_t PolyTree_PushBackHorizontal(PolyTree_Node_t* pRoot, size_t count, ...);
size_t PolyTree_PushBackVertical(PolyTree_Node_t* pRoot, size_t count, ...);

PolyTree_Node_t* PolyTree_CopyBack(PolyTree_Node_t* pRoot, size_t n, void* pData);
size_t PolyTree_CopyBackHorizontal(PolyTree_Node_t* pRoot, size_t n, size_t count, ...);
size_t PolyTree_CopyBackVertical(PolyTree_Node_t* pRoot, size_t n, size_t count, ...);

PolyTree_Node_t* PolyTree_CreateBack(PolyTree_Node_t* pRoot, size_t n);

void PolyTree_VisitPreOrder(PolyTree_Node_t* pRoot, PolyTree_VisitorCB_t visitor);
void PolyTree_VisitPreOrderDepth(PolyTree_Node_t* pRoot, PolyTree_VisitorCB_t visitor, size_t depth);

PolyTree_Node_t* PolyTree_FindLaterally(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);

//void PolyTree_Remove(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);
//void* PolyTree_RemoveWithoutData(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);
//PolyTree_Node_t* PolyTree_Extract(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);

void PolyTree_Free(PolyTree_Node_t* pRoot);
void PolyTree_FreeWithoutData(PolyTree_Node_t* pRoot);


#endif //C_CHESS_POLYNARYTREE_H
