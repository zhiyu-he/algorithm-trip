#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

char A[MAX_SIZE];
char B[MAX_SIZE];

int dp[MAX_SIZE][MAX_SIZE];

// 计算两个字符串的最长公共子串
int lcs_len (char *s1, char *s2, int len)
{
  int i, j;
  for (i = 0; i < len; i++)
    for (j = 0; j < len; j++)
      {
        if (s1[i] == s2[j])
          dp[i + 1][j + 1] = dp[i][j] + 1;
        else
          dp[i + 1][j + 1] = dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j];
      }
  return dp[len][len];
}

int main()
{
  gets (A);
  int i, j, len = strlen (A);
  j = len - 1;
  i = 0;
  while (j >= 0)
    B[i++] = A[j--];

  for (i = 0; i <= len; i++)
    for (j = 0; j <= len; j++)
      dp[i][j] = 0;
  int lcs_length = lcs_len (A, B, len);
  
  printf ("%d\n", len - lcs_length);
  return 0;
}
