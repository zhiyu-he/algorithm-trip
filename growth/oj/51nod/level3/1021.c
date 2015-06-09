#include <stdio.h>
#include <limits.h>


long sum[101][101] = { { 0 } };

long dp[101][101] = { { LONG_MAX } };

int main()
{
  int n;
  long arr[101] = { 0 };
  scanf ("%d", &n);
  int i, j, k, l;
  for (i = 1; i <= n; i++)
    {
      scanf ("%ld", &arr[i]);
    }
  
  // 构建sum合, 即从第i个元素到第j个元素的和
  for (i = 1; i <= n; i++)
    {
      for (j = i; j <= n; j++)
        {
          if (i == j)
            sum[i][j] = arr[i];
          else
            sum[i][j] += sum[i][j - 1] + arr[j];
        }
    }
  
  for (l = 2; l <= n; l++)
    for (i = 1; i <= n - l + 1; i++)
      {
        j = i + l - 1;
        dp[i][j] = LONG_MAX;

        for (k = i; k < j; k++)
          {
            long temp = dp[i][k] + dp[k + 1][j] + sum[i][j];
            if (dp[i][j] > temp)
              {
                dp[i][j] = temp;
              }
          }
      }
  printf ("%ld\n", dp[1][n]);
  return 0;
}
