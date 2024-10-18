#include "util.h"

void swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = arr[i];
}

void copyArr(int *src, int *dest, int length)
{
  for (int i = 0; i < length; i++)
  {
    dest[i] = src[i];
  }
}

void printValues(int *nums, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", nums[i]);
  }
}