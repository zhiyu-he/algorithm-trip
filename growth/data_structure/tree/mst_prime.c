#include<stdio.h>


#define inf 999999

int e[10][10];
int dis[10];    //各个点到生成树的最小距离
int book[10];
int sum = 0;
int main()
{
    int n, m;   // n个顶点, m条边
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[u][v] = w;
        e[v][u] = w;
    }
    // dis中保存的是每个点到最小生成树最小的距离; 当前求解中, 假设了选取1号顶点作为开始
    for(int i = 1; i <= n; i++)
        dis[i] = e[1][i];
    
    int count = 0;
    book[1] = 1;        // 这里默认选择了1号顶点作为出发点.
    count++;
    while(count < n)
    {
        int min = inf;
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            if(book[i] == 0 && dis[i] < min)
            {
                min = dis[i];
                j = i;
            }
        }
        book[j] = 1;
        count++;
        sum = sum+dis[j];
        // 这个是说, 我现在找到了一个j, 我想知道这个j 到这棵树最小的距离
        for(int k = 1; k<=n; k++)
        {
            if(book[k] == 0 && dis[k] > e[j][k])
                dis[k] = e[j][k];
        }
    }
    printf("%d", sum);
    return 0;
}
