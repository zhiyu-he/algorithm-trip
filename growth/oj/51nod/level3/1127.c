#include <stdio.h>
#include <string.h>

#define INF 999999
#define MAX_LEN 100001
#define BASE 65

char str[MAX_LEN];

int ch[26] = { 0 };


int main()
{
  gets (str);
  
  int len = strlen (str);
  int res = INF;

  int start = 0;
  int tail = 0;
  int ch_num = 0;
  while (tail < len)
    {
      while (ch_num < 26 && tail < len)
        {
          // 发现一枚新字符
          if (ch[str[tail] - 'A'] == 0)
            {
              ch_num++;
            }
          ch[str[tail] - 'A']++;
          tail++;
        }

      if (ch_num < 26) break; // 如果遍历到结尾仍不足26个，直接退出
      
      if (tail - start < res) // 更新最小结果
        {
          res = tail - start;
        }

      ch[str[start] - 'A'] -= 1;

      if (ch[str[start] - 'A'] == 0)
        {
          ch_num--;
        }
      start++;
    }
  
  if (res == INF)
    printf ("No Solution\n");
  else
    printf ("%d\n", res);
  return 0;
}
