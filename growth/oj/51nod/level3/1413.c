#include <stdio.h>
#include <string.h>


int check_zero (char num[], int len)
{
  int i = 0;
  while (i < len)
    {
      if (num[i] != '0')
        return i;
      i++;
    }
  return -1;
}

int main()
{

  char number[10];

  gets (number);
  
  int len = strlen (number);
  int res = 0;
  int i = 0;
  
  while ((i = check_zero (number, len)) != -1)
    {
      while (i < len)
        {
          if (number[i] != '0')
            {
              int num = number[i] - '0';
              num--;
              number[i] = num + '0';
            }
          i++;
        }
      res++;
    }
  printf ("%d\n", res);
  return 0;
}
