#include <stdio.h>

#define LEN 50001

int dp[LEN];
int a[LEN];

int main()
{
  int n;
  scanf ("%d", &n);
  int i;
  
  for (i = 1; i <= n; i++)
    scanf ("%d", &a[i]);

  int max_inc_len = 0;
  for (i = 1; i <= n; i++)
    {
      dp[a[i]] = dp[a[i] - 1] + 1;
      max_inc_len = max_inc_len > dp[a[i]] ? max_inc_len : dp[a[i]];
    }
  
  printf ("%d\n", n - max_inc_len);
  
  return 0;
}
