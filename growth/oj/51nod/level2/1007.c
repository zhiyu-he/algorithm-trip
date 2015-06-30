#include <stdio.h>
#include <stdlib.h>

long N[101];

long dp[10001] = {0};

int main()
{
  int i, n;
  long sum = 0;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    {
      scanf ("%ld", &N[i]);
      sum += N[i];
    }
  
  long half = sum / 2; // 容量为half的背包的最大值
  for (i = 1; i <= n; i++) // 放i枚
    {
      long j;
      for (j = half; j >= N[i]; j--)
        {
          dp[j] = dp[j - N[i]] + N[i] > dp[j] ? dp[j - N[i]] + N[i] : dp[j];
        }
    }
  //  printf ("dp[half] = %ld\n", dp[half]);
  printf ("%ld\n", sum - 2 * dp[half]);
  return 0;
}
