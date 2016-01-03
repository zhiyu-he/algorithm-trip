#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define BUCKET_SIZE 1000
#define MAX_LEN 100000
#define MAX_QUERY 5000


int N, M;
long long A[MAX_LEN];                            // 原始序列
long long sorted_nums[MAX_LEN];                  // 排序后的原始序列
long long ans[MAX_QUERY];                        // Q次查询的结果
int L[MAX_QUERY], R[MAX_QUERY], K[MAX_QUERY];    // Q次查询


vector<long long> buckets[MAX_LEN / BUCKET_SIZE];


void init()
{
    int i;
    for (i = 0; i < N; i++)
    {
        buckets[i / BUCKET_SIZE].push_back(A[i]);
        sorted_nums[i] = A[i];
    }
    sort(sorted_nums, sorted_nums + N);
    for (i = 0; i < N / BUCKET_SIZE; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
}

void slove()
{
    int i;
    for (i = 0; i < M; i++)
    {   
       // 1, 2, 2, 3, 4 k = 3
       // import 不超过x的不少于, k个
       
       // 假设x为第k大, 那么意味着比x大的数不超过(N - k)个数
       // 假设x为第k大, 那么意味着比x小的数不少于(k - 1)个
       int l = L[i], r = R[i] + 1, k = K[i];
       // e.g [0, 2)
       // [l, r) 的第k大
       int lb = -1, ub = N - 1;
       // lb, ub 代表的是遍历的整体范围
       // e.g N = 1 代表只有一个元素, 就不需要进行遍历了
       while (ub - lb > 1)
       {    
           int md = (lb + ub) / 2;
           long long x = sorted_nums[md];
           int tl = l, tr = r, c = 0;

           // 处理区间两端, 探出的部分
           while (tl < tr && tl % BUCKET_SIZE != 0) if (A[tl++] <= x) c++;
           while (tl < tr && tr % BUCKET_SIZE != 0) if (A[--tr] <= x) c++;

           while (tl < tr)
           {
               int b = tl / BUCKET_SIZE;
               c += upper_bound(buckets[b].begin(), buckets[b].end(), x) - buckets[b].begin();
               tl += BUCKET_SIZE;
           }
           if (c >= k) 
               ub = md;
           else
               lb = md;
       }
       ans[i] = sorted_nums[ub];
    }
}


int main()
{
    scanf("%d %d", &N, &M);
    int i;
    for (i = 0; i < N; i++)
        scanf("%lld", &A[i]);
    for (i = 0; i < M; i++)
    {
        int l, r, k;
        scanf ("%d %d %d", &l, &r, &k);
        L[i] = l - 1;
        R[i] = r - 1;
        K[i] = k;
    }
    init();
    slove();
    
    for (i = 0; i < M; i++)
        printf ("%lld\n", ans[i]);
    
    return 0;
}
