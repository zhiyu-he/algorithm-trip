#include <stdio.h>

#define LIMIT 1e18
#define TABLE_SIZE 60 * 60 * 60 + 1
#define T 10001


/*
  最大输入的N为10^18
  
  2^x + 3^y + 5^z <= 10^18

  以最小的算 2^x <= 10^18 -> x = 60
*/

unsigned long long hit_table[TABLE_SIZE] = { 0 };

unsigned long long ans[T];


int binary_search (unsigned long long arr[], int start, int end, unsigned long long value)
{
  int index = -1;
  while (start <= end)
    {
      int mid = start + ((end - start) >> 1);
      if (arr[mid] == value)
        {
          index = mid;
          break;
        }
      else if (arr[mid] > value)
        {
          index = mid;
          end = mid - 1;
        }
      else
        start = mid + 1;
    }

  return index;
}

int main()
{
  int count = 0;
  int i = 0;   // for 2
  int j = 0;   // for 3
  int k = 0;   // for 5
  int next = 1;
  hit_table[0] = 1;
  
  while (next < TABLE_SIZE)
    {
      unsigned long long mid = hit_table[j] * 3 < hit_table[k] * 5 ? hit_table[j] * 3 : hit_table[k] * 5;
      hit_table[next] = hit_table[i] * 2 < mid ? hit_table[i] * 2 : mid;

      if (hit_table[next] == hit_table[i] * 2) i++;
      if (hit_table[next] == hit_table[j] * 3) j++;
      if (hit_table[next] == hit_table[k] * 5) k++;
            
      if (hit_table[next] < hit_table[next - 1])
        {
          hit_table[next] = 0;
          break;
        }
      
      next++;
      count++;
    }
  //  for (i = 1; i <= 100; i++)
  //   printf ("%llu\n", hit_table[i]);
  
  
  
  int t;
  scanf ("%d", &t);
  
  i = 1;
  while (i <= t)
    {
      unsigned long long v;
      scanf ("%llu", &v);
      int index = binary_search (hit_table, 1, count, v);
      ans[i] = hit_table[index];
      i++;
    }
  
  for (i = 1; i <= t; i++)
    printf ("%llu\n", ans[i]);
  

  //  printf ("last v : %llu\n", hit_table[count + 1]);
  return 0;
}
