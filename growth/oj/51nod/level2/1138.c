#include <stdio.h>
#include <math.h>

long N;


int main()
{
  int flag = 1;
  scanf ("%ld", &N);

  long loop = (long)sqrt (2 * N + 1);
  for (; loop >= 2; loop--)
    {
      long temp = 2 * N - loop * (loop - 1);
      if (temp > 0)
        {
          long mod = 2 * loop;
          //          printf ("temp: %ld mod: %ld\n", temp, mod);
          if (temp % mod == 0)
            {
              flag = 0;
              printf ("%ld\n", temp / mod);
            }
        }
    }

  if (flag)
    printf ("No Solution\n");
  return 0;
}
