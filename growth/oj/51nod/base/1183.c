#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 1002

char str1[MAX_SIZE];
char str2[MAX_SIZE];

int dp[MAX_SIZE][MAX_SIZE] = { {INT_MAX} }; // dp[i][j] 代表 str1 从 1....i str2 从1....j的最少修改次数

int main()
{
  gets (str1);
  gets (str2);

  int s1_len = strlen (str1);
  int s2_len = strlen (str2);

  int i, j;

  for (i = 0; i <= s1_len; i++)
    dp[i][0] = i;

  for (j = 0; j <= s2_len; j++)
    dp[0][j] = j;

  
  for (i = 0; i < s1_len; i++)
    for (j = 0; j < s2_len; j++)
      {
        if (str1[i] == str2[j])
          dp[i + 1][j + 1] = dp[i][j];
        else
          {
            // 三种场景
            int m1 = dp[i + 1][j] + 1; // 对原串操作
            int m2 = dp[i][j + 1] + 1; // 对目标串操作
            int m3 = dp[i][j] + 1; // 直接删了
            dp[i + 1][j + 1] = m1 > m2 ? (m2 > m3 ? m3 : m2) : (m1 > m3 ? m3 : m1);
          }
        //        printf ("dp[%d][%d] = %d\n", i + 1, j + 1, dp[i + 1][j + 1]);
      }

  printf ("%d\n", dp[s1_len][s2_len]);
  return 0;
}
