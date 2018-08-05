#include <stdio.h>

#define MAX_VAL 999999

// 在 bellman-ford.c的基础上, 利用队列进行优化
// 当我们谈论优化, 那么我们要知道具体优化了什么
// 相比于第一版的bellman-ford算法, 其时间复杂度为O(N*M), 即N个定点M条边
// 由于大部分情况下可以提前结束, 均摊会小于O(N*M)

int main()
{
    int que[101], head = 1, tail = 1;
    int dis[6], book[6], u[8], v[8], w[8], first[6], next[8];
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++)
        dis[i] = MAX_VAL;
    dis[1] = 0;

    for (int i = 1; i <= n; i++)
        book[i] = 0;
    for (int i = 1; i <= n; i++)
        first[i] = -1;

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    que[tail] = 1;
    tail++;
    book[1] = 1;

    while (head < tail)
    {
        int k = first[que[head]];
        while (k != -1)
        {
            if (dis[v[k]] > dis[u[k]] + w[k])
            {
                dis[v[k]] = dis[u[k]] + w[k];
                if (book[v[k]] == 0)
                {
                    que[tail] = v[k];
                    tail++;
                    book[v[k]] = 1;
                }
            }
            k = next[k];
        }
        book[que[head]] = 0;
        head++;
    }

    for (int i = 1; i <= n; i++)
        printf("%10d", dis[i]);

    printf("\n");

    return 0;
}
