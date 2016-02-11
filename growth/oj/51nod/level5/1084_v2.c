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
 * 3. 优化:
 *    因为知道步数之后, 知道行坐标, 即可推算出纵坐标
 *    那么, 优化后的dp方程为
 *    k = i + j = p + q
 *
 *    其实需要判定列的原因是为了`取`val中的值
 *    j = k - i;
 *    q = k - q;
 *    
 *    那么对于行 存在两种可能 (i - 1, p) (i, p - 1), (i - 1, p - 1), (i, j)  最后一种情况是, 列变化了
 *    dp[k][i][p] = max (dp[k - 1][i - 1][p], dp[k - 1][i][p - 1], dp[k - 1][i - 1][p - 1], dp[k - 1][i][p]) + val[i][j] + val[p][q]
 *    其中i != p
 *
 */

//#define max(a, b) (a) > (b) ? (a) : (b)

//#define INIT(arr, val) memset(arr, val, sizeof(arr))

#define MAX 201

int m, n; // m行n列

long val[MAX][MAX];
long dp[402][MAX][MAX]; // dp[k][i][p] 表示第k步时, 第一个路径在第i行、第二个路径在第p行

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
    // 51nod这个题, m是列, n是行
    scanf ("%d %d", &m, &n);
    int k, i, j, p;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%ld", &val[i][j]);
    
    // 第k步
    for (k = 1; k <= m + n; k++)
    {
        for (i = 1; i <= n && k - i >= 0; i++)
        {
            for (p = 1; p <= n && k - p >= 0; p++)
            {
                long tmp = Max(dp[k - 1][i][p], 
                               dp[k - 1][i - 1][p], 
                               dp[k - 1][i][p - 1], 
                               dp[k - 1][i - 1][p - 1]);
                if (i == p) {
                    dp[k][i][p] = tmp + val[i][k - i + 1];
                } else {
                    dp[k][i][p] = tmp + val[i][k - i + 1] + val[p][k - p + 1];
                }

            }
        }
    }

    printf ("%ld\n", dp[m + n][n][n]); // 因为要走到相同的行
    return 0;
}
