#include <stdio.h>


long k;
int  n;
long A[10001];
long dp[10001];

int left = 0, right = 0;


void build_answer (int i, int j)
{
  if (left == 0)
    {
      left = i;
      right = j;
    }
  else if (left > i)
    {
      left = i;
      right = j;
    }
  else if (left == i)
    {
      if (j < right)
        {
          right = j;
        }
    }
}


int main()
{
  scanf ("%d %ld", &n, &k);
  int i, j, flag = 1;
  for (i = 1; i <= n; i++)
    scanf ("%ld", &A[i]);

  // init dp
  for (i = 1; i <= n; i++)
    {
      dp[i] = A[i];
      if (dp[i] == k)
        build_answer (i, i);
    }

  // 从第二层开始
  for (i = 2; i <= n; i++)
    {
      int index = 1;
      for (j = i; j <= n; j++)
        {
          dp[index] = dp[index] + A[j];
          //          printf ("dp[%d][%d] = %ld ", i, index, dp[index]);
          if (dp[index] == k)
            {
              build_answer (index, index + i - 1);
              flag = 0;
            }
          index++;
        }
      //      printf ("\n");
    }
  
  
  if (flag)
    printf ("No Solution\n");
  else
    printf ("%d %d\n", left, right);
  return 0;
}
