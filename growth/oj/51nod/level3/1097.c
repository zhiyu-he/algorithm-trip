#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

struct num
{
  char ch[20];
};

struct num number[MAX_SIZE];

/**
 对给定的数组元素, 在区间[i, j]进行排序
 */
void quick_sort (struct num nums[], int i, int j);

int cmp (struct num num1, struct num num2)
{
  char str1[40], str2[40];
  //  printf ("num1.ch: %s  num2.ch: %s\n", num1.ch, num2.ch);
  strcpy (str1, num1.ch);
  strcat (str1, num2.ch);
  
  strcpy (str2, num2.ch);
  strcat (str2, num1.ch);

  //  printf ("str1: %s \n str2: %s\n", str1, str2);
  return strcmp (str1, str2);
}

int main()
{
  int N;
  scanf ("%d", &N);
  
  getchar();
  int i;
  for (i = 0; i < N; i++)
    gets (number[i].ch);

  quick_sort (number, 0, N - 1);
  
  //  printf ("sort done\n");
  long ch_count = 0;
  
  for (i = 0; i < N; i++)
    {
      int j = 0;
      while (number[i].ch[j] != '\0')
        {
          printf ("%c", number[i].ch[j]);
          j++;
          ch_count++;
          if (ch_count % 1000 == 0)
            {
              printf ("\n");
            }
        }
    }
  return 0;
}

void quick_sort (struct num nums[], int i, int j)
{
  //  printf ("i: %d j: %d\n", i, j);
  if (nums == NULL || i > j)
    return;
  
  struct num base = nums[i]; // 选择第一个元素当作中枢
  int left  = i;  // 左区间指针
  int right = j;  // 右区间指针
  
  while (left != right)
    {
      while (cmp (nums[right], base) >= 0 && left < right)
        right--;
      
      while (cmp (nums[left], base) <= 0 && left < right)
        {
          left++;
        }

      if (left < right)
        {
          //          printf ("left: %d right: %d\n", left, right);
          struct num t = nums[left];
          nums[left] = nums[right];
          nums[right] = t;
        }
    }

  nums[i] = nums[left];
  nums[left] = base;

  quick_sort (nums, i, right - 1);
  quick_sort (nums, left + 1, j);
}
