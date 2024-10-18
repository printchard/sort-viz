#include "sort.h"

Move m[RECT_NUM * RECT_NUM];

void bubbleSort(int *nums, int length)
{
  int step = 0;
  for (int i = 0; i < length - 1; i++)
  {
    for (int j = i; j < length; j++)
    {
      m[step].i = i;
      m[step].j = j;
      m[step].t = COMP;
      step++;

      if (nums[i] > nums[j])
      {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        m[step].i = i;
        m[step].j = j;
        m[step].t = SWAP;
        step++;
      }
    }
  }
}