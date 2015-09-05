#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200002

long a[MAX_SIZE];

void merge (long arr[], long start, long mid, long end)
{
  long len_l = mid - start + 1;
  long len_r = end - mid;

  long *l = (long *) malloc (sizeof (long) * len_l);
  long *r = (long *) malloc (sizeof (long) * len_r);
  
  long i, j, k;
  for (i = 0; i < len_l; i++)
    l[i] = arr[start + i];
  
  for (i = 0; i < len_r; i++)
    r[i] = arr[mid + 1 + i];

  i = 0;
  j = 0;
  k = start;

  while (i < len_l && j < len_r)
    {
      if (l[i] < r[j])
        arr[k++] = l[i++];
      else
        arr[k++] = r[j++];
    }

  while (i < len_l)
    arr[k++] = l[i++];
  
  while (j < len_r)
    arr[k++] = r[j++];

  free (l);
  free (r);
  
}

void merge_sort (long arr[], long start, long end)
{
  long mid = 0;
  if (start < end)
    {
      mid = start + ((end - start) >> 1);
      merge_sort (arr, start, mid);
      merge_sort (arr, mid + 1, end);
      merge (arr, start, mid, end);
    }
}

void quick_sort (long arr[], long i, long j)
{
  if (arr == NULL || i > j)
    return;
  long left = i;
  long right = j;
  long base = arr[i];
  
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
  arr[i] = arr[left];
  arr[left] = base;

  quick_sort (arr, i, right - 1);
  quick_sort (arr, left + 1, j);
}

/**
   指向第一个不小于给定value的元素
 */
long lower_bound (long arr[], long first, long last, long value)
{
  if (arr == NULL) return -1;

  long index = -1;
  
  while (first <= last)
    {
      long mid = first + ((last - first) >> 1);
      if (arr[mid] == value)
        {
          last = mid - 1;
        }
      else if (arr[mid] > value)
        {
          last = mid - 1;
        }
      else
        {
          first = mid + 1;
          index = mid;
        }
    }

  return index;
}

int main()
{
  long n;
  scanf ("%ld", &n);
  long i;
  for (i = 0; i < n; i++)
    scanf ("%ld", &a[i]);
  
  //  quick_sort (a, 0, n - 1);
  merge_sort (a, 0, n - 1);

  //  for (i = 0; i < n ;i++)
  //    printf ("%ld ", a[i]);
  /*
  long arr[] = {1, 2, 3, 3, 3, 5, 8};
  
    case for test lower_bound

  for (i = 1; i <= 10; i++)
    {
      long index = lower_bound (arr, 0, 6, i);
      if (index < 0)
        printf ("do not find lower element\n");
      else
        printf ("search for %d.  result: index = %ld, arr[%ld] = %ld\n", i, index, index, arr[index]);
    }
  */
  
  long max_mod = 0;
  long mod = 0;
  for (i = 0; i < n - 1; i++)
    {
      long threshold = a[i] * 2;
      while (threshold <= a[n - 1])
        {
          long index = lower_bound (a, 0, n - 1, threshold);
          if (index > 0)
            {
              mod = a[index] % a[i];
              max_mod = max_mod < mod ? mod : max_mod;
              if (mod == a[i] - 1)
                break;
            }
          threshold += a[i]; // 再次扩大
        }
      mod = a[n - 1] % a[i];
      max_mod = max_mod< mod ?mod : max_mod;
    }
  printf ("%ld\n", max_mod);
  return 0;
}
