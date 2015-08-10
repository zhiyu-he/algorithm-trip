#include <stdio.h>
#include <stdlib.h>

/**
   归并排序，分为`拆分`与`合并`两个步骤
   其中合并为O(n)拆分为O(logn)
   整体复杂度为O(nlogn)
   
   merge_sort: 切分
   merge: 合并
 **/


void merge (int arr[], int first, int mid, int end)
{
  int l1 = mid - first + 1;
  int l2 = end - mid;

  int *l = (int *) malloc (sizeof (int) * l1);
  int *r = (int *) malloc (sizeof (int) * l2);
  
  int i, j, k;
  for (i = 0; i < l1; i++)
    l[i] = arr[first + i];
  for (i = 0; i < l2; i++)
    r[i] = arr[mid + i + 1];

  // init 初始化
  i = 0;
  j = 0;
  k = first;
  while (i < l1 && j < l2)
    {
      if (l[i] < r[j])
        arr[k++] = l[i++];
      else
        arr[k++] = r[j++];
    }

  while (i < l1)
    arr[k++] = l[i++];
  while (j < l2)
    arr[k++] = r[j++];
  
  free (l);
  free (r);
}

void merge_sort (int arr[], int first, int end)
{
  int mid;
  if (first < end)
    {
      mid = first + ((end - first) >> 1);
      merge_sort (arr, first, mid);
      merge_sort (arr, mid + 1, end);
      merge (arr, first, mid, end);      
    }
}

int main()
{
  int arr1[] = { 10, 3, 2, 1, 4 };

  merge_sort (arr1, 0, 4);

  int i = 0;
  for (i = 0; i < 5; i++)
    printf ("%d ", arr1[i]);

  printf ("\n==============\n");
  
  int arr2[] = { 1 };
  
  merge_sort (arr2, 0, 0);
  
  for (i = 0; i < 1; i++)
    printf ("%d ", arr2[i]);

  
  return 0;
}
