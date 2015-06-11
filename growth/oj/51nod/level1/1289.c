#include <stdio.h>

struct fish {
  long long value;
  int direct;
};

struct fish fishes[100001];

int main()
{
  
  int pos = 0;
  int t;

  scanf ("%d", &t);
  int i;

  int direct;
  for (i = 0; i < t; i++)
    {
      struct fish one;
      scanf ("%lld %d", &one.value, &one.direct);
      fishes[pos++] = one;

      // 以当前鱼为参考，如果是相向而行就处理, 如果是相背而行就入栈
      while (pos > 1)
        {
          // 当上一条鱼往右走, 当前往左走才会相遇
          if (fishes[pos - 2].direct == 1 && fishes[pos - 1].direct == 0)
            {
              if (fishes[pos - 2].value > fishes[pos - 1].value)
                {
                  pos--;
                }
              else
                {
                  fishes[pos - 2].value = fishes[pos - 1].value;
                  fishes[pos - 2].direct = fishes[pos - 1].direct;
                  pos--;
                }
            }
          else
            break;
        }
    }
  printf ("%d\n", pos);
  return 0 ;
}