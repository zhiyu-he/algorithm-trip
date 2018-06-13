#include<stdio.h>

#define SIZE 101

int w[SIZE];
int p[SIZE];
int book[SIZE];

int max_value;
int cap;
int num;

void dfs(int cur_c, int cur_val);

int main()
{
    scanf("%d %d", &num, &cap);
    int i;
    for (i = 0; i < num; i++)
    {
        scanf("%d %d", &w[i], &p[i]);
    }
    dfs(0, 0);

    printf("%d\n", max_value);
}

void dfs(int cur_c, int cur_val)
{
    if (cur_c > cap)
    {
        return;
    } else {
        if (cur_val > max_value) {
            max_value = cur_val;
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (book[i] == 0) {
            book[i] = 1;
            cur_c += w[i];
            cur_val += p[i];
            dfs(cur_c, cur_val);
            cur_c -= w[i];
            cur_val -= p[i];
            book[i] = 0;
        }
    }
}
