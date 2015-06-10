#include <stdio.h>

unsigned long long square_sum[1000001] = {0};

unsigned long long to_answer[1000];

int is_relation_with7(unsigned int n)
{
  if (n % 7 == 0) return 1;
  
  while (n > 0)
    {
      if (n % 10 == 7) return 1;
      n /= 10;
    }
  return 0;
}

int main()
{
  
  int t;
  scanf ("%d", &t);
  
  int i;
  unsigned long long max_in = 0;
  for (i = 0; i < t; i++)
    {
      scanf ("%lld", &to_answer[i]);
      if (to_answer[i] > max_in)
        max_in = to_answer[i];
    }
    
  unsigned long long n = 1;
    

  while (n <= max_in)
    {
      square_sum[n] = is_relation_with7(n) == 0 ? square_sum[n - 1] + n * n : square_sum[n - 1]; 
      n++;
    }

  for (i = 0; i < t; i++)
    {
      printf ("%llu\n", square_sum[to_answer[i]]);
    }
  return 0;
}
