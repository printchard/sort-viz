#include <raylib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sort.h"
#include "util.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define RECT_HEIGHT 800 - Y_PADDING * 2
#define X_PADDING 50
#define Y_PADDING 20

void fillRandomArray(int *vs, int num)
{
  for (int i = 0; i < num; i++)
  {
    vs[i] = i + 1;
  }

  for (int i = num; i > 0; i--)
  {
    int j = rand() % (i + 1);
    swap(vs, i, j);
  }
}

void drawRectangles(int *heights, Move m, int num, int h)
{
  float width = 2 * (SCREEN_WIDTH - X_PADDING * 2) / (float)(3 * num - 1);
  float x = X_PADDING;
  for (int i = 0; i < num; i++)
  {
    float height = h * (heights[i] / (float)RECT_NUM);
    float y = SCREEN_HEIGHT - height - Y_PADDING;
    if (m.i == i || m.j == i)
    {
      DrawRectangle(x, y, width, height, RED);
    }
    else
    {
      DrawRectangle(x, y, width, height, BLACK);
    }
    x += width * 1.5;
  }
}

int main()
{
  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "sorter");
  SetExitKey(KEY_Q);

  srand(time(NULL));
  int rs[RECT_NUM];
  int hs[RECT_NUM];
  fillRandomArray(hs, RECT_NUM);
  copyArr(hs, rs, RECT_NUM);

  bubbleSort(hs, RECT_NUM);

  int time = 0;
  int currStep = 0;
  while (!WindowShouldClose())
  {

    BeginDrawing();
    ClearBackground(WHITE);
    drawRectangles(rs, m[currStep], RECT_NUM, RECT_HEIGHT);
    EndDrawing();
    if (time % 120)
    {
      if (m[currStep].t == SWAP)
      {
        int temp = rs[m[currStep].i];
        rs[m[currStep].i] = rs[m[currStep].j];
        rs[m[currStep].j] = temp;
      }
      if (currStep < RECT_NUM * RECT_NUM)
        currStep++;
    }
    time++;
  }
  CloseWindow();

  return 0;
}