#include <stdio.h>

#define LEN 101
#define MOD 1000000007
long M; // M次方
long N; // 矩阵的大小
long long matrix[LEN][LEN];
long long res[LEN][LEN];
long long t[LEN][LEN];

int init_flag = 1;


void init_t ()
{
  int i, j;
  for (i = 1; i <= N; i++)
    for (j = 1; j <= N; j++)
      t[i][j] = 0;
}

void quick_pow ()
{
  int i, j, inc;
  int c = 1;
  while (M)
    {
      if (M & 1)
        {
          if (init_flag)
            {
              for (i = 1; i <= N; i++)
                for (j = 1; j <= N; j++)
                  {
                    res[i][j] = matrix[i][j];
                  }
              init_flag = 0;
            }
          else
            {
              init_t ();
              for (i = 1; i <= N; i++)
                for (j = 1; j <= N; j++)
                  {
                    t[i][j] = 0;
                    inc = 1;
                    while (inc <= N)
                      {
                        t[i][j] += res[i][inc] * matrix[inc][j];
                        t[i][j] %= MOD;
                        inc++;
                      }
                  }
              for (i = 1; i <= N; i++)
                for (j = 1; j <= N; j++)
                  res[i][j] = t[i][j];
            }
        }
      
      M >>= 1;
      init_t ();
      for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
          {
            t[i][j] = 0;
            inc = 1;
            while (inc <= N)
              {
                t[i][j] += matrix[i][inc] * matrix[inc][j];
                t[i][j] %= MOD;
                inc++;
              }
          }
      for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
          matrix[i][j] = t[i][j];
      c++;
    }
}

int main()
{
  scanf ("%ld %ld", &N, &M);

  long j, i = 1;
  while (i <= N)
    {
      for (j = 1; j <= N; j++)
        scanf ("%lld", &matrix[i][j]);
      i++;
    }
  
  for (i = 1; i <= N; i++)
    for (j = 1; j <= N; j++)
      res[i][j] = 0;

  quick_pow ();
  
  for (i = 1; i <= N; i++)
    {
      for (j = 1; j <= N; j++)
        {
          printf ("%lld ", res[i][j]);
        }
      printf ("\n");
    }
  return 0;
}
