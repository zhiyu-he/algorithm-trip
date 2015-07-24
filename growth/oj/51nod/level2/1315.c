#include <stdio.h>

#define MAX_SIZE 50
#define INF 1000000000

long number[MAX_SIZE];

int bit_count[32] = {0};
int main()
{
  //  printf ("%ld\n", LONG_MAX);
  
  int n;
  long x;
  scanf ("%d %ld", &n, &x);
  
  int i;
  for (i = 0; i < n; i++)
    scanf ("%ld", &number[i]);
  
  long or_res = 0;
  
  for (i = 0; i < n; i++)
    {
      if ((number[i] & ~x) != 0) // 判断一个number是否会对x中二进制为1位，有所贡献
        continue;
      or_res |= number[i];
      int q = 0;
      while (number[i])
        {
          if (number[i] & 1)
            bit_count[q] += 1;
          q++;
          number[i] >>= 1;
        }
    }

  if (or_res < x)
    {
      printf ("0\n");
      return 0;
    }

  int q = 0;
  int min = INF;
  while (x)
    {
      if (x & 1)
        {
          min = min > bit_count[q] ? bit_count[q] : min;
        }
      q++;
      x >>= 1;
    }
  printf ("%d\n", min);
  return 0;
}
