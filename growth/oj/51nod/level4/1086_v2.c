#include <stdio.h>

#define N_KINDS 101
#define W 50000
int n, w;

int weight[N_KINDS] = {0};
int value[N_KINDS] = {0};
int count[N_KINDS] = {0};

int dp[W] = {0};

int main()
{
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &weight[i], &value[i], &count[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int k = 1;
        while (k < count[i])
        {
            for (int j = w; j - weight[i] * k >= 0; j--)
            {
                int temp = dp[j-weight[i]*k] + value[i]*k;
                if (temp > dp[j])
                {
                    dp[j] = temp;
                }
            }
            count[i] -= k;
            k = k * 2;
        }
 
        for (int j = w; j - weight[i] * count[i] >= 0; j--)
        {
            int temp = dp[j-weight[i]*count[i]] + value[i]* count[i];
            if (temp > dp[j])
            {
                dp[j] = temp;
            }
        }
    }

    int max = 0;
    for (int i = 0; i <= w; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }
    printf("%d\n", max);
    return 0;
}

