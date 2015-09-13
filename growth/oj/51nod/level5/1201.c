#include <stdio.h>
#include <math.h>
/**
   1. 01背包可以解
   2. 优化的复杂度为n * sqrt(n)
   dp[i][j] 表示j个数组成值为i的方法数
 */
#define MAX_SIZE 50001
#define MOD 1000000007;

int N;
long count = 0;

long dp[MAX_SIZE][350]; // N的范围是50000 那么最小的可能就是 1 ＋ 2 ＋3 ＋ 。。。 ＋ n ＝ 50000 
// dp[i][j] = dp[i - j][j - 1] + dp[i - 1][j];
// dp[5][3] = dp[3][2] + dp[4][3]
// dp[5][2] = dp[3][1] + dp[3][2]
int main()
{
  scanf ("%d", &N);
  
  int i, j;
  
  dp[1][1] = 1;
  for (i = 1; i < 350; i++)
    for (j = 1; j <= N; j++)
      {
        if (i + j <= N)
          {
            dp[i + j][i] = (dp[i + j][i] + dp[j][i]) % MOD;
          }

        if (i + j + 1 <= N && i + 1 < 350)
          {
            dp[i + j + 1][i + 1] = (dp[i + j + 1][i + 1] + dp[j][i]) % MOD;
          }
      }

  long long ans = 0;
  for (i = 1; i < 350; i++)
    ans = (ans + dp[N][i]) % MOD;

  printf ("%lld\n", ans);
  return 0;
}
