#include <stdio.h>

// 寻找图中指定的位置?
// m x n, m行n列
// 0:空地 1: 障碍物
/*  
 *  5 4
	0 0 1 0
	0 0 0 0
	0 0 1 0
	0 1 0 0
	0 0 0 1
	0 0 3 2
	7
 *
 */

/*
 * DFS: 本身关注的就是,当前我做什么,以及下一步我要做什么.
 * 缺点: 如果递归的太深,stackoverflow. GG
 */

int m, n, min = 100000;
int matrix[100][100];

int begin_x, begin_y;
int target_x, target_y;

int orient[4][2] = {
    {0, 1}, // 向右走
    {0, -1},// 向左走
    {1, 0}, // 向上走
    {-1, 0} // 向下走
};

int book[100][100];

void dfs(int x, int y, int step);

int main()
{
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    scanf("%d %d %d %d", &begin_x, &begin_y, &target_x, &target_y);
    
    book[begin_x][begin_y] = 1;
    dfs(begin_x, begin_y, 0);

    printf("%d\n", min);
    return 0;
}

void dfs(int x, int y, int step)
{
    // 判断当前点
    if (x == target_x && y == target_y)
    {
        if (step < min)
        {
            min = step;
        }
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        // 此处有4个方向可以搞搞
        int next_x = x + orient[i][0];
        int next_y = y + orient[i][1];
        if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
        {
            continue;
        }

        if (book[next_x][next_y] == 0 &&  matrix[next_x][next_y] == 0)
        {
            book[next_x][next_y] = 1;
            dfs(next_x, next_y, step+1);
            book[next_x][next_y] = 0;
        }
    }
    return;
}
