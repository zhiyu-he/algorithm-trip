#include <stdio.h>


#define MOD 1000000007

long row, col;

long long exgcd (long long a, long long b, long long *x, long long *y)  
{  
  if (b == 0) 
    {
      *x = 1;
      *y = 0;
      return a;
    }  
  else   
    {  
      long long d = exgcd (b, a % b, x, y);  
      long long t = *x;  
      *x = *y;
      *y = t - a / b * (*y);
      return d;
    }
}

long long inverse(long long num, long long mod)  
{  
  long long x, y;  
  exgcd (num, mod, &x, &y);
  while (x < 0)
    x += mod, y -= num;
  return x;
}

long long p (int m, int n)
{
  //  printf ("m: %d n: %d\n", m, n);
  long _m = m;
  long _n = n;
  long long a = 1;
  long long b = 1;
  int times = 1;

  while (times <= n)
    {
      a *= _m;
      a %= MOD;
      times++;
      _m--;
    }
  //  printf ("res: %lld\n", res);
  
  if (m != n)
    {
      times = 1;
      while (times <= n)
        {
          b *= _n;
          b %= MOD;
          times++;
          _n--;
        }
    }

  long long k = inverse (b, MOD);

  return a * k % MOD;
}

int main()
{
  scanf ("%ld %ld", &row, &col);
  
  row -= 1;
  col -= 1;
  long m = row + col;
  
  // 一共需要走的步数为 step = (row - 1) + (col - 1)，然后做排列组合p(step, x)
  printf ("%lld\n", p (m, row == 0 ? col : row));
  return 0;
}
