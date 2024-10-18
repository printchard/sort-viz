#include "sort.h"
#include "util.h"

Move m[RECT_NUM * RECT_NUM];

void bubbleSort(int *nums, int length)
{
  int step = 0;
  for (int i = 0; i < length - 1; i++)
  {
    for (int j = i + 1; j < length; j++)
    {
      m[step].i = i;
      m[step].j = j;
      m[step].t = COMP;
      step++;

      if (nums[i] > nums[j])
      {
        swap(nums, i, j);
        m[step].i = i;
        m[step].j = j;
        m[step].t = SWAP;
        step++;
      }
    }
  }
}