/**
    博弈论水题，枚举P状态即可
    P状态为先手必胜状态的集合
**/

#include <stdio.h>


char t[9] = { 'A', 'A', 'B', 'A', 'A', 'A', 'A', 'B' };

int answer[10001];

int main()
{
  
  int N;
  scanf ("%d", &N);
  
  int i;
  for (i = 1; i <= N; i++)
    {
      long number;
      scanf ("%ld", &number);
      int mod = number % 7;
      int index = mod == 0 ? 7 : mod;
      answer[i] = t[index];
    }

  for (i = 1; i <= N; i++)
    printf ("%c\n", answer[i]);
  return 0;
}
