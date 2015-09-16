#include <stdio.h>


#define MAX_SIZE 200001

int main()
{
  int k, n, i;

  scanf ("%d %d", &k, &n);
  
  int even = 0;
  int odd = 0;

  for (i = 0; i < k; i++)
    {
      long size;
      scanf ("%ld", &size);
      if (size % 2 == 0)
        even++;
      else
        odd++;
    }
  // Daenerys
  // Stannis
  if (n == k)
    {
      if (odd & 1)
        {
          printf ("Stannis\n");
          return 0;
        }
      else
        {
          printf ("Daenerys\n");
          return 0;
        }
    }
  
  int times = k - n;

  if (times / 2 >= odd)
    {
      printf ("Daenerys\n");
      return 0;
    }

  if ((n & 1) == 1 && (k - n) / 2 >= even)
    {
      printf ("Stannis\n");
      return 0;
    }

  if ((n & 1) == 0 && (k - n) / 2 >= even)
    {
      printf ("Daenerys\n");
      return 0;
    }

  if (times & 1)
    {
      // 偶数被弄干净的场景
      /*
      if ((n & 1) == 1 && (k - n) / 2 >= even)
        {
          printf ("Stannis\n");
          return 0;
        }
      */
      // 没处理干净，大家都有
      printf ("Stannis\n");
      return 0;
    }
  else
    {
      /*
      if ((n & 1) == 0 && (k - n) / 2 >= even)
        {
          printf ("Daenerys\n");
          return 0;
        }
      */
      printf ("Daenerys\n");
      return 0;
    }
  return 0;
}
