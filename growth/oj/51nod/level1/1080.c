#include <stdio.h>
#include <math.h>


long N;

int find_answer (long limit)
{
  long i = 0;
  long j = limit;
  int count = 0;
  while (i <= j)
    {
      //      printf ("i: %ld j: %ld\n", i, j);
      long temp = i * i + j * j;
      if (temp > N)
        {
          j--;
        }
      else if (temp < N)
        {
          i++;
        }
      else
        {
          printf ("%ld %ld\n", i, j);
          i++;
          j--;
          count++;
        }
    }
  return count;
}

int main()
{
  scanf ("%ld", &N);
  
  long limit = (long) sqrt (N);

  if (find_answer (limit) == 0)
    printf ("No Solution\n");
  return 0;
}
