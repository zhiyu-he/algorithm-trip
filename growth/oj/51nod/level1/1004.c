#include <stdio.h>
#include <string.h>

int period[11] = { 0, 1, 4, 4, 2, 1, 1, 4, 4, 2 };
int main()
{
  char number[15];
  scanf ("%s", number);
  int len = strlen (number);
  int n = number[len - 1] - '0';
  unsigned long power = 0;
  int i;
  for (i = 0; i < len; i++)
    {
      power *= 10;
      power += number[i] - '0';
    }
  if (n == 0)
    printf ("0\n");
  else
    {
      int times = period[n];
      int mod = power % times;
      if (mod == 0)
        mod = times;
      int value = 1;
      while (mod > 0)
        {
          value *= n;
          if (value > 10)
	    {
	      value = value % 10;
	    }
	    mod--;
	  }
       printf ("%d\n", value);
    }
  return 0;
}