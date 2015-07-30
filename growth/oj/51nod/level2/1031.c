#include <stdio.h>

#define MOD 1000000007

/**
   对于n来说，n有两种可能，即 基数与偶数那么f(1) = 1 f(2) = 2
   当为3的时候 实际可选择的应该是f(3) = f(3 - 1) + f(3 - 2)
   那么到f(n) = f(n - 1) + f (n - 2)
   
**/
long long f (int n)
{
  long long sum, f1, f2;
  f1 = 1;
  f2 = 2;
  int i;
  for (i = 3; i <= n; i++)
    {
      sum = (f1 + f2) % MOD;
      f1 = f2 % MOD;
      f2 = sum % MOD;
    }
  return sum;
}

int main()
{
  int n;
  scanf ("%d", &n);
  
  if (n == 1)
    printf ("1\n");
  else if (n == 2)
    printf ("2\n");
  else
    printf ("%lld\n", f(n));

  return 0;
}
