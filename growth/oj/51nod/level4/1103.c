#include <stdio.h>


#define MAX_SIZE 50001

long long A[MAX_SIZE];
long long sum_n[MAX_SIZE] = { 0 };
int r[MAX_SIZE];

/**
   根据抽屉原理，本题一定有解
 **/
int main()
{
  int i, N;
  scanf ("%d", &N);

  int len = 0, pos = 0, start = 1;
  for (i = 1; i <= N; i++)
    {
      scanf ("%lld", &A[i]);
      if (len != 0) continue;

      sum_n[i] = (sum_n[i - 1] + A[i]) % N;
      if (sum_n[i] == 0) // 可以满足答案需求
        {
          //          printf ("i: %d", i);
          len = i;
          pos = i;
          start = 1;
          continue;
        }

      if (r[sum_n[i]] == 0)
        r[sum_n[i]] = i;
      else
        {
          //          printf ("i: %d r: %d", i, sum_n[i]);
          len = i - r[sum_n[i]];
          pos = i;
          start = r[sum_n[i]] + 1;
        }
    }
  
  printf ("%d\n", len);
  for (i = start; i <= pos; i++)
    printf ("%lld\n", A[i]);
  return 0;
}
