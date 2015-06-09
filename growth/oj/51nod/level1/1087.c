#include <stdio.h>
int check (long pos);
int main()
{
  long T[10000];
  int n;
  scanf ("%d", &n);
  
  int i;
  for (i = 0; i < n; i++)
    scanf ("%ld", &T[i]);
  
  for (i = 0; i < n; i++)
    {
      if (check (T[i]) == 1)
	    printf ("1\n");
      else
	    printf ("0\n");
    }
}


int check (long pos)
{
  long value = 1;
  int i;
  for (i = 1; i <= pos; i++)
    {
      value += (i - 1);
      if (value == pos)
	    return 1;
      if (value > pos)
	    return -1;
    }
  return -1;
}
