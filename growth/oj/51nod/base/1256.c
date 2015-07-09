#include <stdio.h>

long exgcd (long a, long b, long *x, long *y)  
{  
  if (b == 0) 
    {
      *x = 1;
      *y = 0;
      return a;
    }  
  else   
    {  
      long d = exgcd (b, a % b, x, y);  
      long t = *x;  
      *x = *y;
      *y = t - a / b * (*y);
      return d;
    }
}

long inverse(long num, long mod)  
{  
  long x, y;  
  exgcd (num, mod, &x, &y);
  while (x < 0)
    x += mod, y -= num;
  return x;
}


int main()
{

  long m, n;
  scanf ("%ld %ld", &m, &n);

  printf ("%ld\n", inverse (m, n));

  return 0;
}
