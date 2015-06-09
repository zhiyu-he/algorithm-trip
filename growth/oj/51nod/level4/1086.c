#include <stdio.h>


int weight[201]; // 重量
int value[201]; // 价值
int count[201]; // 数量


long f[50000] = { 0 };

long max_value (int kinds, int c)
{
  int i, j; //k; // 具备k种可能
  long max = 0;
  
  int split_size = 0;
  int cursor = 1;
  int split_weight[20001] = { 0 };
  int split_value[20001] = { 0 };

  for (i = 1; i <= kinds; i++)
    {
      int size = count[i];
      int s_i;
      for (s_i = 1; s_i <= size; s_i *= 2)
        {
          split_weight[cursor] = s_i * weight[i];
          split_value[cursor] = s_i * value[i];
          cursor++;
          size -= s_i;
          split_size++;
        }
      if (size > 0)
        {
          split_weight[cursor] = size * weight[i];
          split_value[cursor++] = size * value[i];
          split_size++;
        }
    }
  for (i = 1; i <= split_size; i++)
    for (j = c; j >= split_weight[i]; j--)
      {
        long answer = f[j - split_weight[i]] + split_value[i];
        if (f[j] < answer)
          f[j] = answer;
        if (f[j] > max)
          max = f[j];
      }
  return max;
}

int main()
{
  int n, c;
  scanf ("%d %d", &n, &c);
  
  int i;
  for (i = 1; i <= n; i++)
    {
      int size, w, v;
      scanf ("%d %d %d", &w, &v, &size);
      weight[i] = w;
      value[i] = v;
      count[i] = size;
    }

  long max = max_value(n, c);
  printf ("%ld\n", max);
  return 0;
}