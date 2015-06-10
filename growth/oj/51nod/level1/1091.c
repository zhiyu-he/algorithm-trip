#include <stdio.h>
#include <stdlib.h>

struct line {
  long long start;
  long long end;
};

void merge (struct line arr[], long begin, long mid, long end);

void divide(struct line arr[], long begin, long end);

int cmp (struct line a, struct line b)
{
  if (a.start < b.start)
    return -1;
  else if (a.start == b.start)
    return a.end <= b.end ? -1 : 1;
  else
    return 1;
}

int main()
{
  int n;
  scanf ("%d", &n);
  
  struct line *arr = (struct line *) malloc (sizeof (struct line) * (n + 1));
  
  int i, j;
  for (i = 1; i <= n; i++)
    scanf ("%lld %lld", &arr[i].start, &arr[i].end);

  divide(arr, 1, n); 
  
  long long max = 0;
  long long far_end = arr[1].end;
  for (i = 2; i <= n; i++)
    {
      long long overlap = 0;

      if (arr[i].end <= far_end)
        {
          overlap = arr[i].end - arr[i].start;
        }
      else
        {
          overlap = far_end - arr[i].start;
          far_end = arr[i].end;
        }
      if (overlap > max)
        max = overlap;
    }
  //  for (i = 1; i <=n; i++)
  //  printf ("%lld %lld\n", arr[i].start, arr[i].end);
  printf ("%lld\n", max);
  return 0;
}


void merge(struct line arr[], long begin, long mid, long end)
{
  long n1 = mid - begin + 1;
  long n2 = end - mid;

  struct line *l1 = (struct line *) malloc (sizeof (struct line) * n1);
  struct line *l2 = (struct line *) malloc (sizeof (struct line) * n2);
  
  long i, j, k;
  for (i = 0; i < n1; i++)
    {
      l1[i].start = arr[begin + i].start;
      l1[i].end = arr[begin + i].end;
    }
  for (j = 0; j < n2; j++)
    {
      l2[j].start = arr[mid + 1 + j].start;
      l2[j].end = arr[mid + 1 + j].end;
    }
  
  i = j = 0;
  k = begin;
  while (i < n1 && j < n2)
    {
      if (cmp(l1[i], l2[j]) == -1)
        {
          arr[k++] = l1[i++];
        } 
      else 
        {
          arr[k++] = l2[j++];
        }
    }
  while (i < n1)
    {
      arr[k++] = l1[i++];
    }
  while (j < n2)
    {
      arr[k++] = l2[j++];
    }

  free(l1);
  free(l2);
}


void divide(struct line arr[], long begin, long end)
{
  long mid;
  if (begin < end)
    {
      mid = begin + (end - begin) / 2;
      divide (arr, begin, mid);
      divide (arr, mid + 1, end);
      merge (arr, begin, mid, end);
    }
}
