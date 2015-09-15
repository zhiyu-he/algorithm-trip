#include <stdio.h>

int main()
{
  // 原数据
  long long a1, b1;
  long long a2, b2;
  
  
  scanf ("%lld %lld %lld %lld", &a1, &b1, &a2, &b2);

  //  printf ("%lld %lld \n %lld %lld \n", a1, b1, a2, b2);
  // 持久数据
  long long m1, n1;
  long long m2, n2;
  
  m1 = a1;
  n1 = b1;
  m2 = a2;
  n2 = b2;
  
  long long count_num1_2x = 0;
  long long count_num1_3x = 0;

  long long count_num2_2x = 0;
  long long count_num2_3x = 0;

  while (a1 % 2 == 0 || a1 % 3 == 0)
    {
      if (a1 % 2 == 0)
        {
          count_num1_2x++;
          a1 /= 2;
        }

      if (a1 % 3 == 0)
        {
          count_num1_3x++;
          a1 /= 3;
        }
    }

  while (b1 % 2 == 0 || b1 % 3 == 0)
    {
      if (b1 % 2 == 0)
        {
          count_num1_2x++;
          b1 /= 2;
        }

      if (b1 % 3 == 0)
        {
          count_num1_3x++;
          b1 /= 3;
        }
    }

  while (a2 % 2 == 0 || a2 % 3 == 0)
    {
      if (a2 % 2 == 0)
        {
          count_num2_2x++;
          a2 /= 2;
        }

      if (a2 % 3 == 0)
        {
          count_num2_3x++;
          a2 /= 3;
        }
    }

  while (b2 % 2== 0 || b2 % 3 == 0)
    {
      if (b2 % 2 == 0)
        {
          count_num2_2x++;
          b2 /=2;
        }

      if (b2 % 3 == 0)
        {
          count_num2_3x++;
          b2 /= 3;
        }
    }
  /*  
  printf ("count_num1_2x : %lld\n", count_num1_2x);
  printf ("count_num1_3x : %lld\n", count_num1_3x);
  
  printf ("count_num2_2x : %lld\n", count_num2_2x);
  printf ("count_num2_3x : %lld\n", count_num2_3x);
  */
  // PS: 当乘上2/3时，2的数量会＋1
  long long ans = 0;
  if (count_num2_3x > count_num1_3x)
    {
      long long times = count_num2_3x - count_num1_3x;
      count_num2_2x += times;
      ans += times;
      long long i = 0;
      
      for (i = 0; i < times; i++)
        {
          if (m2 % 3 == 0)
            m2 = m2 / 3 * 2;
          else
            n2 = n2 / 3 * 2;
        }
    }
  else
    {
      long long times = count_num1_3x - count_num2_3x;
      count_num1_2x += times;
      ans += times;
      long long i = 0;
      for (i = 0; i < times; i++)
        {
          if (m1 % 3 == 0)
            m1 = m1 / 3 * 2;
          else
            n1 = n1 / 3 * 2;
        }
    }
  /*
  // 处理完3后
  printf ("----------\n");
  printf ("count_num1_2x : %lld\n", count_num1_2x);
  printf ("count_num1_3x : %lld\n", count_num1_3x);

  printf ("count_num2_2x : %lld\n", count_num2_2x);
  printf ("count_num2_3x : %lld\n", count_num2_3x);
  printf ("-----------\n");
  */
  if (count_num2_2x > count_num1_2x)
    {
      long long times = count_num2_2x - count_num1_2x;
      ans += times;
      long long i = 0;
      for (i = 0; i < times; i++)
        {
          if (m2 % 2 == 0)
            m2 /= 2;
          else
            n2 /= 2;
        }
    }
  else
    {
      long long times = count_num1_2x - count_num2_2x;
      ans += times;
      long long i = 0;
      for (i = 0; i < times; i++)
        {
          if (m1 % 2 == 0)
            m1 /= 2;
          else
            n1 /= 2;
        }
    }
  //  printf ("%lld %lld \n %lld %lld \n", m1, n1, m2, n2);

  if (m1 * n1 == m2 * n2)
    printf ("%lld\n", ans);
  else
    printf ("-1\n");
}
