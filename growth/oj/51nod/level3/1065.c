#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 50001

struct sum {
  int i;
  long long value;
};

void merge_sort (struct sum arr[], int start, int end);

void merge (struct sum arr[], int start, int mid, int end);

struct sum A[MAX_SIZE];

long long min = LONG_LONG_MAX;

int main()
{
  int i, n;
  scanf ("%d", &n);
  
  for (i = 1; i <= n; i++)
    {
      long long temp;
      scanf ("%lld", &temp);
      if (i == 1)
        {
          A[i].i = i;
          A[i].value = temp;
        }
      else
        {
          A[i].i = i;
          A[i].value = A[i - 1].value + temp;
        }
    }

  merge_sort (A, 1, n);

  for (i = 1; i <= n; i++)
    {
       min = A[i].value > 0 && min > A[i].value ? A[i].value : min;
       if (i > 1 && A[i].i > A[i - 1].i)
        {
          long long temp = A[i].value - A[i - 1].value;
          min = min > temp ? temp : min;
        }
    }
  
  printf ("%lld\n", min);
  return 0;
}


void merge_sort (struct sum arr[], int start, int end)
{
  int mid;
  if (start < end)
    {
      mid = start + (end - start) / 2;
      merge_sort (arr, start, mid);
      merge_sort (arr, mid + 1, end);
      merge (arr, start, mid, end);
    }
}

void merge (struct sum arr[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  struct sum *l = (struct sum *) malloc (sizeof (struct sum) * l1);
  struct sum *r = (struct sum *) malloc (sizeof (struct sum) * l2);

  int i, j, k;
  
  for (i = 0; i < l1; i++)
    l[i] = arr[i + start];
  
  for (j = 0; j < l2; j++)
    r[j] = arr[j + mid + 1];

  i = j = 0;
  k = start;
  while (i < l1 && j < l2)
    {
      if (l[i].value < r[j].value)
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
