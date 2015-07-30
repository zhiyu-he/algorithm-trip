#include <stdio.h>

#define MAX_SIZE 1001

int matrix_size;

long long matrix1[MAX_SIZE][MAX_SIZE];
long long matrix2[MAX_SIZE][MAX_SIZE];
long long matrix3[MAX_SIZE][MAX_SIZE];

// i: 行 j: 列
long long cal (int i, int j, int size)
{
  //martix3[i][j] = martix1[i][0..size] * maritx2[0..size][j];

  long long res = 0;
  int inc = 0;
  while (inc < size)
    {
      res += matrix1[i][inc] * matrix2[inc][j];
      inc++;
    }
  return res;
}

int main()
{
  scanf ("%d", &matrix_size); // 读入矩阵数量

  int row = 0;
  // 获取第一个矩阵
  while (row < matrix_size)
    {
      int i;
      for (i = 0; i < matrix_size; i++)
        scanf ("%lld", &matrix1[row][i]);
      row++;
    }
  // 获取第二个矩阵
  row = 0;
  while (row < matrix_size)
    {
      int i;
      for (i = 0; i < matrix_size; i++)
        scanf ("%lld", &matrix2[row][i]);
      row++;
    }
  
  // 对矩阵进行计算
  int i, j;
  for (i = 0; i < matrix_size; i++)
    for (j = 0; j < matrix_size; j++)
      {
        matrix3[i][j] = cal (i, j, matrix_size);
      }

  for (i = 0; i < matrix_size; i++)
    {
      for (j = 0; j < matrix_size; j++)
        {
          printf ("%lld", matrix3[i][j]);
          if (j < matrix_size - 1)
            printf (" ");
        }
      printf ("\n");
    }
  return 0;
}
