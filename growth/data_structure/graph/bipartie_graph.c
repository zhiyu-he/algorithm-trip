#include<stdio.h>

/*
 *  二分图定义: 如果一个图的所有顶点可以被分为X和Y两个集合, 并且所有边的
 *  两个顶点恰好一个属于集合X, 另一个属于集合Y, 即每个集合内的顶点没有边相连.
 *  那么此图就是二分图.
 *
 *  所谓求二分图的最大匹配, 即匹配对数最多.
 *  
 *  增广路的本质就是一条路径的起点和终点都是未被配对的.
 *  
 *  1. 如果e[u][v] == 1 but match[v] == 1 则, 让v去找一圈
 *  2. v找了一圈之后, 还不ok, 那么u就要换人了.
 *
 */


int n, m;
int book[101];
int e[101][101];
int match[101];


int dfs(int u)
{
    for(int i = 1; i <= n; i++)
    {
        if(book[i] == 0 && e[u][i] == 1)
        {
            book[i] = 1;
            if(match[i] == 0 || dfs(match[i]))
            {
                match[i] = u;
                match[u] = i;
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u][v] = 1;
        e[v][u] = 1;
    }

    for(int i = 1; i <= n; i++)
        match[i] = 0;
    
    int sum;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            book[j] = 0;
        if(dfs(i))
            sum++;
    }
    printf("%d", sum);
    return 0;
}
