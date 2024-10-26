#include <stdio.h>
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