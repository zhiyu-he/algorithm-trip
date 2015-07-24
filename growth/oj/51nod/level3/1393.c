#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000002

char str[MAX_SIZE];

char stack[MAX_SIZE];
int sp = 0;

int sum[MAX_SIZE];
int pos_hash[MAX_SIZE] = { MAX_SIZE };
int neg_hash[MAX_SIZE] = { -MAX_SIZE };

int main()
{
  gets (str);
  
  int i = 0;
  sum[0] = 0;
  pos_hash[0] = 0;

  for (i = 1; i < MAX_SIZE; i++)
    pos_hash[i] = MAX_SIZE;
  for (i = 0; i < MAX_SIZE; i++)
    neg_hash[i] = MAX_SIZE;
  
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '0')
        sum[i + 1] += sum[i] + -1;
      else
        sum[i + 1] += sum[i] + 1;

      if (sum[i + 1] >= 0)
        {
          if (pos_hash[sum[i + 1]] > i + 1)
            pos_hash[sum[i + 1]] = i + 1;
        }
      else
        {
          if (neg_hash[-sum[i + 1]] > i + 1)
            neg_hash[-sum[i + 1]] = i + 1;
        }
      i++;
    }

  int distance = 0;
  int len = i; // 字符串长度
  //  for (i = 0; i <= len; i++)
  //    printf ("sum[%d] = %d\n", i, sum[i]);
  for (i = 0; i <= len; i++)
    {
      int temp = sum[i] >= 0 ? pos_hash[sum[i]] - i : neg_hash[-sum[i]] - i;
      temp = temp < 0 ? -temp : temp;
      distance = temp > distance ? temp : distance;
    }
  
  printf ("%d\n", distance);
  return 0;
}
