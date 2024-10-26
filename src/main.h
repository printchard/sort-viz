#ifndef MAIN_H
#define MAIN_H

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define X_PADDING 50
#define Y_PADDING 20
#define RECT_HEIGHT 800 - Y_PADDING * 2
#define RECT_NUM 10

typedef enum MoveType
{
  COMP,
  SWAP
} MoveType;

typedef struct Move
{
  MoveType t;
  int i, j;
} Move;

extern Move m[RECT_NUM * RECT_NUM];

#endif