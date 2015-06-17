/**
   
   方法1:
   
   如果用队列反推的话相当于1, 2, 4, 8 ... n
   根据等比数列求和公式 a1 = 1  s = (1 - 2^n) / (1 - 2) 
   相当于指数级别的
   
   方法2:

   利用数学公式推导 f (n, k) = (f(n - 1, k) + k) mod n
   for (1, k) = 1;
 **/

#include <stdio.h>

int n, k;

int main()
{
  scanf ("%d %d", &n, &k);
  int i;
  int s = 0;
  for (i = 2; i <= n; i++)
    {
      s = (s + k) % i;
    }
  printf ("%d\n", s + 1);
  return 0;
}
