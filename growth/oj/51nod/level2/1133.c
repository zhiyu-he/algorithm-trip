#include <stdio.h>
#include <stdlib.h>

struct activity {
  long long st;
  long long et;
};

int N;

struct activity at[10001];
int book[10001];

int cmp (struct activity a1, struct activity a2);

void merge_sort (struct activity arr[], int start, int end);

void merge (struct activity a[], int start, int mid, int end);


int search (int n); 

int main()
{
  scanf ("%d", &N);
  int i;
  for (i = 1; i <= N; i++)
    {
      scanf ("%lld %lld", &at[i].st, &at[i].et);
    }
  merge_sort (at, 1, N);
  
  
  int room = search (N);
  
  printf ("%d\n", room + 1);
  //for (i = 1; i <= N; i++)
    //    printf ("st: %lld et: %lld\n", at[i].st, at[i].et);
  return 0;
}

int search (int n)
{
  long long end = at[1].et;
  
  int sum = 0;
  int i;
  for (i = 2; i <= n; i++)
    {
      if (at[i].st >= end)
        {
          sum++;
          end = at[i].et;
        }
    }
  return sum;
}


int cmp (struct activity a1, struct activity a2)
{
  if (a1.et > a2.et)
    return 1;
  else if (a1.et == a2.et)
    {
      if (a1.st > a2.st)
        return 1;
      else if (a1.st == a1.st)
        return 0;
      else
        return -1;
    }
  else
    return -1;
}

void merge_sort (struct activity arr[], int start, int end)
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

void merge (struct activity a[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  struct activity *l = (struct activity *) malloc (sizeof (struct activity) * l1);
  struct activity *r = (struct activity *) malloc (sizeof (struct activity) * l2);
  
  int i, j, k;
  for (i = 0; i < l1; i++)
    {
      l[i] = a[start + i];
    }
  for (i = 0; i < l2; i++)
    {
      r[i] = a[mid + i + 1];
    }
  i = j = 0;
  k = start;
  while (i < l1 && j < l2)
    {
      if (cmp (l[i], r[j]) == -1)
        a[k++] = l[i++];
      else
        a[k++] = r[j++];
    }

  while (i < l1)
    a[k++] = l[i++];
    
  while (j < l2)
    a[k++] = r[j++];

  free (l);
  free (r);
}
