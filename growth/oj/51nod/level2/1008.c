#include <stdio.h>

/**
   N! = (N - 1) * N
   a * b mod p = a % p * b % p

   res = (N - 1) % p
   对于最后的结果 就是 res * i % p
 */
int main()
{
  long long N, P;
  scanf ("%lld %lld", &N, &P);
  
  long long i, res = 1; // res 是已经取过MOD的

  if (N == 1)
    {
      printf ("%lld\n", N % P);
      return 0;
    }

  for (i = 2; i <=  N; i++)
    {
      res = res * i % P;
      if (res == 0)
        break;
    }

  printf ("%lld\n", res);
}
