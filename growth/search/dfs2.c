#include<stdio.h>

// [][][] + [][][] = [][][], 1~9的数字, 使用1次
//
//
//
//
int n;
int a[11];
int book[11];
void dfs(int step)
{
    if (step == n-1)
    {   
        int num1 = a[0] * 100 + a[1] * 10 + a[2];
        int num2 = a[3] * 100 + a[4] * 10 + a[5];
        int num3 = a[6] * 100 + a[7] * 10 + a[8];
        if (num1 + num2 == num3)
        {
            printf("%d + %d = %d\n", num1, num2, num3);
        }
        return;
    }
    
    for (int i = 1; i < n; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            a[step] = i;
            dfs(step+1);
            book[i] = 0;
        }
    }
}


int main()
{
    n = 10;
    dfs(0);
    return 0;
}
