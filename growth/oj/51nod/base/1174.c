#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 20001

/**
 *  线段树是为了在logn的时间内找到给定区间的最值问题, 其思路是空间换时间,
 *
 *  同时考虑下初始化，由于有n个叶子节点，叶子节点上面是n/2个父节点n + n/2 + n/4 + ... + 1 = 2n
 *  整体初始化的`时间复杂度`与`空间复杂度均为`就是O(2n) = O(n)
 *  
 *  e.g 
 *  arr: [1 7 6 3 1]
 *  
 *  那么构建数组`arr`的线段树结构为
 *  1.                       7[0, 4]
 *  2.               7[0, 2]               3[3, 4]
 *  3.        7[0, 1]        6[2]      3[3]     1[4]
 *  4.    1[0]      7[1]
 *
 *  那么考虑下初始化的问题:
 * 
 * 考虑下初始化对于每个数组中的元素有两种可能
 *  1. 区间[left, right] left == right 时 st[index] = arr[left]
 *  2. 不等的时候, 则要进行选举，那么就是st[index * 2] 与 st[index * 2 + 1] 进行比较
 *     如果是最大值，那么取大值，赋值给st[index]
 *
 *
 *  这里在进行初始化的时候，需要注意一点st的index从1开始, 那么数组中的元素也是从[1, n]
 *  可以采用递归的形式
 *
 *  void init_segment_tree(s[], index, left, right)
 *  {
 *      if  left == right
 *          st[index] = s[left]
 *      else
 *          mid = left + (right - left) / 2
 *          init_segment_tree(index * 2, left, mid)
 *          init_segment_tree(index * 2 + 1, mid + 1, right)
 *          // 这里要处理一个比较的结果
 *          if st[index * 2] >= st[index * 2 + 1]
 *              st[index] = st[index * 2]
 *          else
 *              st[index] = st[index * 2 + 1]
 *          
 *  }
 *  
 *  查找的问题:
 *  
 *  当给定一个区间时[i, j], 并求该区间的最值时, 会存在如下几种情况:
 *  1. 待查询的区间，包含了`预处理`的区间内，这个情况为 -----i---pi----pj---j----> 
 *  2. 第二种，向下遍历min/max (index * 2 and index * 2 + 1)
 *
 *
 *  知道节点数量求树高: log(叶子节点的数量) + 1
 *  
 *  
 *
 *
 *
 *
 */


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
