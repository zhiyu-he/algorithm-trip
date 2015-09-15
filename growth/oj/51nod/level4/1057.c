#include <stdio.h>

#define FACTORIAL_LEN 10001

#define SCALE 1000000000

//char F[FACTORIAL_LEN][10];
long long F[FACTORIAL_LEN] = { 0 };

/**
   F[i]的每一位，保存阶乘的一个数位
   例如4! = 1 * 2 * 3 * 4 = 24 即F[0] = 4 F[1] = 2
 */
int main()
{
  int n;
  scanf ("%d", &n);
  
  F[0] = 1;
  int i, j;
  for (i = 2; i <= n; i++)
    {
      long long ca = 0; // carry-on
      for (j = 0; j < FACTORIAL_LEN; j++)
        {
          long long res = F[j] * i + ca;
          F[j] = res % SCALE;
          ca = res / SCALE;
          //          printf ("F[%d] = %d\n", j, F[j]);
        }
    }


  j = FACTORIAL_LEN - 1;
  while (F[j] == 0)
    j--;
  //  printf ("j: %d\n", j);
  int flag = 1;
  while (j >= 0)
    {
      long long print = F[j];
      //      printf ("--%ld\n", print);
      int fix_zero = 0;
      while (print != 0)
        {
          fix_zero++;
          print /= 10;
        }
      //      printf ("fix_zero: %d\n", fix_zero);
      if (F[j] > 0)
        {
          fix_zero = 9 - fix_zero;
          while (!flag && fix_zero--)
            printf ("0");
          printf ("%lld", F[j]);
        }
      else
        printf ("000000000");
      j--;
      flag = 0;
    }

  printf ("\n");
  return 0;
}
