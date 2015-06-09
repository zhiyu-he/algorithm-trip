#include <stdio.h>

int coins[13] = { 1, 2, 5,     // 分 
                  10, 20, 50,  // 角
                  100, 200, 500, 1000, 2000, 5000, 10000 // 元
};

unsigned long result = 0;

unsigned long dp[100001][13];   // dp[i][j] dp[i][j] 为满足i元, j枚硬币时下的解的数量

unsigned long MOD = 1000000007;

int main()
{

  unsigned long N;
  scanf ("%ld", &N);
  int i, j;
  for (i = 0; i < 13; i++)
    {
      dp[0][i] = 1;
    }

  for (i = 1; i <= N; i++)
    {
      int c, nc;
      for (j = 0; j < 13; j++)
        {
          // 添加coins[j]
          c  = i - coins[j] >= 0 ? dp[i - coins[j]][j] : 0;
          // 不添加
          nc = j > 0 ? dp[i][j - 1] : 0;
          dp[i][j] = (c + nc) % MOD;
        }
    }
  
  printf ("%ld\n", dp[N][12]);
  return 0;
}
