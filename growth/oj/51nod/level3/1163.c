#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50001

struct task {
  long long et;
  long long value;
};

struct task tasks[MAX_SIZE];

int queue_size = 0;
struct task priority_queue[MAX_SIZE];


// 最大堆的向上调整
void max_up (struct task arr[], int i, int n);
// 最大堆的向下调整
void max_down (struct task arr[], int i, int n);

long max_del (struct task arr[]);


void merge (struct task arr[], long begin, long mid, long end);

void divide(struct task arr[], long begin, long end);

int cmp (struct task t1, struct task t2)
{
  /*
  if (t1.value > t2.value)
    return 1;
  else if (t1.value == t2.value)
    {
      if (t1.et > t2.et)
        return -1;
      else
        return 0;
    }
  else
    return -1;
  */
  
  if (t1.et > t2.et)
    return 1;
  else if (t1.et == t2.et)
    {
      if (t1.value > t2.value)
        return 1;
      else if (t1.value == t2.value)
        return 0;
      else
        return -1;
    }
  else
    return -1;
  
}

int main()
{
  int N;
  scanf ("%d", &N);
  

  long long max_value = 0;
  int i, j;

  for (i = 1; i <= N; i++)
    {
      scanf ("%lld %lld", &tasks[i].et, &tasks[i].value);
      if (tasks[i].et > N)
        tasks[i].et = N;
    }
  divide (tasks, 1, N);
  
  
  j = 1;
  for (i = tasks[1].et; i > 0; i--)
    {
      while (j <= N && tasks[j].et >= i)
        {
          priority_queue[++queue_size] = tasks[j++];
          max_up (priority_queue, queue_size, queue_size);
        }
      if (queue_size != 0)
        max_value += max_del (priority_queue);
    }
  /*
  printf ("=====\n");

  for (i = 1; i <= N; i++)
    printf ("%lld %lld\n", tasks[i].et, tasks[i].value);
  */
  printf ("%lld\n", max_value);
  return 0;
}


void merge(struct task arr[], long begin, long mid, long end)
{
  long n1 = mid - begin + 1;
  long n2 = end - mid;

  struct task *l1 = (struct task *) malloc (sizeof (struct task) * n1);
  struct task *l2 = (struct task *) malloc (sizeof (struct task) * n2);
  
  long i, j, k;
  for (i = 0; i < n1; i++)
    {
      l1[i].et = arr[begin + i].et;
      l1[i].value = arr[begin + i].value;
    }
  for (j = 0; j < n2; j++)
    {
      l2[j].et = arr[mid + 1 + j].et;
      l2[j].value = arr[mid + 1 + j].value;
    }
  
  i = j = 0;
  k = begin;
  while (i < n1 && j < n2)
    {
      if (cmp (l1[i], l2[j]) >= 0)
        arr[k++] = l1[i++];
      else
        arr[k++] = l2[j++];
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


void divide(struct task arr[], long begin, long end)
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


// 最大堆的向上调整
void max_up (struct task arr[], int i, int n)
{
  if (i == 1)
    return;
  
  int flag = 0;
  while (i != 1 && flag == 0)
    {
      if (arr[i / 2].value < arr[i].value)
        {
          struct task temp = arr[i / 2];
          arr[i / 2] = arr[i];
          arr[i] = temp;
          i = i / 2;
        }
      else
        flag = 1;
    }
}

void max_down (struct task arr[], int i, int n)
{
  int flag = 0;
  while (i * 2 <= n && flag == 0)
    {
      int t = arr[i * 2].value > arr[i].value ? i * 2 : i; // 与i结点的左儿子进行比较
      
      if (i * 2 + 1 <= n && arr[t].value < arr[i * 2 + 1].value) // 与i结点的右儿子进行比较
        t = i * 2 + 1;

      if (t != i)
        {
          struct task temp = arr[t];
          arr[t] = arr[i];
          arr[i] = temp;
          i = t;
        }
      else
        flag = 1;
    }
}

long max_del (struct task arr[])
{
  long temp = arr[1].value;
  arr[1] = arr[queue_size];
  queue_size--;
  max_down (arr, 1, queue_size);
  return temp;
}
