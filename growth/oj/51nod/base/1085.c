#include <stdio.h>

#define MAX_ITEM_SIZE 101

int dp[MAX_ITEM_SIZE][10000];

int max_value (int n, int c);

int weight[MAX_ITEM_SIZE] = {0};
int value[MAX_ITEM_SIZE] = {0};

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    int i;
    for (i = 1; i <= n; i++)
    {
      scanf("%d %d", &weight[i], &value[i]); 
    }
    int max = max_value (n, c);
    printf("%d\n", max);
    return 0;
}

int max_value(int n, int c)
{
    int i, j;
    int max;
    for (i = 1; i <= n; i++)
        for (j = 0; j <= c; j++)
        {
            // 首先初始化当前数组元素即 放入i个元素，容量为c的价值大小
            dp[i][j] = dp[i - 1][j] == 0 ? 0 : dp[i - 1][j];
            // 判断当前元素是否可以扔到背包里
            if (j - weight[i] >= 0)
            {
                int temp;
                temp = dp[i - 1][j - weight[i]] + value[i];
                if (temp > dp[i][j])
                    dp[i][j] = temp;
            }
            if (dp[i][j] > max)
              max = dp[i][j];
            }
    return max;
}
