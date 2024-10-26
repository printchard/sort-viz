#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void copyArr(int *src, int *dest, int length)
{
  for (int i = 0; i < length; i++)
    dest[i] = src[i];
}

void printValues(int *nums, int length)
{
  printf("[ ");
  for (int i = 0; i < length; i++)
  {
    if (i != length - 1)
      printf("%d, ", nums[i]);
    else
      printf("%d", nums[i]);
  }
  printf("]\n");
}

void fillRandomArray(int *vs, int num)
{
  for (int i = 0; i < num; i++)
  {
    vs[i] = i + 1;
  }

  for (int i = num - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);
    swap(vs, i, j);
  }
}