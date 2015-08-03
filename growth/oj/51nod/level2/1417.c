#include <stdio.h>

int t;

long long gcd (long long a1, long long a2)
{
  long long last, res;
  res = a1 % a2;
  if (res == 0)
    return a2;
  while (res != 0)
    {
      last = res;
      //      printf ("a1: %ld a2: %ld res: %ld\n", a1, a2, res);
      a1 = a2;
      a2 = res;
      res = a1 % a2;
    }
  return last;
}

int main()
{
  scanf ("%d", &t);

  while (t--)
    {
      long long a, b;
      scanf ("%lld %lld", &a, &b);
      long long x = a + 3 * b;
      long long y = 4 * (a + b);
      long long g = gcd (x, y);
      printf ("%lld/%lld\n", x / g, y / g);
    }
  return 0;
}
