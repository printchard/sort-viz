#include <raylib.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define RECT_NUM 100
#define RECT_HEIGHT 800 - Y_PADDING * 2
#define X_PADDING 50
#define Y_PADDING 20

void generateRects(Rectangle *rects, int num, int h)
{
  float width = 2 * (SCREEN_WIDTH - X_PADDING * 2) / (float)(3 * RECT_NUM - 1);
  float x = X_PADDING;
  for (int i = 0; i < num; i++)
  {
    rects[i].x = x;
    rects[i].width = width;
    x += width * 1.5;
    rects[i].height = h;
    rects[i].y = SCREEN_HEIGHT - h - Y_PADDING;
  }
}

int main()
{
  Rectangle r[RECT_NUM];
  generateRects(r, RECT_NUM, RECT_HEIGHT);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "sorter");
  SetExitKey(KEY_Q);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    for (int i = 0; i < RECT_NUM; i++)
    {
      DrawRectangleRec(r[i], RED);
    }
    EndDrawing();
  }
  CloseWindow();

  return 0;
}