#include <stdio.h>
#include <math.h>

long long R;

int main()
{
  int t;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%lld", &R);
      long long D = 2 * R;
      printf ("%lld\n", D);
    }
  return 0;
}
