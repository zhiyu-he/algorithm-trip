#include <stdio.h>

#define LEN 500

long long matrix[LEN][LEN];

long long dp[LEN][LEN]; // i, 代表行, j代表列

long long c[LEN];

int is_negative = 1;

void init_c ()
{
  int i = 0;
  while (i < LEN)
    c[i++] = 0;
}

long long max_segment (int col)
{
  long long max = 0;
  long long mid = 0;
  int i;
  /*
  printf ("c[k]: ");

  for (i = 0; i < col; i++)
    printf ("%lld ", c[i]);
  printf ("\n");
  */
  for (i = 0; i < col; i++)
    {
      mid = mid + c[i] > c[i] ? mid + c[i] : c[i];
      if (mid > max)
        max = mid;
    }
  return max;
}

long long max_sum (int m, int n)
{
  long long max = 0;
  long long mid = 0;
  int i, j, k;
  for (i = 0; i < m; i++)
    {
      init_c ();
      for (j = i; j < m; j++)
        {
          for (k = 0; k < n; k++)
            {
              c[k] = i == j ? matrix[i][k] : (c[k] + matrix[j][k]);
            }
          mid = max_segment (n);
          if (mid > max)
            max = mid;
        }
    }
  return max;
}

int main ()
{
  int m, n; // m为列, n为行
  scanf ("%d %d", &m, &n);
  
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      {
        scanf ("%lld", &matrix[i][j]);
        if (matrix[i][j] > 0)
          is_negative = 0;
      }
  
  if (is_negative)
    printf ("0\n");
  else
    printf ("%lld\n", max_sum (n, m));
  return 0;
}
