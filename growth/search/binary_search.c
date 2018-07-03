#include <stdio.h>

/*
 * 关于二分, 有几点需要注意的为
 * 1. 每次的搜索为[left, right]的闭区间, 以保证每次循环成立
 * 2. todo 关于离散数学与二分的证明
*/

/**
   检索[first, last] 之间的目标value
**/
int binary_search (int arr[], int first, int last, int value)
{
    if (arr == NULL) return -1;
  
    while (first <= last)
    {
        int mid = first + ((last - first) >> 1);    // 此处是为了避免在右边界的溢出
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

/**
   检索[first, last]之间的目标value
   返回最左的匹配
**/
int binary_search_left (int arr[],int first, int last, int value)
{
    if (arr == NULL) return -1;
  
    int index = -1;
  
    while (first <= last)
    {
        int mid = first + ((last - first) >> 1);
        if (arr[mid] == value)
        {
            index = mid;
            last = mid - 1;     // 为什么是修改last呢? 因为如果已经是最左侧的了,  则之后也会是最左侧的; 同时, 如果左侧还有value, 那么也应该将last = mid -1;
        }
        else if (arr[mid] > value)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return index;
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
  printf ("find 2: %d\n", binary_search_left (arr2, 0, len - 1, 2));
  printf ("find 4: %d\n", binary_search_left (arr2, 0, len - 1, 4));

  // 一个元素的临界值测试
  int arr3[] = {1};
  printf ("find 1: %d\n", binary_search (arr3, 0, 0, 1));
  printf ("find 2: %d\n", binary_search (arr3, 0, 0, 2));
  return 0;
}
