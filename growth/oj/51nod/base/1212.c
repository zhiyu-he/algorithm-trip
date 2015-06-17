/**
    利用prime算法实现
**/
#include <stdio.h>
#define MAX_VALUE 999999

int e[1001][1001];

int book[1001];
int dis[1001];
int n, m, count = 0;


int total_weight = 0;

int main()
{
  scanf ("%d %d", &n, &m);
  
  int i, j;
  
  // init
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      e[i][j] = i == j ? 0 : MAX_VALUE;

  for (i = 1; i <= m; i++)
    {
      int u, v, w;
      scanf ("%d %d %d", &u, &v, &w);
      e[u][v] = w;
      e[v][u] = w;
    }
  for (i = 1; i <= n; i++)
    dis[i] = e[1][i];


  // init 1号顶点
  book[1] = 1;
  count++;
  while (count < n)
    {
      int min = MAX_VALUE;
      int v = -1;
      for (i = 1; i <= n; i++)
        {
          if (book[i] == 0 && dis[i] < min)
            {
              //              printf ("dis[%d] = %d\n", i, dis[i]);
              min = dis[i];
              v = i;
            }
        }
      if (v != -1)
        {
          //          printf ("point: %d value: %d\n", v, min);
          total_weight += min;
          count++;
          book[v] = 1;
        }
      for (j = 1; j <= n; j++)
        {
          if (book[j] == 0 && dis[j] > e[v][j])
            {
              dis[j] = e[v][j];
            }
        }
    }

  printf ("%d\n", total_weight);
  
  return 0;
}