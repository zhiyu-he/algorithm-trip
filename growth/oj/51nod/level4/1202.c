#include <stdio.h>

#define LEN 100001
#define MOD 1000000007

int table[LEN];
long number[LEN];
long long dp[LEN];

int main()
{
  int n;
  scanf ("%d", &n);
  
  int i;
  for (i = 1; i <= n; i++)
    scanf ("%ld", &number[i]);

  for (i = 0; i <= LEN; i++)
    dp[i] = 0;
  
  dp[0] = 1; // 空序列
  
  for (i = 0; i <= LEN; i++)
    table[i] = 0;

  for (i = 1; i <= n; i++)
    {
      if (table[number[i]] == 0)
        {
          dp[i] = dp[i - 1] * 2 % MOD;
        }
      else
        {
          // 加上MOD是为了避免溢出
          dp[i] = (dp[i - 1] * 2 - dp[table[number[i]] - 1] + MOD) % MOD;
        }
      table[number[i]] = i;
    }
  printf ("%lld\n", dp[n] - 1);
  return 0;
}
