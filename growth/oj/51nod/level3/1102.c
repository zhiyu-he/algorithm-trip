#include <stdio.h>

#define MAX_SIZE 50002

long long A[MAX_SIZE];

long stack[MAX_SIZE]; // 里面放的是高度下标

int L[MAX_SIZE], R[MAX_SIZE];

int main()
{
  int i, n, t;
  scanf ("%d", &n);

  for (i = 1; i <= n; i++)
    scanf ("%lld", &A[i]);
  
  // 求每个A[i]作为高度时, 所能向左延伸的最大值
  t = 0;
  for (i = 1; i <= n; i++)
    {
      while (t > 0 && A[stack[t - 1]] >= A[i]) t--; // 当A[i - 1] >= A[i]时, 说明可以向左扩展
      L[i] = t == 0 ? 1 : (stack[t - 1] + 1);
      stack[t++] = i;
    }
  /*
  printf ("L ");
  for (i = 1; i <= n; i++)
    printf ("%d ", L[i]);
  printf ("\n");
  */
  
  // 求每一个A[i]作为高度时, 所能向右延伸的最大值
  t = 0;
  for (i = n; i > 0; i--)
    {
      while (t > 0 && A[stack[t - 1]] >= A[i]) t--;
      R[i] = t == 0 ? n : stack[t - 1] - 1;
      stack[t++] = i;
    }
  /*
  printf ("R ");
  for (i = 1; i<= n; i++)
    printf ("%d ", R[i]);
  printf ("\n");
  */
  long long max_area = 0;
  for (i = 1; i <= n; i++)
    if ((R[i] - L[i] + 1) * A[i] > max_area)
      max_area = (R[i] - L[i] + 1) * A[i];

  printf ("%lld\n", max_area);
  return 0;
}
