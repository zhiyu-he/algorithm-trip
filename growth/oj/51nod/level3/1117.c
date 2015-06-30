#include <stdio.h>

#define MAX_SIZE 50001

long long A[MAX_SIZE];

//-----------最小堆相关操作-----------

// 建立最小堆
void build_min_heap (long long arr[], int n);

// 最小堆的向上调整
void min_up (long long arr[], int i);

// 最小堆的向下调整
void min_down (long long arr[], int i, int n);

long long min_del (long long arr[], int i, int n);

int main()
{
  
  int n, i;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    scanf ("%lld", &A[i]);

  build_min_heap (A, n);

  long long res = 0;
  while (n >= 2)
    {
      long long l1 = A[1];
      A[1] = A[n];
      n--;
      min_down (A, 1, n);
      
      long long l2 = A[1];
      A[1] = A[n];
      n--;
      min_down (A, 1, n);

      //      printf ("n: %d l1: %lld l2: %lld\n", n, l1, l2);
      res += (l1 + l2);
      A[++n] = l1 + l2;
      min_up (A, n);
    }
  printf ("%lld\n", res);
  return 0;
}

void build_min_heap (long long arr[], int n)
{
  int i;
  for (i = n / 2; i >= 1; i--)
    min_down (arr, i, n);
}

void min_up (long long arr[], int i)
{
  if (i == 1)
    return;

  int flag = 0;
  while (i != 1 && flag == 0)
    {
      if (arr[i / 2] > arr[i])
        {
          int temp = arr[i / 2];
          arr[i / 2] = arr[i];
          arr[i] = temp;
          i = i / 2;
        }
      else
        flag = 1;
    }
}

void min_down (long long arr[], int i, int n)
{
  int flag = 0;
  while (i * 2 <= n && flag == 0)
    {
      int t = arr[i * 2] < arr[i] ? i * 2 : i; // 处理i的左结点
      
      if (i * 2 + 1 <= n && arr[t] > arr[i * 2 + 1])
        t = i * 2 + 1;
      
      if (t != i)
        {
          int temp = arr[t];
          arr[t] = arr[i];
          arr[i] = temp;
          i = t;
        }
      else
        flag = 1;
    }
}

long long min_del (long long arr[], int i, int n)
{
  long long res = arr[1];
  arr[1] = arr[n];
  n--;
  min_down (arr, 1, n);
  return res;
}
