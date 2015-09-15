#include <stdio.h>
#include <string.h>

#define LEN 1001

/**

   正整数k的导数1/k，要么被整除了，要么存在循环节
   同时，循环节的长度，一定小于k
   这个貌似可以根据容斥原理解释？
 */

int cache[LEN];

void clear_cache()
{
  memset(cache, 0, sizeof(cache));
}

int cal_loop (int num)
{
  
  int count = 1;
  int i = 1;
  
  // 直接可以整出的情况
  if (i % num == 0)
    return 0;
  
  while (1)
    {
      i *= 10;
      //      int quotient = i / num;
      int mod = i % num;
      //      printf (" %d / %d = %d .. %d\n", i, num, quotient, mod);
      if (mod == 0 || cache[mod] > 0)
        {
          count = count - cache[mod];
          break;
        }
      else
        {
          i = mod;
          cache[mod] = count;
          count++;
        }
    }

  return count;
}

int main()
{
  int n;
  int max_loop = 0;
  int max_num = 0;
  scanf ("%d", &n);

  //  printf ("%d\n", cal_loop (n));
  
  int i = 1;
  while (i <= n)
    {
      clear_cache ();
      //      printf ("num: %d loop: %d\n", i, cal_loop (i));
      int loop = cal_loop (i);
      if (loop > max_loop)
        {
          max_loop = loop;
          max_num = i;
        }
      i++;
    }

  printf ("%d\n", max_num);
  
  return 0;
}
