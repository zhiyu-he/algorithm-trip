#include <stdio.h>
#include <math.h>

/**

   在求树高的时候有应用
**/
long long stirling (long n)
{
  if (n == 1)
    return 1;
  else
    return (long long) ((log10 (sqrt(4.0 * acos (0.0) * n)) + n * (log10 (n) - log10 (exp(1.0)))) + 1 );
}

long number[1001];

int main()
{
  int N;
  scanf ("%d", &N);
  int i;
  for (i = 1; i <= N; i++)
    scanf ("%ld", &number[i]);

  for (i = 1; i <= N; i++)
    printf ("%lld\n", stirling (number[i]));
  return 0;
}
