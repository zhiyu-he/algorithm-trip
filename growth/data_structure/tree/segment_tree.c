#include <stdio.h>

#define MAX_SIZE 101


int arr[MAX_SIZE];

// 如果是100个元素 树高为 log(n) + 1 = 8 
int segment_tree[256];

void build_seg_tree (int node, int start, int end)
{
  int mid;
  if (start == end)
    segment_tree[node] = arr[start];
  else
    {
      mid = start + (end - start) / 2;
      build_seg_tree (2 * node, start, mid);
      build_seg_tree (2 * node + 1, mid + 1, end);

      if (segment_tree[2 * node] <= segment_tree[2 * node + 1])
        segment_tree[node] = segment_tree[2 * node];
      else
        segment_tree[node] = segment_tree[2 * node + 1];
    }
}


int main()
{
  int i, n;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    scanf ("%d", &arr[i]);

  build_seg_tree (1, 1, n);

  for (i = 1; i <= 15; i++)
    printf ("%d ", segment_tree[i]);
  return 0;
}
