#include <stdio.h>
#include <limits.h>

long long sum[2001][2001];

long long dp[2001][2001];

int k[2001][2001];  // k[i][j - 1] <= k[i, j] <= k[i + 1][j];

long long result = LONG_LONG_MAX;


int main()
{
  long long arr[2001] = { 0 };
  int N, RN; // RN means real length RN = 2 * N - 1
  scanf ("%d", &N);
  int i, j, l;
  for (i = 1; i <= N; i++)
    scanf ("%lld", &arr[i]);
  //printf ("====\n");
  // 拼接链表 将环状的数组退化到一维的链表
  for (i = N + 1, j = 1; j < N; j++, i++)
    arr[i] = arr[j];
  
  RN = 2 * N - 1;

  for (i = 1; i <= RN; i++)
    {
      int end = i + 5 > RN ? RN : i + N; 
      for (j = i; j <= end; j++)
        {
          if (i == j)
            sum[i][j] = arr[i];
          else
            sum[i][j] += arr[j] + sum[i][j - 1];
        }
    }
  //  printf ("=====2\n");

  for (i = 1; i <= RN; i++)
    for (j = 1; j <= RN; j++)
      dp[i][j] = 0;

  for (i = 1; i <= RN; i++)
    k[i][i] = i;
  //  for (i = 1; i <= RN; i++)
  //  printf ("%lld\t", arr[i]);
  for (l = 2; l <= N; l++)
    {
      for (i = 1; i <= RN - l + 1; i++)
        {
          int j = i + l - 1;

          int a = k[i][j - 1];
          int b = k[i + 1][j] > j - 1 ? j - 1 : k[i + 1][j];
          dp[i][j] = LONG_LONG_MAX;
          int m;
          for (m = a; m <= b; m++)
            {
              long long temp = dp[i][m] + dp[m + 1][j] + sum[i][j];
              if (dp[i][j] > temp)
                {
                  dp[i][j] = temp;
                  k[i][j] = m;
                }
              if (l == N && temp < result)
                result = temp;
            }
        }
    }
  
  printf ("%lld\n", result);
  return 0;
}