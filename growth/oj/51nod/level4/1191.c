#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50001

struct arrow {
  long d;
  long q;
};

struct arrow arr[MAX_SIZE];
long B[MAX_SIZE];


int queue_size = 0;

struct arrow priority_queue[MAX_SIZE];

void min_down (struct arrow arr[], int i, int n);
void min_up (struct arrow arr[], int i, int n);
long min_del (struct arrow arr[]);


void merge_arrow (struct arrow arr[], int start, int mid, int end, int (* cmp)(struct arrow, struct arrow));
void merge_sort_arrow (struct arrow arr[], int start, int end, int (* cmp)(struct arrow, struct arrow));

void merge_b (long arr[], int start, int mid, int end);
void merge_sort_b (long arr[], int start, int end);



int cmp1 (struct arrow a1, struct arrow a2)
{
  if (a1.d > a2.d)
    return 1;
  else if (a1.d == a2.d)
    {
      if (a1.q > a2.q)
        return 1;
      else
        return 0;
    }
  else
    return -1;
}

int cmp2 (struct arrow a1, struct arrow a2)
{
  return a1.q > a2.q ? 0 : 1;
}

int main()
{
  int n, m;
  scanf ("%d %d", &n, &m);

  int i, j;
  for (i = 1; i <= n; i++)
    scanf ("%ld", &B[i]);
  
  for (j = 1; j <= m; j++)
    scanf ("%ld %ld", &arr[j].d, &arr[j].q);

  if (n > m)
    {
      printf ("No Solution\n");
      return 0;
    }

  merge_sort_b (B, 1, n);

  merge_sort_arrow (arr, 1, m, cmp1);

  /*
  printf ("\nr: ");
  for (i = 1; i <= n; i++)
    printf ("%ld\n", B[i]);

  printf ("\n==========\n");
  
  for (j = 1; j <= m; j++)
    printf ("d: %ld q: %ld\n", arr[j].d, arr[j].q);
  */
  i = j = 1;
  long long cost = 0;
  

  for (i = 1; i <= n; i++)
    {
      while (j <= m && arr[j].d >= B[i])
        {
          //          printf ("queue_size: %d\n", queue_size);
          priority_queue[++queue_size] = arr[j++];
          //          printf ("queue_size: %d\n", queue_size);
          min_up (priority_queue, queue_size, queue_size);
        }
      if (queue_size == 0)
        {
          cost = 0;
          break;
        }
      else
        {
//          printf ("queue_size: %d\n", queue_size);
          long temp = min_del (priority_queue);
          cost += temp;
        }
    }

  if (cost == 0)
    printf ("No Solution\n");
  else
    printf ("%lld\n", cost);

  /*
  printf ("\nr: ");
  for (i = 1; i <= n; i++)
    printf ("%ld\n", B[i]);

  printf ("\n==========\n");

  for (j = 1; j <= m; j++)
    printf ("d: %ld q: %ld\n", arr[j].d, arr[j].q);
  */
  return 0;
}


void merge_sort_b (long arr[], int start, int end)
{
  int mid;
  if (start < end)
    {
      mid = start + (end - start) / 2;
      merge_sort_b (arr, start, mid);
      merge_sort_b (arr, mid + 1, end);
      merge_b (arr, start, mid, end);
    }
}

void merge_b (long arr[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  long *l = (long *) malloc (sizeof (long) * l1);
  long *r = (long *) malloc (sizeof (long) * l2);

  int i, j, k;
  for (i = 0; i < l1; i++)
    l[i] = arr[i + start];
  
  for (j = 0; j < l2; j++)
    r[j] = arr[j + mid + 1];

  i = j = 0, k = start;
  while (i < l1 && j < l2)
    {
      if (l[i] > r[j])
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


void merge_sort_arrow (struct arrow arr[], int start, int end, int (* cmp)(struct arrow, struct arrow))
{
  int mid;
  if (start < end)
    {
      mid = start + (end - start) / 2;
      merge_sort_arrow (arr, start, mid, cmp);
      merge_sort_arrow (arr, mid + 1, end, cmp);
      merge_arrow (arr, start, mid, end, cmp);
    }
}

void merge_arrow (struct arrow arr[], int start, int mid, int end, int (*cmp)(struct arrow, struct arrow))
{
  int l1 = mid - start + 1;
  int l2 = end - mid;

  struct arrow *l = (struct arrow *) malloc (sizeof (struct arrow) * l1);
  struct arrow *r = (struct arrow *) malloc (sizeof (struct arrow) * l2);

  int i, j, k;
  for (i = 0; i < l1; i++)
    l[i] = arr[i + start];
  for (j = 0; j < l2; j++)
    r[j] = arr[j + mid + 1];

  i = j = 0, k = start;

  while (i < l1 && j < l2)
    {
      if (cmp (l[i], r[j]) > 0)
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


void min_down (struct arrow arr[], int i, int n)
{
  int flag = 0;
  
  while (i * 2 <= n && flag == 0)
    {
      int t = arr[i * 2].q < arr[i].q ? i * 2 : i; // 处理i的左结点
      
      if (i * 2 + 1 <= n && arr[t].q > arr[i * 2 + 1].q)
        t = i * 2 + 1;
      
      if (t != i)
        {
          struct arrow temp = arr[t];
          arr[t] = arr[i];
          arr[i] = temp;
          i = t;
        }
      else
        flag = 1;
    }
}

void min_up (struct arrow arr[], int i, int n)
{
  if (i == 1)
    return;

  int flag = 0;
  while (i != 1 && flag == 0)
    {
      if (arr[i / 2].q > arr[i].q)
        {
          struct arrow temp = arr[i / 2];
          arr[i / 2] = arr[i];
          arr[i] = temp;
          i = i / 2;
        }
      else
        flag = 1;
    }
}

long min_del (struct arrow arr[])
{
  long temp = arr[1].q;
  arr[1] = arr[queue_size];
  queue_size--;
  min_down (arr, 1, queue_size);
  return temp;
}
