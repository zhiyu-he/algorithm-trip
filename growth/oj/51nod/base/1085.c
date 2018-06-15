#include <stdio.h>

#define MAX_ITEM_SIZE 101
#define MAX_CAP 10000
int dp[MAX_CAP] = {0};

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
    // 优化空间之前 dp[i][c] = max(dp[i-1][c], dp[i-1][c-w[i]])
    // 之前每一次i循环, 会将dp[i-1][0...c]全部依次填充
    for (i = 1; i <= n; i++)
    {
        for (j = c; j >= weight[i]; j--)
        {
            // 初始化涉及到一个问题是, 使用完整的CAP or 允许CAP为空
            // 前者dp[0] = 0, 其他为负无穷
            // 直接全部初始化为0
            // 判断当前元素是否可以扔到背包里
            if (j - weight[i] >= 0)
            {
                int temp;
                temp = dp[j - weight[i]] + value[i];
                if (temp > dp[j])
                    dp[j] = temp;
            }
            if (dp[j] > max)
              max = dp[j];
        }
    }
    return max;
}
