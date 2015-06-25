#include <stdio.h>

int one_count = 0;
int two_count = 0;
int other_count = 0;
int n;


int ap_sum (int num)
{
  return (1 + num) * num / 2;
}

int main()
{
  scanf ("%d", &n);
  int i;
  for (i = 1; i <= n; i++)
    {
      long long num;
      scanf ("%lld", &num);
      if (num == 1)
        one_count++;
      else if (num == 2)
        two_count++;
      else
        other_count++;
    }

  long long result = 0;
  // 处理1
  if (one_count != 0)
    {
      result += (other_count + two_count) * one_count;
      result += 2 * ap_sum (one_count - 1);
    }
  // 处理2
  if (two_count != 0)
      result += ap_sum (two_count - 1);
  printf ("%lld\n", result);
  return 0;
}
