#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 41

int nums[MAX_LENGTH];
int n;
int flag;

int sub1[MAX_LENGTH], sub2[MAX_LENGTH];
int answer[5];

void dfs (int i, int len1, int len2, int st)
{
  if (len1 > n / 2 || len2 > n / 2 || flag)
    return;
  
  if (i == n)
    {
      if (len1 == len2)
        {
          flag = 1;
        }
      return;
    }

  if (i == 0) // 第一个元素加入到sub1中去
    {
      sub1[len1] = nums[i];
      dfs (i + 1, len1 + 1, len2, st);
    }
  else
    {
      if (sub1[st] == nums[i]) // 第一个元素为头，如果发现一样，那么这个东东就是第二个序列的头
        {
          sub2[len2] = nums[i];
          dfs (i + 1, len1, len2 + 1, st + 1); // 此处是有两种状态的?
                                               // 1. 这个数是v1中间的一个数，直接放入v1
                                               // 2. 这个数v1的第一个数放在v2中
        }
      sub1[len1] = nums[i];
      dfs (i + 1, len1 + 1, len2, st);
    }
}

int main()
{
  int t;
  scanf ("%d", &t);

  int i = 0;
  while (i < t)
    {
      scanf ("%d", &n);
      int j;
      for (j = 0; j < n; j++)
        scanf ("%d", &nums[j]);
      memset (sub1, 0, sizeof(sub1));  
      memset (sub2, 0, sizeof(sub2));

      flag = 0;
      dfs (0, 0, 0, 0);
      answer[i] = flag;
      i++;
    }

  for (i = 0; i < t; i++)
    {
      if (answer[i])
        printf ("Good job!!\n");
      else
        printf ("What a pity!\n");
    }
  return 0;
}
