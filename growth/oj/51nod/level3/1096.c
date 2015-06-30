#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 10001


void merge (long long arr[], int start, int mid, int end);
void merge_sort (long long arr[], int start, int end);

long long P[MAX_SIZE];


int main()
{
  int i, N;
  scanf ("%d", &N);
  
  for (i = 1; i <= N; i++)
    scanf ("%lld", &P[i]);

  merge_sort (P, 1, N);

  int median_index = N % 2 != 0 ? (N + 1) / 2 : N / 2; // 兔子告诉偶，说直接N/2当中位数就好啦

  long long res = 0;
  
  i = 1;
  while (i < median_index)
    res += P[median_index] - P[i++];

  i = N;
  while (median_index < i)
    res += P[i--] - P[median_index];
  
  printf ("%lld\n", res);
  return 0;
}

void merge_sort (long long arr[], int start, int end)
{
  //  printf ("merge_sort start: %d end: %d mid: %d\n", start, end, mid);
  int mid = 0;
  if (start < end)
    {
      mid = start + (end - start) / 2;
      merge_sort (arr, start, mid);
      merge_sort (arr, mid + 1, end);
      merge (arr, start, mid, end);
    }
}

void merge (long long arr[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  long long *l = (long long *) malloc (sizeof (long long) * l1);
  long long *r = (long long *) malloc (sizeof (long long) * l2);
  
  int i, j, k;
  for (i = 0; i < l1; i++)
    l[i] = arr[i + start];
  
  for (j = 0; j < l2; j++)
    r[j] = arr[j + mid + 1];

  i = j = 0;
  k = start;
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
