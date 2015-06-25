#include <stdio.h>

#define MAX_SIZE 1001

int A[MAX_SIZE];

//-----------最大堆相关操作-----------

// 建立最大堆
void build_max_heap ();

// 最大堆的向上调整
void max_up (int arr[], int i);

// 最大堆的向下调整
void max_down (int arr[], int i, int n);

void max_del (int arr[], int i, int n);

//-----------最小堆相关操作-----------

// 建立最小堆
void build_min_heap ();

// 最小堆的向上调整
void min_up (int arr[], int i);

// 最小堆的向下调整
void min_down (int arr[], int i, int n);

void min_del (int arr[], int i, int n);

int main()
{
  
  int n, i;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    scanf ("%d", &A[i]);

  build_max_heap (A, n);
  //  build_min_heap (A, n);

  //  min_del (A, 0, n);
  max_del (A, 0, n);
  //  for (i = 1; i <= n; i++)
  //  printf ("%d ", A[i]);
  return 0;
}


void build_max_heap (int arr[], int n)
{
  int i;
  for (i = n / 2; i >= 1; i--)
    max_down (arr, i, n);
}

void max_up (int arr[], int i)
{
  if (i == 1)
    return;
  
  int flag = 0;
  while (i != 1 && flag == 0)
    {
      if (arr[i / 2] < arr[i])
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

void max_down (int arr[], int i, int n)
{
  int flag = 0;
  while (i * 2 <= n && flag == 0)
    {
      int t = arr[i * 2] > arr[i] ? i * 2 : i; // 与i结点的左儿子进行比较
      
      if (i * 2 + 1 <= n && arr[t] < arr[i * 2 + 1]) // 与i结点的右儿子进行比较
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

void max_del (int arr[], int i, int n)
{
  while (n >= 1)
    {
      printf ("%d ", arr[1]);
      arr[1] = arr[n];
      n--;
      max_down (arr, 1, n);
    }
}



void build_min_heap (int arr[], int n)
{
  int i;
  for (i = n / 2; i >= 1; i--)
    min_down (arr, i, n);
}

void min_up (int arr[], int i)
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

void min_down (int arr[], int i, int n)
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

void min_del (int arr[], int i, int n)
{
  while (n >= 1)
    {
      printf ("%d ", arr[1]);
      arr[1] = arr[n];
      n--;
      min_down (arr, 1, n);
    }
}
