#include <stdio.h>
#include <stdlib.h>

struct cirle {
  long left;
  long right;
};

struct cirle c_arr[50001];

int g_binary_search (struct cirle arr[], int begin, int end, long k, int len)
{
  if (arr[len].right < k)
    return -1;

  int low = begin;
  int high = end;
  while (low <= high)
    {
      int mid = low + ((high - low) >> 1);
      
      if (mid + 1 <= len && arr[mid].right < k && k <= arr[mid + 1].right)
        //        {
        //  printf ("mid: %d\n", mid);
          return mid;
      // }
      else if (arr[mid].right < k)
        low = mid + 1;
      else
        high = mid - 1;
    }
  return -1;
}

int cmp (struct cirle c1, struct cirle c2)
{
  /*
  if (c1.left > c2.left)
      return 1;
  else if (c1.left == c2.left)
    return c1.right >= c2.right ? 1 : -1;
  else
    return -1;
  */
  if (c1.right > c2.right)
    return 1;
  else
    return -1;
}

void merge (struct cirle arr[], int start, int mid, int end);

void merge_sort (struct cirle arr[], int start, int end);

int main()
{
  int N;
  scanf ("%d", &N);
  int i;
  for (i = 1; i <= N; i++)
    {
      long pos, r;
      scanf ("%ld %ld", &pos, &r);
      c_arr[i].left = pos - r;
      c_arr[i].right = pos + r;
    }
  
  merge_sort (c_arr, 1, N);
  
  int count = 0;
  for (i = 2; i <= N; i++)
    {
      int pos = g_binary_search (c_arr, 1, N, c_arr[i].left, N);
      if (pos > -1)
        count += pos;
    }
  /*  
   printf ("===========\n");
   for (i = 1; i <= N; i++)
     printf ("%ld %ld\n", c_arr[i].left, c_arr[i].right);
  */
  printf ("%d\n", count);
  return 0;
}


void merge_sort (struct cirle arr[], int start, int end)
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


void merge (struct cirle arr[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  struct cirle *l = (struct cirle *) malloc (sizeof (struct cirle) * l1);
  struct cirle *r = (struct cirle *) malloc (sizeof (struct cirle) * l2);

  int i, j, k;
  for (i = 0; i < l1; i++)
    l[i] = arr[i + start];
  
  for (j = 0; j < l2; j++)
    r[j] = arr[j + mid + 1];

  i = j = 0;
  k = start;
  while (i < l1 && j < l2)
    {
      if (cmp (l[i], r[j]) == 1) // l[i] > r[j]
        arr[k++] = r[j++];
      else
        arr[k++] = l[i++];
    }

  while (i < l1)
    arr[k++] = l[i++];
  
  while (j < l2)
    arr[k++] = r[j++];
  
  free (l);
  free (r);
}
