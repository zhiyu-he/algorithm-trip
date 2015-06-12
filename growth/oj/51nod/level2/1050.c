#include <stdio.h>


long long number[50000];


long long min_sum = 0; // 最小的字段和
long long max_sum = 0; // 最大的字段和
long long total_sum = 0; // 全量数组之和

void cal_min_sum (int length)
{
  int i;
  long long mid = 0;
  for (i = 1; i <= length; i++)
    {
      mid = mid + number[i - 1] > number[i - 1] ? number[i - 1] : mid + number[i - 1];
      if (mid < min_sum)
        min_sum = mid;
    }
}

void cal_max_sum (int length)
{
  int i;
  long long mid = 0;
  for (i = 1; i <= length; i++)
    {
      mid = mid + number[i - 1] > number[i - 1] ? mid + number[i - 1] : number[i - 1];
      if (mid > max_sum)
        max_sum = mid;
    }
}


int main()
{
  int n;
  scanf ("%d", &n);
  int i;
  int has_answer = 0;
  for (i = 0; i < n; i++)
    {
      scanf ("%lld", &number[i]);
      if (number[i] > 0)
        {
          has_answer = 1;
        }
      total_sum += number[i];
    }
  if (has_answer == 0)
    printf ("0\n");
  else
    {
      cal_max_sum (n);
      cal_min_sum (n);

      if (max_sum >= (total_sum - min_sum))
        printf ("%lld\n", max_sum);
      else
        printf ("%lld\n", (total_sum - min_sum));
    }
  return 0;
}
