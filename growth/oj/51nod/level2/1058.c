#include <stdio.h>
#include <math.h>

/**

   在求树高的时候有应用
 **/
long stirling (int n)
{
  if (n == 1)
    return 1;
  else
    return (long) ((log10 (sqrt(4.0 * acos (0.0) * n)) + n * (log10 (n) - log10 (exp(1.0)))) + 1 );
}

int main()
{
  int N;
  scanf ("%d", &N);
  printf ("%ld\n", stirling (N));
  return 0;
}
