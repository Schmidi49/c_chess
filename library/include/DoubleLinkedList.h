/******************************************************************************
 * @file DoubleLinkedList.h
 * @author Erik Schmidthaler
 * @brief Header File for the Double Linked List data structure
 *
 * (C) Erik Schmidthaler (22.03.2024)
 */

#ifndef C_CHESS_DOUBLELINKEDLIST_H
#define C_CHESS_DOUBLELINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

/// @brief structure which contains a double linked list
typedef struct tDlList_List {
  struct tDlList_Node* pFirst; /// @brief pointer towards the first node, NULL if list is empty
  struct tDlList_Node* pLast; /// @brief pointer towards the last node, NULL if list is empty
} tDlList_List;

/// @brief internal node structure for a double linked list, shall only be held by a tDlList_List
typedef struct tDlList_Node {
  void* pData;                /// @brief data pointer
  struct tDlList_Node* pPrev; /// @brief pointer towards the previous node of the list, NULL if node is the first node
  struct tDlList_Node* pNext; /// @brief pointer towards the next node of the list, NULL if node is the last node
} tDlList_Node;

/// @brief callback function when visiting a list
/// @param pData data which gets visited
/// @param index number of the visited element
typedef void (*DlList_VisitorCB)(void* data, size_t index);
/// @brief comparator callback for finding, removing and extracting functions
/// @param pFirst first parameter to be compared
/// @param pSecond first parameter to be compared
typedef bool (*DlList_CompareCB)(void* pFirst, void* pSecond);

/// @brief allocates and initializes a new list
/// @return pointer to new list
tDlList_List* DlList_New(void);
/// @brief initializes a new list
/// @param pList pointer to the list which shall be initialized
void DlList_Init(tDlList_List* pList);

/// @brief pushes new, user allocated data to the back of the list
/// @param pList list pointer where to push back
/// @param pData data pointer which tom insert
/// @return node pointer where the data was inserted, NULL on failure
tDlList_Node* DlList_PushBack(tDlList_List* pList, void* pData);
/// @brief pushes new, user allocated data to the front of the list
/// @param pList list pointer where to push to the front
/// @param pData data pointer which tom insert
/// @return node pointer where the data was inserted, NULL on failure
tDlList_Node* DlList_PushFront(tDlList_List* pList, void* pData);

/// @brief pushes data to the back of the list, allocates memory and copies the data
/// @param pList list pointer where to copy back
/// @param n size of the data to push back
/// @param pData data pointer which gets copied
/// @return node pointer where the data was copied to, NULL on failure
tDlList_Node* DlList_CopyBack(tDlList_List* pList, size_t n, void* pData);
/// @brief pushes data into the front of the list, allocates memory and copies the data
/// @param pList list pointer where to copy to the front
/// @param n size of the data to push back
/// @param pData data pointer which gets copied
/// @return node pointer where the data was copied to, NULL on failure
tDlList_Node* DlList_CopyFront(tDlList_List* pList, size_t n, void* pData);

/// @brief creates a new node at the back of the list, automatically allocates data of various size
/// @param pList list pointer where to create a new node
/// @param n size of memory to allocate
/// @return node pointer where new data might be put in, NULL on failure
tDlList_Node* DlList_CreateBack(tDlList_List* pList, size_t n);
/// @brief creates a new node at the front of the list, automatically allocates data of various size
/// @param pList list pointer where to create a new node
/// @param n size of memory to allocate
/// @return node pointer where new data might be put in, NULL on failure
tDlList_Node* DlList_CreateFront(tDlList_List* pList, size_t n);

/// @brief frees the list, its nodes and all the data contained
/// @param pList list to be freed
void DlList_Free(tDlList_List* pList);
/// @brief frees the list, its nodes but not the data contained
/// @param pList list to be freed
void DlList_FreeWithoutData(tDlList_List* pList);

#endif //C_CHESS_DOUBLELINKEDLIST_H
