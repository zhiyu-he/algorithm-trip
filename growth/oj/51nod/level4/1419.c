#include <stdio.h>

long long gcd (long long a1, long long a2)
{
  long long last, res;
  res = a1 % a2;
  if (res == 0)
    return a2;
  while (res != 0)
    {
      last = res;
      a1 = a2;
      a2 = res;
      res = a1 % a2;
    }
  return last;
}

long long lcm (long long a1, long long a2)
{
  //  return a1 / g * a2;
  return a1 / gcd (a1, a2) * a2;
}

int main()
{
  long long n;
  scanf ("%lld", &n);
  
  if (n < 3)
    {
      printf ("%lld\n", n);
      return 0;
    }

  // 奇数情况
  if (n % 2 == 1)
    {
      printf ("%lld\n", n * (n - 1) * (n - 2));
      return 0;
    }

  // 偶数情况
  long long max_lcm = -1;
  int i, j, k;
  long long limit = n - 10 > 0 ? n - 10 : 1;
  for (i = n; i >= limit; i--)
    for (j = n - 1; j >= limit; j--)
      for (k = j - 1; k >= limit; k--)
        {
          if (i < 0 || j < 0 || k < 0)
            continue;
          long long _lcm = lcm (lcm (i, j), k);
          if (_lcm > max_lcm)
            max_lcm = _lcm;
        }

  printf ("%lld\n", max_lcm);
  return 0;
}