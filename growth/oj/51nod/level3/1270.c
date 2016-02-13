#include <stdio.h>
#include <stdlib.h>
#define MAX 50001

long B[MAX];

long dp[MAX][2];

/*
long abs(long val)
{
    return val < 0 ? -val : val;
}
*/

long max (long v1, long v2)
{
    return v1 > v2 ? v1 : v2;
}

int main()
{   
    int N;
    scanf ("%d", &N);
    int i;
    for (i = 1; i <= N; i++)
    {
        scanf ("%ld", &B[i]);
    }


    // A[i] 的取值 只可能是1，或者B[i], 那么这个问题，就变成了，当取1或者取B[i]时, 那个会导致dp[i]的代价最大
    // 也就是说, dp[i]的含义为，长度为i的数组A[i]的最大代价
    // 以往数列类型的DP，第i个点的位置是固定的，因此dp[i]即可以表示，现在不同的情况是, 第i个点的选择有两种情况，即最大(峰点)，最小(鞍点)
    //
    // dp[i][1] 代表第i个位置取B[i]
    // dp[i][0] 代表第i个位置取1
    // 
    // 当dp[i][1]时, 取决于dp[i - 1][1] 与 dp[i - 1][0] 因为当前点的最大值的上面有两个分支
    // 同理可知dp[i][0]时, 也是如此
    //
    // dp[i][1] = max(dp[i - 1][1] + abs(B[i] - B[i - 1]), dp[i - 1][0] + abs(B[i] - 1))
    // dp[i][0] = max(dp[i - 1][1] + abs(1 - B[i]), dp[i - 1][1] + 0)
    dp[1][1] = 0;
    dp[1][0] = 0;
    for (i = 2; i <= N; i++)
    {
        dp[i][1] = max(dp[i - 1][1] + abs(B[i] - B[i - 1]), dp[i - 1][0] + abs(B[i] - 1));
        dp[i][0] = max(dp[i - 1][1] + abs(1 - B[i - 1]), dp[i - 1][0] + 0);
    }
    long ans = max(dp[N][0], dp[N][1]);
    printf ("%ld\n", ans);

    return 0;
}
