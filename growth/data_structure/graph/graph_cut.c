#include<stdio.h>

/*
 *  图的割点, 重点在于如何识别出某一个点为割点
 *  为每一个顶点维护两个序列
 *  序列1. dfs中第几个遍历到该节点的
 *  序列2. 该节点的最小父节点是谁
 *  
 *  进一步, 图的割边
 *  TIPS: low[v] > num[u], 如果low[v]==num[u]相等则表示还可以回到祖先(包含父亲)
 *
 */

int num[9], low[9], flag[9];
int e[9][9];
int idx, n, m, root = 1;

int min(int a, int b)
{
    return a < b ? a : b;
}

void dfs(int cur, int father)
{
    int child;
    // 处理当前节点
    idx++;
    num[cur] = idx;
    // 这个节点是需要被更新的, 当前处理到他, low[cur]=idx相当于默认值
    // 更新时机: 遍历所有与num相连的其他结点
    // a. 如果e[cur][i] == 1 同时num[i] == 0, 则先搜索后比较
    // b. 如果e[cur][i] == 1 同时num[i] != 0 && i != father, 则直接比较 low[i], low[cur]
    low[cur] = idx;
    
    for(int i=1; i <= n; i++)
    {
        if(e[cur][i] == 1)
        {
            if(num[i] == 0)
            {
                child++;
                dfs(i, cur);
                low[cur] = min(low[cur], low[i]);
                if(cur != root && low[i] >= num[cur])
                    flag[cur] = 1;
                // 如果当前结点是根结点，在生成树中根结点必须要有两个儿子，那么这个根结点才是割点
                if(cur == root & child == 2)
                    flag[cur] = 1;
            }
            else if(i != father)
            {
                low[cur] = min(low[cur], num[i]);
            }
        }
    }
}

int main()
{
    int x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            e[i][j] = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        e[x][y] = 1;
        e[y][x] = 1;
    }

    dfs(1, root);

    for(int i = 1; i <= n; i++)
    {
        if(flag[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
