#include<stdio.h>

// 输出一串数字的全排列
//
//
//
//

int n;
int a[100];
int book[100];
int tmp[100];

void dfs(int step)
{
    if (step == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", tmp[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (book[a[i]] == 0)
        {
            tmp[step] = a[i];
            book[a[i]] = 1;
            dfs(step+1);
            book[a[i]] = 0;
        }
    }
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(0);
    return 0;
}
