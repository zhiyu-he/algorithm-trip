#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007


/**
   2^0 = 1 2^1 = 2 2^2 = 4 ......
   
   f (1) = f (2 * 0 + 1) = 1
   f (2) = f (2 * 1)     = 2
   f (3) = f (2 * 1 + 1) = f (2) = 2
   f (4) = f (2 * 2) = f(3) + f(2) = 4
   f (5) = f (2 * 2 + 1) = f (4) = 4
   f (6) = f (2 * 3) = f (5) + f (3) = 6
   f (7) = f (2 * 3 + 1) = f (6) = 6

   f (1) = 1;
   f (2m + 1) = f (2m)        // 必然包含一个1, 如果砍去1，将2m的每种解 + 1，则为2m + 1
   f (2m) = f (2m - 1) + f(m) // 可能包含1 可能不包含
 **/
long long f (long N)
{
  long long *sum = (long long *) malloc (sizeof (long long) * (N + 1));
  sum[1] = 1;
  long i;
  for (i = 2; i <= N; i++)
    {
      if (i % 2)
        sum[i] = sum[i - 1];
      else
        sum[i] = sum[i - 1] + sum[i / 2];
      
      sum[i] %= MOD;
    }
  return sum[N];
}

int main()
{
  long N;
  scanf ("%ld", &N);
  
  if (N == 1)
    printf ("1\n");
  else
    printf ("%lld\n", f (N));

  return 0;
}
