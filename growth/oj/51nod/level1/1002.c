#include <stdio.h>

int tower[501][501];
int dp[501][501];

long max_value = 0;

void init_dp ()
{
  int i, j;
  for (i = 1; i <= 500; i++)
    for (j = 1; j <= i; j++)
      {
        dp[i][j] = 0;
      }
}

void find_max (int heigh)
{
  int i, j, k;
  for (i = 1; i < heigh; i++) // 处理塔的楼层, 每层
    {
      if (i == 1)
        {
          dp[1][1] = tower[1][1];
          max_value = dp[1][1];
        }
      for (j = 1; j <= i; j++) // 取当前的层的所有点
        {
          int current_point = dp[i][j];
          int next_step = i + 1;
          for (k = j; k <= j + 1; k++) // 计算当前点下一层的最大值
            {
              int temp = current_point + tower[next_step][k];
              dp[next_step][k] = temp > dp[next_step][k] ? temp : dp[next_step][k];
              max_value = dp[next_step][k] > max_value ? dp[next_step][k] : max_value;
            }
        }
    }
}

int main()
{
  init_dp ();

  int th; // 塔的高度
  scanf ("%d", &th);

  int i, j;
  for (i = 1; i <= th; i++)
    for (j = 1; j <= i; j++)
      {
        scanf ("%d", &tower[i][j]);
      }

  find_max (th);

  printf ("%ld\n", max_value);
  return 0;
}