#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000002 // 考虑有\0
char str[MAX_SIZE];

int check_symmetry_str ();

int main()
{
  gets (str);
  
  long len = strlen (str);

  if (len % 2 != 0)
    {
      printf ("NO\n");
      return 0;
    }
  else
    {
      long i = 0, half = len / 2;
      
      while (i < half)
        {
          if (str[i] != str[i + half])
            {
              printf ("NO\n");
              return 0;
            }
          i++;
        }
    }
  printf ("YES\n");
  return 0;
}
