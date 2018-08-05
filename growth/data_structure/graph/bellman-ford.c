#include <stdio.h>

// 这里我们讨论两个问题
// 1. 图的存储
// 1.1 e[i][j] 如果有n个点, 需要的空间则是O(n^2)
// 1.2 如果m << n^2, 则称为稀疏图
// 1.3 此时如果使用临接表, 则需要, u[n], v[n], w[n]; first[n], next[m+1]; first[n+1], next[m+1];
// 1.4 first的idx含义为第i个点, val为第x条边; next的idx含义为第i条边, val为下一条边
// 2. 在单源最短路径的场景下, 解决负权边? 同时提出另一个问题, 为什么dijkstra无法解决负权边?

#define MAX_VAL 999999

int main()
{
    int dis[10], u[10], v[10], w[10];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    
    for (int i = 1; i <= n; i++)
        dis[i] = MAX_VAL;
    
    dis[1] = 0;

    for (int k = 1; k <= n - 1; k++)    // 有n个点, 寻找许多有n-1条边, OPT: 这里是否有性能问题呢?
        for (int i = 1; i <= m; i++)
            // src->v[i] 有没有可能 通过边u[i]->v[i] 这条边松弛
            // 即src->u[i]->v[i]
            if (dis[v[i]] > dis[u[i]] + w[i])
                dis[v[i]] = dis[u[i]] + w[i];
    int flag = 0;
    for (int i = 1; i <= m; i++)
        if (dis[v[i]] > dis[u[i]] + w[i])
            flag = 1;
    if (flag == 1)
        printf("negtive circuit\n");

    for (int i = 1; i <= n; i++)
        printf("%d", dis[i]);
    return 0;
}
