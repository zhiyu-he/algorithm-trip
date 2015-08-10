#include <stdio.h>
#include <string.h>

int main()
{
  char i[100];
  char s[100];
  int j, len, mid, next, top;

  gets(i);
  len = strlen(i);
  
  if (len == 0)
  {
    printf("FALSE\n");
    return -1;
  }
  top = 0;
  mid = len / 2 - 1;
  for (j = 0; j <= mid; j++)
    s[top++] = i[j];
  
  if (len % 2 == 0)
    next = mid + 1;
  else
    next = mid + 2;

  for (j = next; j < len; j++)
  {
    if (s[--top] != i[j]) 
    {
      printf("FALSE\n");
      return 0;
    }
  }
  printf("TRUE\n");
  return 0;
}
