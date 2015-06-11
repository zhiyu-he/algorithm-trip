#include <stdio.h>

char winner[10001];

// k + 1 为后出手者的必胜策略
char who_win (long long n, long long k)
{
  if (k >= n)
    return 'A';
  else
    return n % (k + 1) == 0 ? 'B' : 'A';
}


int main()
{
  int t;
  scanf ("%d", &t);
  int i;
  for (i = 1; i <= t; i++)
    {
      long long n, k;
      scanf ("%lld %lld", &n, &k);
      winner[i] = who_win(n, k);
    }
  for (i = 1; i <= t; i++)
    printf ("%c\n", winner[i]);
  return 0;
}
