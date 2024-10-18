#include <raylib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "sort.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define RECT_NUM 100
#define RECT_HEIGHT 800 - Y_PADDING * 2
#define X_PADDING 50
#define Y_PADDING 20

void fillRandomArray(int *vs, int num)
{
  for (int i = 0; i <= 100; i++)
  {
    vs[i] = i;
  }

  for (int i = 100; i > 0; i--)
  {
    int j = rand() % (i + 1);

    int temp = vs[i];
    vs[i] = vs[j];
    vs[j] = temp;
  }
}

void generateRects(Rectangle *rects, int *heights, int num, int h)
{
  float width = 2 * (SCREEN_WIDTH - X_PADDING * 2) / (float)(3 * RECT_NUM - 1);
  float x = X_PADDING;
  for (int i = 0; i < num; i++)
  {
    rects[i].x = x;
    rects[i].width = width;
    x += width * 1.5;
    rects[i].height = h * (heights[i] / 100.0);
    rects[i].y = SCREEN_HEIGHT - (h * (heights[i] / 100.0)) - Y_PADDING;
  }
}

void printValues(int *nums, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", nums[i]);
  }
}

int main()
{
  srand(time(NULL));
  Rectangle rs[RECT_NUM];
  int hs[RECT_NUM];
  fillRandomArray(hs, RECT_NUM);
  generateRects(rs, hs, RECT_NUM, RECT_HEIGHT);
  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "sorter");
  SetExitKey(KEY_Q);

  int time = 0;
  int select = 0;
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    for (int i = 0; i < RECT_NUM; i++)
    {
      if (select == i)
      {
        DrawRectangleRec(rs[i], RED);
        continue;
      }

      DrawRectangleRec(rs[i], BLACK);
    }
    EndDrawing();
    if (time % 30 == 0)
    {
      select++;
    }
    if (time == 60)
    {
      bubbleSort(hs, RECT_NUM);
      generateRects(rs, hs, RECT_NUM, RECT_HEIGHT);
      time = 0;
    }
    time++;
  }
  CloseWindow();

  return 0;
}