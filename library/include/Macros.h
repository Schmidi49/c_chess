/******************************************************************************
 * @file Macros.h
 * @author Erik Schmidthaler
 * @brief Header file containing useful macros regarding pointers and memory management
 *
 * (C) Erik Schmidthaler (24.03.2024)
 */

#ifndef C_CHESS_MACROS_H
#define C_CHESS_MACROS_H

#include <stddef.h>

#define IF_NULL_RETURN(p) if(p == NULL){return;}
#define IF_NULL_RETURN_NULL(p) if(p == NULL){return NULL;}
#define IF_NULL_RETURN_VAL(p, val) if(p == NULL){return val;}

#define ALLOC(p)  p = malloc(sizeof &p); IF_NULL_RETURN_NULL(p)


#endif //C_CHESS_MACROS_H
