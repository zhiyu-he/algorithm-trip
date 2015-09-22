#include <stdio.h>

#define LEN 1000

int a[LEN];


void print_answer(int c5, int c2)
{
  while (c5--)
    printf ("5");
  while (c2--)
    printf ("0");

  printf ("\n");
}



int main()
{
  int i, n;
  scanf ("%d", &n);

  int count_5 = 0;
  int count_0 = 0;
  
  for (i = 0; i < n; i++)
    {
      int num;
      scanf ("%d", &num);
      if (num == 5)
        count_5++;
      else
        count_0++;
    }
  
  
  int find_answer = 0;
  while (1)
    {
      if (count_5 < 9)
        break;
      
      if (count_5 * 5 % 9 == 0)
        {
          find_answer = 1;
          break;
        }
      
      count_5 = count_5 - count_5 % 9;
    }

  if (find_answer && count_0 > 0)
    {
      print_answer(count_5, count_0);
      return 0;
    }

  if (count_0 == 0)
    printf ("-1\n");
  else
    printf ("0\n");
  return 0;
}
