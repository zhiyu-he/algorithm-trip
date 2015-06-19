#include <stdio.h>

int main()
{
  long long N;
  scanf ("%lld", &N);

  int count = 0;

  while (N)
    {
      count += N / 5;
      N /= 5;
    }

  printf ("%d\n", count);
  return 0;
}
