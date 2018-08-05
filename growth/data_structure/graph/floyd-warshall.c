#include <stdio.h>

// 多源最短路径, 好比, 任意两个城市之间的最短路径 -> 任意两点的最短路径
// 考虑这么一个问题, 假设A->B 耗时1h的路程, 那么什么场景下A->B的耗时会减少?
// 理论上只有借助额外的点, 好比A->M->B. 进一步考虑, 借助的点可以有N个
//
// 回过头来, 思考这个问题, 在N个点的情况下, 求任意两点的最短路径, 即是否存在一个点K, 使得A->B之间更短, 即 cost[A][B] > cost[A][K] + cost[K][B]?
// 这里需要考虑得是, 一共有N个点, 有可能存在K1, K2, ... Kn, 多个点使得A->B之间更短, 此时要如何做呢?
//
#define MAX_INF 9999999

int main()
{
    int e[10][10], n, m, u, v, w;
    // n个点, m条边
    scanf("%d %d", &n, &m);
    
    // 初始化整个矩阵, 默认i->j为无穷大
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i ==j)
                e[i][j] = 0;
            else
                e[i][j] = MAX_INF;
    
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);  // u->v, w
        e[u][v] = w;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (e[i][k] < MAX_INF && e[k][j] < MAX_INF && e[i][j] > e[i][k]+e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
            }

    int flag = 0;   // 检验负权回路

    // print result
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%10d", e[i][j]);
        printf("\n");
    }
    return 0;
}
