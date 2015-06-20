#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C_T_N 48

char a[10002];
char b[10002];


int cmp (char *a, char *b, int a_len, int b_len)
{
  if (a_len > b_len) return 1;

  int i = 0;
  while (i < b_len)
    {
      if (a[i] > b[i])
        return 1;
      else if (a[i] < b[i])
        return -1;
      i++;
    }
  return 0;
}

char * big_add (char *a, char *b, int a_len, int b_len, int len)
{
  char *res = (char *) malloc (sizeof (char) * len);
  
  int i = 0;
  int a_start = a_len - 1;
  int b_start = b_len - 1;
  int carry = 0;
  // 处理低位
  while (b_start >= 0)
    {
      int _a = a[a_start] - C_T_N;
      int _b = b[b_start] - C_T_N;
      int _res = _a + _b + carry;
      carry = _res / 10;
      res[i++] = _res % 10 + C_T_N;
      b_start--;
      a_start--;
      //      printf ("res[%d] = %c\n", i, res[i]);
    }
  while (a_start >= 0)
    {
      int _a = a[a_start] - C_T_N;
      int _res = _a + carry;
      carry = _res / 10;
      res[i++] = _res % 10 + C_T_N;
      //printf ("res[%d] = %c\n",i, res[i]);
      a_start--;
    }
  
  if (carry > 0)
    {
      res[i++] = carry + C_T_N;
      carry = 0;
    }
  res[i] = '\0';
  return res;
}

char * big_sub (char *a, char *b, int a_len, int b_len, int len)
{
  char *res = (char *) malloc (sizeof (char) * len);
  int i = 0;
  int a_start = a_len - 1;
  int b_start = b_len - 1;
  int carry = 0;
  while (b_start >= 0)
    {
      int _a = a[a_start] - C_T_N + carry;
      int _b = b[b_start] - C_T_N;
      carry = 0;

      if (_a < _b)
        {
          carry = -1;
          _a += 10;
        }
      int _res = _a - _b;
      
      res[i++] = _res + C_T_N;
      //printf ("res[%d] = %c\n", i, res[i - 1]);
      b_start--;
      a_start--;
      //      printf ("a_start: %d\n", a_start);
    }
  
  //  printf ("a_start: %d\n", a_start);
  while (a_start >= 0)
    {
      //  printf ("a_start: %d\n", a_start);
      int _a = a[a_start] - C_T_N + carry;
      carry = 0;
      if (_a < 0)
        {
          carry = -1;
          _a += 10;
        }
      res[i++] = _a + C_T_N;
      //printf ("_a: %d res[%d] = %c\n", _a, i, res[i - 1]);
      a_start--;
    }
  //  printf ("sub : %s\n", res);
  res[i] = '\0';
  return res;
}

int main()
{
  
  scanf ("%s %s", a, b);
  
  int a_len = strlen (a);
  int b_len = strlen (b);
  int len, i;
  char *res;
  char ch = '+';

  if (a[0] != '-' && b[0] != '-')
    {
      //      printf ("a = %s b = %s a_len = %d b_len = %d len = %d\n", a, b, a_len, b_len, len);
      //      printf ("sum\n");
      len = (a[0] + b[0] - C_T_N * 2) >= 10 ? a_len + 2 : a_len + 1;
      //      printf ("a = %s b = %s a_len = %d b_len = %d len = %d\n",a, b, a_len, b_len, len);
      if (a_len > b_len)
        res = big_add (a, b, a_len, b_len, len);
      else
        res = big_add (b, a, b_len, a_len, len);
    }
  else if (a[0] == '-' && b[0] == '-')
    {
      ch = '-';
      int index = 0;
      for (i = 1; i < a_len; i++)
        a[index++] = a[i];
      a[index] = '\0';
      a_len--;

      index = 0;
      for (i = 1; i < b_len; i++)
        b[index++] = b[i];
      b[index] = '\0';
      b_len--;
      len = (a[0] + b[0] - C_T_N * 2) >= 10 ? a_len + 2 : a_len + 1;
      if (a_len > b_len)
        res = big_add (a, b, a_len, b_len, len);
      else
        res = big_add (b, a, b_len, a_len, len);
    }
  else
    {
      int compare;
      if (a[0] == '-')
        {
          int index = 0;
          for (i = 1; i < a_len; i++)
            a[index++] = a[i];
          a[index] = '\0';
          a_len--;
          if (a_len > b_len)
            {
              compare = 1;
              ch = '-';
            }
          else if (a_len == b_len)
            {
              compare = cmp (a, b, a_len, b_len);
              ch = compare == 1 ? '-' : '+';
            }
        }
      if (b[0] == '-')
        {
          int index = 0;
          for (i = 1; i < b_len; i++)
            b[index++] = b[i];
          b[index] = '\0';
          b_len--;
          if (b_len > a_len)
            {
              compare = -1;
              ch = '-';
            }
          else if (a_len == b_len)
            {
              compare = cmp (a, b, a_len, b_len);
              ch = compare == -1 ? '-' : '+';
            }
        }
      
      if (a_len > b_len)
        {
          len = a_len + 1;
          res = big_sub (a, b, a_len, b_len, len);
        }
      else if (a_len == b_len)
        {
          if (compare >= 1)
            {
              len = a_len + 1;
              res = big_sub (a, b, a_len, b_len, len);
            }
          else
            {
              len = a_len + 1;
              res = big_sub (b, a, b_len, a_len, len);
            }
        }
      else
        {
          len = b_len + 1;
          res = big_sub (b, a, b_len, a_len, len);
        }
    }

  
  int zero_flag = 1;
  for (i = len - 2; i >= 0; i--)
    {
      if (res[i] != '0')
        {
          zero_flag = 0;
          break;
        }
    }
  if (zero_flag)
    printf ("0\n");
  else
    {
      int head = 0;
      if (ch == '-')
        printf ("-");
      for (i = len - 1; i >= 0; i--)
        {
          if (res[i] != '0' && res[i] != '\0')
            head = 1;
          if (head)
            printf ("%c", res[i]);

        }
      printf ("\n");
    }

  return 0;
}
