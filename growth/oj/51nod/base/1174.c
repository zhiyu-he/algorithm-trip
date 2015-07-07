#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 20001


long number[MAX_SIZE];
long segment_tree[MAX_SIZE * 2]; // 由于第i层的结点数一定是第i - 1层的2倍，所以，最大的空间约为MAX_SIZE * 2
                                 // 同时segment_tree 是一颗ma
long answer[MAX_SIZE];
/**
   i: 第几个结点
   start: 区间
   end: 区间
 **/
void init_segment_tree (int i, int start, int end)
{
  int mid;
  if (start == end)
    segment_tree[i] = number[start];
  else
    {
      mid = start + (end - start) / 2;
      init_segment_tree (i * 2, start, mid);       // 初始化第i * 2 个点[start, mid]
      init_segment_tree (i * 2 + 1, mid + 1, end); // 初始化第i * 2 + 1 个基点[mid + 1, end]
      if (segment_tree[i * 2] >= segment_tree[i * 2 + 1])
        segment_tree[i] = segment_tree[i * 2];
      else
        segment_tree[i] = segment_tree[i * 2 + 1];
    }
}

/**
   获取区间[a, b]的最小值
**/
long query (int a, int b, int k, int l, int r)
{
  // 如果
  if (a > r || b < l) return -1;
    // a b 包含 lr内
  if (a <= l && r <= b)
    return segment_tree[k];
  else
    {
      int mid = l + (r - l) / 2;
      long v1 = query (a, b, k * 2, l, mid);
      long v2 = query (a, b, k * 2 + 1, mid + 1, r);
      //      printf ("[%d %d] = %ld\n", l, mid, v1);
      //      printf ("[%d %d] = %ld\n", mid + 1, r, v2);
      return v1 > v2 ? v1 : v2;
    }
}

int main()
{
  int i, n;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    scanf ("%ld", &number[i]);

  init_segment_tree (1, 1, n);
  int q;
  scanf ("%d", &q);
  
  i = 1;
  while (i <= q)
    {
      int a, b;
      scanf ("%d %d", &a, &b);
      answer[i] = query (a + 1, b + 1, 1, 1, n);
      i++;
    }

  for (i = 1; i <= q; i++)
    printf ("%ld\n", answer[i]);
  return 0;
}
