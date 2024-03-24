/******************************************************************************
 * @file PolynaryTree.h
 * @author Erik Schmidthaler
 * @brief Header File for the Polynary Tree data structure
 *
 * (C) Erik Schmidthaler (21.03.2024)
 */

#ifndef C_CHESS_POLYNARYTREE_H
#define C_CHESS_POLYNARYTREE_H

#include <stddef.h>
#include <stdbool.h>

/// @brief strcuture for a Polynary Tree, contains the Linked List and the Tree structures in it.
/// Represents root and leaf alike
/// @note pPrev and pNext shall only be used from the Node in the next higher layer, they are only thought to iterate
/// threw the many brnaches of a root node
typedef struct PolyTree_Node_s {
  void* pData;                    /// @brief data pointer
  struct PolyTree_Node_s* pFirst; /// @brief pointer to the first leaf
  struct PolyTree_Node_s* pLast;  /// @brief pointer to the last leaf
  struct PolyTree_Node_s* pPrev;  /// @brief pointer to th prev leaf of the leaf structure of the overlying root
  struct PolyTree_Node_s* pNext;  /// @brief pointer to th next leaf of the leaf structure of the overlying root
} PolyTree_Node_t;

/// @brief callback function when visiting a tree
/// @param pData data which gets visited
/// @param depth depth inside the tree of the currently visited node
typedef void (*PolyTree_VisitorCB_t)(void* pData, size_t depth);
/// @brief comparator callback for finding, removing and extracting functions
/// @param pFirst first parameter to be compared
/// @param pSecond first parameter to be compared
typedef bool (*PolyTree_CompareCB_t)(void* pFirst, void* pSecond);

/// @brief allocates a new tree root
/// @param pData data to be attached to the root
/// @return root pointer or NULL on failure
PolyTree_Node_t* PolyTree_New(void* pData);
/// @brief initializes the data of a tree node/root
/// @param pRoot root to be initialized
/// @param pData data to be attached
void PolyTree_Init(PolyTree_Node_t* pRoot, void* pData);

/// @brief pushes back data to a new leaf of the root. memory has to be user allocated
/// @param pRoot root pointer to which to push back a new leave
/// @param pData data pointer to be pushed back
/// @return new node pointer on success, NULL on failure
PolyTree_Node_t* PolyTree_PushBack(PolyTree_Node_t* pRoot, void* pData);
/// @brief pushes back multiple data, data gets attached to the same root horizontally. memory has to be user allocated
/// @param pRoot root pointer to which to push back a new leave
/// @param count number of arguments to be attached
/// @param ... count arguments of type void*
/// @return number of failed insertions, therefore 0 on success
size_t PolyTree_PushBackHorizontal(PolyTree_Node_t* pRoot, size_t count, ...);
/// @brief pushes back multiple data, each new leaf is the root of the next leaf,
/// therefore inserting horizontally down the tree. memory has to be user allocated
/// @param pRoot root pointer to which to push back a new leave
/// @param count number of arguments to be attached
/// @param ... count arguments of type void*
/// @return number of failed insertions, therefore 0 on success
size_t PolyTree_PushBackVertical(PolyTree_Node_t* pRoot, size_t count, ...);

/// @brief creates a new leaf, allocates memory for the data and copies it to the node
/// @param pRoot root pointer where to insert
/// @param n size of data to allocate
/// @param pData data which gets copied to the new node
/// @return new node pointer on success, NULL on failure
PolyTree_Node_t* PolyTree_CopyBack(PolyTree_Node_t* pRoot, size_t n, void* pData);
/// @brief creates new leafs to the same node horizontally, allocates memory for it and copies the data to the node
/// @param pRoot root pointer to which to push back a new leave
/// @param n size of data to allocate
/// @param count number of arguments to be attached
/// @param ... count arguments of type void*, get copied to the new leafs
/// @return number of failed insertions, therefore 0 on success
size_t PolyTree_CopyBackHorizontal(PolyTree_Node_t* pRoot, size_t n, size_t count, ...);
/// @brief each new leaf is the root of the next leaf therefore inserting vertically,
/// allocates memory for each and copies the data to the node
/// @param pRoot root pointer to which to push back a new leave
/// @param n size of data to allocate
/// @param count number of arguments to be attached
/// @param ... count arguments of type void*, get copied to the new leafs
/// @return number of failed insertions, therefore 0 on success
size_t PolyTree_CopyBackVertical(PolyTree_Node_t* pRoot, size_t n, size_t count, ...);

/// @brief Creates a new node at the end of the roots branches, allocates memory for data
/// @param pRoot root pointer
/// @param n size of the memory to be allocated
/// @return new node pointer on success, NULL on failure
PolyTree_Node_t* PolyTree_CreateBack(PolyTree_Node_t* pRoot, size_t n);

/// @brief visits all nodes of tree, always root before the leafs
/// @param pRoot root pointer
/// @param visitor visitor callback which gets called with each nodes data and depth
void PolyTree_VisitPreOrder(PolyTree_Node_t* pRoot, PolyTree_VisitorCB_t visitor);
/// @brief visits all nodes of tree, always root before the leafs. starts with a not default depth
/// @param pRoot root pointer
/// @param visitor visitor callback which gets called with each nodes data and depth
/// @param depth starting depth
void PolyTree_VisitPreOrderDepth(PolyTree_Node_t* pRoot, PolyTree_VisitorCB_t visitor, size_t depth);

/// @brief finds the first node only in the leafs of the root node (does not search recursively)
/// @note if no compare function is passed, the default compare is by the pointers addresses themself
/// @param pRoot root pointer
/// @param pItem data with which to compare
/// @param comp custom comparator callback
/// @return first found node pointer, NULL if nothing was found
PolyTree_Node_t* PolyTree_FindLaterally(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);

//functions to be implemented soon
//void PolyTree_Remove(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);
//void* PolyTree_RemoveWithoutData(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);
//PolyTree_Node_t* PolyTree_Extract(PolyTree_Node_t* pRoot, void* pItem, PolyTree_CompareCB_t comp);

/// @brief frees the allocated data and nodes of a tree
/// @param pRoot tree pointer to be freed
void PolyTree_Free(PolyTree_Node_t* pRoot);
/// @brief frees the nodes, but not the data of a tree
/// @param pRoot tree pointer to be freed
void PolyTree_FreeWithoutData(PolyTree_Node_t* pRoot);


#endif //C_CHESS_POLYNARYTREE_H
