#include <stdio.h>


// 指定一个点, 到其余各点的最短路径, 即"单源最短路径"
// 和floyd-warshall相比, 后者是"多源最短路径"
// 思考一下, 如何解决这个问题, 给定一个点, 到其余各点的最短路径
// 给定一个点的情况下, 我们可以有一个distance的数组, 用来表达, 从`给定点`出发到其余各点的距离

// 接下来, 我们考虑下什么时候distance[k]会发生变化呢?
// a1. 假设抽象题目为从node1出发的点到其余各点的最短路径
// a2. 如果有有如下的边(n1, n2, 10),(n1, n3, 100), 我们选一个离n1最近的边, 看是否可以将整个distance数组变的更小
// a2.1. 这里的重点是， 选择所有以n1为出度的边中, 距离最小的那个 why? and 贪心?
//
//
//
#define MAX_VAL 999999


int main()
{   
    int e[10][10], dis[10], book[10], n, m, u, v, w;

    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = MAX_VAL;

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u][v] = w;
    }
    // 初始化dis数组
    for (int i = 1; i <= n; i++)
        dis[i] = e[1][i];

    for (int i = 1; i <= n; i++)
        book[i] = 0;

    book[1] = 1;

    for (int i = 1; i <= n - 1; i++)
    {
        // 找到离1号定点最近的点
        int node;
        int min = MAX_VAL;
        for (int j = 1; j <= n; j++)
        {
            if (book[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                node = j;
            }
        }
        // 用这个边去`松弛`所有的边, why this work?!
        book[node] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (e[node][v] < MAX_VAL)
            {
                if (dis[v] > dis[node] + e[node][v])
                    dis[v] = dis[node] + e[node][v];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}
