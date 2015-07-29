#include <stdio.h>

#define MAX_SIZE 5 * 100000 + 1

long size[MAX_SIZE];

void quick_sort (long arr[], long i, long j)
{
  if (arr == NULL || i > j)
    return;
  long base = arr[i];
  long left = i;
  long right = j;
  while (left != right)
    {
      while (arr[right] > base && left < right)
        right--;
      while (arr[left] <= base && left < right)
        left++;

      if (left < right)
        {
          long temp = arr[left];
          arr[left] = arr[right];
          arr[right] = temp;
        }
    }
  
  // 处理base
  arr[i] = arr[left];
  arr[left] = base;

  quick_sort (arr, i, right - 1);
  quick_sort (arr, left + 1, j);
}


int main()
{
  long n;
  scanf ("%ld", &n);
  
  long i;
  for (i = 0; i < n; i++)
    scanf ("%ld", &size[i]);

  quick_sort (size, 0, n - 1);

  long count = 0;
  long start = n - 1;
  long tail = n / 2 - 1; // 理想情况即1-1配对
  while (tail >= 0)
    {
      if (size[start] >= size[tail] * 2)
        {
          count++;
          start--;
          tail--;
        }
      else
        tail--;
    }

  printf ("%ld\n", n - count);
  return 0;
}