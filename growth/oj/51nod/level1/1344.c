#include <stdio.h>

long long grid[50000];

long long min_energy(int right, long init)
{
  //  printf ("right: %d\n", right);
  long long min = 0;
  long long energy = init;
  int i;
  for (i = 0; i <= right; i++)
    {
      long long temp = energy = energy + grid[i];
      if (temp < 0)
        {
          min += -temp;
          energy = 0;
        }
    }
  return min;
}

int main()
{
  int n;
  scanf ("%d", &n);
  
  int i, right;
  for (i = 0; i < n; i++)
    {
      scanf ("%lld", &grid[i]);
      if (grid[i] < 0)
        right = i;
    }
  printf ("%lld\n", min_energy(right, 0));
  return 0;
}
