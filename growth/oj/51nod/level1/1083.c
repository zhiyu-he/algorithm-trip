#include <stdio.h>

long dp[501][501] = { { 0 } };

long v[501][501] = { {0} }; // 每个格子的大小

long max_value(int n)
{
  long max = 0;
  int i, j;
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
        {
          dp[i][j] = 0;
          long v1 = 0;
          long v2 = 0;
          if (i - 1 > 0)
            {
              v1 = dp[i - 1][j];
            }
          if (j - 1 > 0)
            {
              v2 = dp[i][j - 1];
            }
          dp[i][j] = v1 > v2 ? v1 + v[i][j] : v2 + v[i][j];
          if (dp[i][j] > max)
            max = dp[i][j];
        }
    }
  return max;
}

int main()
{
  int n;
  scanf ("%d", &n);
  int i, j;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      {
        scanf ("%ld", &v[i][j]);
      }

  printf ("%ld\n", max_value (n));
  return 0;
}
