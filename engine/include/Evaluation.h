//
// Created by erik on 29.03.24.
//

#ifndef C_CHESS_EVALUATION_H
#define C_CHESS_EVALUATION_H

#define NO_WIN_BIT (1 << ((sizeof(int) * 8) - 1))
#define NO_WIN(pEval) (NO_WIN_BIT & pFirst->mateIn)
#define EVAL_UINT(i) (*(unsigned int*)(&(i)))

typedef struct tEvaluation{
  int mateIn;
  int eval;
} tEvaluation;

bool Evaluation_GT(tEvaluation* pFirst, tEvaluation* pSecond);
bool Evaluation_ST(tEvaluation* pFirst, tEvaluation* pSecond);
bool Evaluation_EQ(tEvaluation* pFirst, tEvaluation* pSecond);

int Evaluation_Comp(tEvaluation* pFirst, tEvaluation* pSecond);

#endif //C_CHESS_EVALUATION_H
