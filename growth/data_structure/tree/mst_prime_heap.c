#include<stdio.h>

#define inf 999999

int dis[7];
int book[7];

int h[7], pos[7], size; // h保存堆, pos用来记录每个顶点在堆中的位置, size为堆大小

void swap(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    
    // update pos
    t = pos[h[x]];
    pos[h[x]] = pos[h[y]];
    pos[h[y]] = t;
}

// 最小堆含义为父节点, 小于所有子节点
void siftdown(int i)
{
    int flag = 0;
    while(i*2 <= size && flag == 0) // left-child: i*2
    {
       // 本质上为在i、i*2、i*2+1 中选出最小的那个
        int min_idx = i;
        if(dis[h[i]] > dis[h[i*2]])
            min_idx = i*2;
        if (i*2+1 <= size && dis[h[min_idx]] > dis[h[i*2+1]])
            min_idx = i*2 + 1;

        if(min_idx != i)
        {
            swap(min_idx, i);
            i = min_idx;
        } else {
            flag = 1;
        }
    }
}

void siftup(int i)
{
    int flag = 0;
    if(i == 1) return;
    // 本质上, 在i, i/2 之间选择更小的那个
    while(i != 1 && flag == 0)
    {
        if(dis[h[i]] < dis[h[i/2]])
            swap(i, i/2);
        else
            flag = 1;
        i = i/2;
    }
}

int pop()
{
    int t;
    t = h[1];
    pos[t] = 0;
    h[1] = h[size];
    pos[h[1]] = 1;
    size--;
    siftdown(1);
    return t;
}

int main()
{
    int n, m;
    int u[19], v[19], w[19], first[7], next[19];

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    
    // 无向图, 所以需要将所有的边再反向存储一遍
    for(int i=m+1; i <= 2*m; i++)
    {
        u[i] = v[i-m];
        v[i] = v[i-m];
        w[i] = v[i-m];
    }
    
    // 使用邻接表存储
    for(int i=1; i <=n; i++)
        first[i] = -1;

    for(int i = 1; i <= 2*m; i++)
    {
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    int count = 0;
    int sum = 0;
    book[1] = 1;
    count++;

    // 初始化dis数组, 这里是1号顶点到其余各个顶点的初始距离
    dis[1] = 0;
    for(int i = 2; i <= n; i++)
        dis[i] = inf;
    
    int k = first[1];
    while(k != -1)
    {
        dis[v[k]] = w[k];
        k = next[k];
    }
    // init heap
    size = n;
    for(int i = 1; i <= size; i++)
    {
        h[i] = i;
        pos[i] = i;
    }
    for(int i = size/2; i >= 1; i--)
        siftdown(i);

    pop();
    
    while(count < n)
    {
        int j = pop();
        book[j] = 1;
        count++;
        sum += dis[j];

        k = first[j];
        while(k != -1)
        {
            if(book[v[k]] == 0 && dis[v[k]] > w[k])
            {
                dis[v[k]] = w[k];
                siftup(pos[v[k]]);
            }
            k = next[k];
        }
    }
    printf("%d", sum);

    return 0;
}
