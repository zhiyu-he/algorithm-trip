#include <stdio.h>


void quick_sort (int nums[], int i, int j)
{
  if (nums == NULL || i > j)
    return;
  
  int left = i;   // 左哨兵
  int right = j;  // 右哨兵

  int base = nums[i];
  int temp;
  while (left != right)
    {
      while (nums[right] > base && left < right)
        right--;
      while (nums[left] <= base && left < right)
        left++;

      if (left < right)
        {
          temp = nums[left];
          nums[left] = nums[right];
          nums[right] = temp;
        }
    }

  temp = nums[i];
  nums[i] = nums[left];
  nums[left] = temp;

  quick_sort (nums, i, right - 1);
  quick_sort (nums, left + 1, j);
}

int main()
{
  int a_1[] = {8, 100, 50, 22, 8, 6, 1, 1000, 999, 0};

  quick_sort (a_1, 0, 9);
  int i;
  for (i = 0; i < 10; i++)
    {
      printf("%d\t", a_1[i]);
    }
  return 0;
}
