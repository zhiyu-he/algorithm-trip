#include <stdio.h>

#define MAX_SIZE 50001

long N[MAX_SIZE]; // 井
long M[MAX_SIZE]; // 盘子


int main()
{
  int n, m; // n为井，m为盘子
  scanf ("%d %d", &n, &m);
  int i;
  for (i = 1; i <= n; i++)
    {
      scanf ("%ld", &N[i]);
      if (i > 1 && N[i] > N[i - 1])
        N[i] = N[i - 1];
    }

  for (i = 1; i <= m; i++)
    scanf ("%ld", &M[i]);

  int count = 0, break_flag = 0;
  i = 1;
  while (!break_flag && n > 0 && i <= m)
    {
      if (M[i] <= N[1]) // 因为N为单调递减的，如果M[i] <= N[1] 证明一定可以放下
        {
          while (N[n] < M[i])
            n--;
          n--;
          count++;
        }
      else
        break_flag = 1;
      i++;
    }

  printf ("%d", count);
  return 0;
}
