#include <stdio.h>

struct edge
{
    int u;
    int v;
    int w;
};

struct edge e[10];
int f[10];  // 并查集

void quick_sort(int left, int right)
{
    if (left > right)
        return;
    // 1. 选一个中枢
    struct edge t = e[left];
    
    int i, j;
    i = left;
    j = right;
    while (i != j && i < j)
    {
        // 从右->左, 找到第一个比`哨兵`小的
        while(i < j && t.w <= e[j].w)
            j--;
        while(i < j && t.w >= e[i].w)
            i++;
        
        if (i != j && i < j)
        {
            struct edge tmp = e[i];
            e[i] = e[j];
            e[j] = tmp;
        }
    }

    struct edge tmp = e[j];
    e[j] = e[left];
    e[left] = tmp;
    quick_sort(left, j-1);
    quick_sort(j+1, right);
    return;
}


int getf(int v)
{
    if(f[v] == v)
        return v;
    else
    {
        f[v] = getf(f[v]);
        return f[v];
    }
}

int merge(int v , int u)
{
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);

    if(t1 != t2)
    {
        f[t2] = t1;
        return 1;
    }
    return 0;
}

int main()
{   
    int n, m;   // n个顶点, m条边
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    quick_sort(1, m);

    // init union-find
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;   // 每个点的爸爸是自己
    }
    
    int count = 0;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if(merge(e[i].u, e[i].v))
        {
            count++;
            sum += e[i].w;
        }
        if(count == m-1)
            break;
    }
    
    printf("%d\n", sum);
    
    return 0;
}
