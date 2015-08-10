#include <stdio.h>

/**
   检索[first, last] 之间的目标value
**/
int binary_search (int arr[], int first, int last, int value)
{
  if (arr == NULL) return -1;
  
  while (first <= last)
    {
      int mid = first + ((last - first) >> 1); // 此处涉及到运算效率，TODO: 了解一下底层的运算起实现
      if (arr[mid] == value)
        return mid;
      else if (arr[mid] > value)
        last = mid - 1;
      else
        first = mid + 1;
    }
  return -1;
}

int main()
{
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  printf ("base test: \n");
  printf ("find 10: %d\n", binary_search (arr1, 0, 10, 10));
  printf ("find -1: %d\n", binary_search (arr1, 0, 10, -1));

  int arr2[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 7};
  int len = sizeof (arr2) / sizeof (int);
  
  // todo 当具有重复元素时候的 边界考虑
  printf ("find 2: %d\n", binary_search (arr2, 0, len - 1, 2));
  printf ("find 4: %d\n", binary_search (arr2, 0, len - 1, 4));

  // 一个元素的临界值测试
  int arr3[] = {1};
  printf ("find 1: %d\n", binary_search (arr3, 0, 0, 1));
  printf ("find 2: %d\n", binary_search (arr3, 0, 0, 2));
  return 0;
}
