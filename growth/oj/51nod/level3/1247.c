#include <stdio.h>

#define MAX_Q 5000

char bool[MAX_Q];
/**

   求a1与a2的最大公约数
   同时，保证a1 >= a2
*/
long long gcd(long long a1, long long a2)
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

  int q;
  scanf ("%d", &q);
  int i = 0;
  while (i < q)
    {
      long long a, b, x, y;
      scanf ("%lld %lld %lld %lld", &a, &b, &x, &y);
      bool[i] = gcd (a, b) == gcd (x, y);
      i++;
    }

  for (i = 0; i < q; i++)
    {
      if (bool[i])
        printf ("Yes\n");
      else
        printf ("No\n");
    }
  return 0;
}
