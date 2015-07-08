#include <stdio.h>
#include <stdlib.h>

struct task {
  long long r; // 执行
  long long o; // 存储
};

struct task arr[100001];


void merge (struct task arr[], int start, int mid, int end);
void merge_sort (struct task arr[], int start, int end);


int cmp (struct task t1, struct task t2)
{
  /*
  if (t1.o > t2.o)
    return 1;
  else if (t1.o == t2.o)
    return t1.r < t2.r ? 1 : 0;
  else
    return -1;
  */
  long long v1 = t1.r - t1.o;
  long long v2 = t2.r - t2.o;
  return v1 > v2 ? 0 : 1;
}

int main()
{
  int i, N;
  scanf ("%d", &N);
  long long a_s = 0, store = 0; // 可用执行空间: a_s     存储空间: store
  for (i = 1; i <= N; i++)
    scanf ("%lld %lld", &arr[i].r, &arr[i].o);
  merge_sort (arr, 1, N);

  /*
  for (i = 1; i <= N; i++)
    printf ("r: %lld o: %lld\n", arr[i].r, arr[i].o);
  printf ("====\n");
  */

  for (i = 1; i <= N; i++)
    {
      if (arr[i].r > a_s)
        {
          // 申请空间
          a_s += arr[i].r - a_s;
          a_s -= arr[i].o;
          store += arr[i].o;
        }
      else
        {
          a_s -= arr[i].o;
          store += arr[i].o;
        }
    }

  printf ("%lld\n", a_s + store);
  return 0;
}


void merge_sort (struct task arr[], int start, int end)
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

void merge (struct task arr[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  struct task *l = (struct task *) malloc (sizeof (struct task) * l1);
  struct task *r = (struct task *) malloc (sizeof (struct task) * l2);
  
  int i, j, k;
  for (i = 0; i < l1; i++)
    l[i] = arr[i + start];

  for (j = 0; j < l2; j++)
    r[j] = arr[j + mid + 1];

  i = j = 0, k = start;
  
  while (i < l1 && j < l2)
    {
      if (cmp (l[i], r[j]) <= 0)
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
