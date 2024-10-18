#ifndef SORT_H
#define SORT_H

#define RECT_NUM 10

typedef enum
{
  COMP,
  SWAP
} MoveType;

typedef struct
{
  MoveType t;
  int i, j;
} Move;

extern Move m[RECT_NUM * RECT_NUM];

void bubbleSort(int *nums, int length);

#endif