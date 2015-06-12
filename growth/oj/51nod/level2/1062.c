#include <stdio.h>

int a[100002];

int max[1000001] = { 0 };
int res[10] = { 0 };
int main()
{
  int i;
  a[0] = 0;
  a[1] = 1;
  for (i = 1; i <= 50000; i++)
    {
      a[i * 2] = a[i];
      a[i * 2 + 1] = a[i] + a[i + 1];
    }

  //for (i = 1; i <= 10; i++)
  //printf ("a[%d] = %d\n", i, a[i]);

  int temp = 0;
  for (i = 1; i <= 100000; i++)
    {
      if (a[i] > temp)
        temp = a[i];
      max[i] = temp;
    }

  int t;
  scanf ("%d", &t);
  
  for (i = 0; i < t; i++)
    {
      int index;
      scanf ("%d", &index);
      res[i] = max[index];
    }
  for (i = 0; i < t; i++)
    printf ("%d\n", res[i]);
  
  return 0;
}
