#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50000

struct node
{
  int pos;
  long val;
};


struct node islands[MAX_SIZE];
struct node queries[MAX_SIZE];


int answer[MAX_SIZE];
int bool[MAX_SIZE];

int cmp (struct node n1, struct node n2)
{
  return n1.val >= n2.val ? 1 : 0;
}

void merge (struct node arr[], int start, int mid, int end)
{
  int l_len = mid - start + 1;
  int r_len = end - mid;

  struct node *l = (struct node *) malloc (sizeof (struct node) * l_len);
  struct node *r = (struct node *) malloc (sizeof (struct node) * r_len);

  int i, j, k;
  for (i = 0; i < l_len; i++)
    l[i] = arr[i + start];

  for (i = 0; i < r_len; i++)
    r[i] = arr[i + mid + 1];

  i = 0;
  j = 0;
  k = start;

  while (i < l_len && j < r_len)
    {
      if (cmp (l[i], r[j]) > 0)
        {
          arr[k++] = r[j++];
        }
      else
        {
          arr[k++] = l[i++];
        }
    }

  while (i < l_len)
    arr[k++] = l[i++];
  
  while (j < r_len)
    arr[k++] = r[j++];

  free (l);
  free (r);
}

void merge_sort (struct node arr[], int start, int end)
{
  int mid;
  if (start < end)
    {
      mid = start + ((end - start) >> 1);
      merge_sort (arr, start, mid);
      merge_sort (arr, mid + 1, end);
      merge (arr, start, mid, end);
    }
}

int main()
{

  int n, q;
  scanf ("%d %d", &n, &q);

  int i;
  for (i = 0; i < n; i++)
    {
      scanf ("%ld", &islands[i].val);
      islands[i].pos = i;
    }

  for (i = 0; i < q; i++)
    {
      scanf ("%ld", &queries[i].val);
      queries[i].pos = i;
    }

  merge_sort (islands, 0, n - 1);
  merge_sort (queries, 0, q - 1);

  /**
     对每一个i来说 a[i] 没入水中

     a[i - 1] a[i + 1] 均活着 岛屿数量 +1

     a[i - 1] || a[i + 1] 不变
     
     a[i - 1] a[i + 1] 均挂了 岛屿数量 -1
   **/

  int ans = 1; // 开始有一个大岛屿
  int j = 0;
  for (i = 0; i < q; i++)
    {
      //      int j = 0;
      while (j < n && islands[j].val <= queries[i].val)
        {
          if (islands[j].pos == 0)
            {
              if (bool[islands[j].pos + 1])
                ans -= 1;
            }
          else if (islands[j].pos == n - 1)
            {
              if (bool[islands[j].pos - 1])
                ans -= 1;
            }
          else
            {
              if (bool[islands[j].pos - 1] == 0 && bool[islands[j].pos + 1] == 0)
                ans += 1;
              else if (bool[islands[j].pos - 1] == 1 && bool[islands[j].pos + 1] == 1)
                ans -= 1;
            }
          bool[islands[j].pos] = 1;
          j++;
        }
      answer[queries[i].pos] = ans;
    }

  for (i = 0; i < q; i++)
    printf ("%d\n", answer[i]);
  return 0;
}