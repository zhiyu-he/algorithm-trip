#include <stdio.h>

// 目标与dfs3.c做的事情一样
//
//
//
int m, n, min = 100000;
int matrix[100][100];
int book[100][100];

int begin_x, begin_y;
int target_x, target_y;

int orient[4][2] = {
	 {0, 1}, // 向右走
	 {0, -1},// 向左走
	 {1, 0}, // 向上走
	 {-1, 0} // 向下走
};

struct node
{
    int x;
    int y;
    int s;
};

struct node q[10000];

int head, tail;

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
    
    // init
    head = tail = 1;
    
    q[tail].x = begin_x;
    q[tail].y = begin_y;
    q[tail].s = 0;
    tail += 1;
    
    int flag = 0;
    int cur_x = q[head].x;
    int cur_y = q[head].y;

    if (cur_x == target_x && cur_y == target_y)
    {
        flag = 1;
    }


    while (head < tail && flag == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            int next_x = q[head].x + orient[i][0];
            int next_y = q[head].y + orient[i][1];
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
            {
                continue;
            }
            if (matrix[next_x][next_y] == 0 && book[next_x][next_y] == 0)
            {
                book[next_x][next_y] = 1;
                q[tail].x = next_x;
                q[tail].y = next_y;
                q[tail].s = q[head].s + 1;
                tail += 1;
            }
            if (next_x == target_x &&next_y == target_y)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
        head += 1;
    }

    if (flag == 1)
    {
        printf("%d\n", q[tail-1].s);
    }

	return 0;
}
