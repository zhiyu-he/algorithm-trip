#include <stdio.h>

#define MAX_SIZE 50001 // 数量

long A[MAX_SIZE];
long B[MAX_SIZE];

int main()
{
  int i, m, n;
  scanf ("%d %d", &m, &n);
  
  long max_height = 0;
  int max_height_index = -1;
  // 读入地形
  for (i = 1; i <= m; i++)
    {
      scanf ("%ld", &A[i]);
      if (A[i] > max_height)
        {
          max_height = A[i];
          max_height_index = i;
        }
    }

  // 读入炮弹
  for (i = 1; i <= n; i++)
    scanf ("%ld", &B[i]);

  // 处理每一枚炮弹
  for (i = 1; i <= n; i++)
    {
      if (B[i] <= A[1])
        continue;
      if (B[i] > max_height)
        continue;
      int j;
      for (j = 2; j <= max_height_index; j++)
        {
          if (B[i] <= A[j])
            {
              //              printf ("B[%d] = %ld, hit A[%d]: %ld\n", i, B[i], j, A[j]);
              A[j - 1] += 1;
              if (A[j - 1] >= max_height)
                {
                  max_height = A[j - 1];
                  max_height_index = j - 1;
                }
              break;
            }
        }
    }

  for (i = 1; i <= m; i++)
    printf ("%ld\n", A[i]);
  return 0;
}
