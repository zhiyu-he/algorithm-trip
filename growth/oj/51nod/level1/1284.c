#include <stdio.h>

int main()
{
  unsigned long long N;
  scanf ("%lld", &N);
    
  unsigned long long X_2 = N / 2;
    
  unsigned long long X_3 = N / 3;
  unsigned long long X_5 = N / 5;
  unsigned long long X_7 = N / 7;

  unsigned long long X_2_3 = N / 6;
  unsigned long long X_2_5 = N / 10;
  unsigned long long X_2_7 = N / 14;

  unsigned long long X_3_5 = N / 15;
  unsigned long long X_3_7 = N / 21;
  
  unsigned long long X_5_7 = N / 35;

  unsigned long long X_2_3_5 = N / 30;
  unsigned long long X_2_3_7 = N / 42;
  unsigned long long X_2_5_7 = N / 70;

  unsigned long long X_3_5_7 = N / 105;
  unsigned long long X_2_3_5_7 = N / 210;


  printf ("%llu\n", N - X_2 - X_3 - X_5 - X_7 + X_2_3 + X_2_5 + X_2_7 + X_3_5 + X_3_7 + X_5_7 - X_2_3_5 - X_2_3_7 - X_2_5_7 - X_3_5_7 + X_2_3_5_7);
  
  return 0;
}
