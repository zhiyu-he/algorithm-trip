#include <stdio.h>
#include <string.h>
/*
 *
 * (1, 1) -> (m, n)
 *
 * 对于最传统的，由左上，走到右下的dp，因为某一个点的位置，只可能是从`左边` 或者`右边`到来
 * 因此dp[i][j] =  max (dp[i - 1][j], dp[i][j - 1]) + v[i][j]
 *
 *
 * 现在是(1, 1) -> (m, n) && (m, n) -> (1, 1)
 *
 * 重新抽象，寻找两条路径(1, 1) -> (i, j) -> (m, n) && (1, 1) -> (p, q) -> (m, n)
 *
 * key: 
 * 1. 假设是m行, n列的矩阵，那么从左上角，走到右下角，需要的步数就是, (m + n)步；当有两条路径的时候，也就是i + j = p + q
 * 2. 保证两条线不相交:
 *    假设下一个目标节点是(i, j, p, q)那么需要推导的点就是
 *    (i - 1, j) (p - 1, q)
 *    (i, j - 1) (p, q - 1)
 *
 *    因此 max(dp[i - 1][j][p - 1][q], dp[i - 1][j][p][q - 1],
 *             dp[i][j - 1][p - 1][q], dp[i][j - 1][p][q - 1]) + val[i][j] + val[p][q]
 *
 */

//#define max(a, b) (a) > (b) ? (a) : (b)

//#define INIT(arr, val) memset(arr, val, sizeof(arr))

#define MAX 201

int m, n; // m行n列

long val[MAX][MAX];
long dp[MAX][MAX][MAX][MAX];

long max(long a, long b)
{
    return a > b ? a : b;
}


long Max(long a, long b, long c, long d)
{
    return max(max(a, b), max(c, d));
}


int main()
{   
    scanf ("%d %d", &m, &n);
    int i, j, p, q;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%ld", &val[i][j]);
    
    //printf("Init dp\n");
    //memset(dp, 0, sizeof(dp));
    //printf("Init dp done\n");

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (p = i + 1; p <= m; p++) // 当选中了i之后, 第二个路径就要错开一行
            {
                q = i + j - p;
                if (q < 0) continue;
                dp[i][j][p][q] = Max(dp[i - 1][j][p - 1][q], dp[i - 1][j][p][q - 1], 
                                     dp[i][j - 1][p - 1][q], dp[i][j - 1][p][q - 1]) + val[i][j] + val[p][q];
            }
        }
    }
    // 单独处理(m, n, m, n)点
    long res = Max(dp[m - 1][n][m - 1][n], dp[m - 1][n][m][n -1], 
                   dp[m][n-1][m-1][n], dp[m][n-1][m][n-1]) + val[m][n];

    printf ("%ld\n", res);
    return 0;
}
