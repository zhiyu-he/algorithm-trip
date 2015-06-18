#include <stdio.h>


long long q_pow (long long a, long long b, long long c)
{
  long long A = a;
  long long ret = 1;
  while (b)
    {
      if (b % 2 != 0)
        {
          ret *= A;
          ret %= c;
        }
      A = A*A % c;
      b >>= 1;
    }

  return ret;
}

int main()
{
  long long a, b, c;
  scanf ("%lld %lld %lld", &a, &b, &c);
  printf ("%lld\n", q_pow (a, b, c));
  return 0;
}