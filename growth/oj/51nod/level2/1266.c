#include <stdio.h>

long ant[50001];


int main()
{

  int n;
  long length;
  scanf ("%d %ld", &n, &length);
  
  int i;
  for (i = 1; i <= n; i++)
    scanf ("%ld", &ant[i]);
  
  long min, max;
  
  // 最快掉落, 一组数中 两端中的最小值，同时，一组数中的最大值
  // e.g. l = 10,  2 {2} 6 {4} 7 {3}
  // e.g. l = 40,  9 {9} 
  min = 0;
  for (i = 1; i <= n; i++)
    {
      long temp = ant[i] < length - ant[i] ? ant[i] : length - ant[i];
      if (temp > min)
        min = temp;
    }
  // 最慢掉落, 一组数中距离单向的最大值
  max = 0;
  for (i = 1; i <= n; i++)
    {
      long temp = ant[i] > length - ant[i] ? ant[i] : length - ant[i];
      if (temp > max)
        max = temp;
    }
  printf ("%ld %ld\n", min, max);
}