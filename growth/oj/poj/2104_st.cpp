#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ST_SIZE (1 << 18) - 1
#define MAX_LEN 100001
#define MAX_QUERY 5000
int N, M;
long long A[MAX_LEN];                            // 原始序列
long long sorted_nums[MAX_LEN];                  // 排序后的原始序列
long long ans[MAX_QUERY];                        // Q次查询的结果
int L[MAX_QUERY], R[MAX_QUERY], K[MAX_QUERY];    // Q次查询


vector<long long> dat[ST_SIZE];

void init(int k, int l, int r)
{
    if (r - l == 1)
    {
        dat[k].push_back(A[l]);
    }
    else
    {
        int lch = 2 * k + 1, rch = 2 * k + 2;
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
        dat[k].resize(r - l);
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
    }
}

int query(int i, int j, long long x, int k, int l, int r)
{
    if (j <= l || r <= i)
    {
        return 0;
    }
    else if (i <= l && r <= j)
    {
        return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    } else {
        int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
        int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
        return lc + rc;
    }
}

void solve()
{
    int i;
    for (i = 0; i < N; i++)
    {
        sorted_nums[i] = A[i];
    }
    sort(sorted_nums, sorted_nums + N);
    init(0, 0, N);

    for (i = 0; i < M; i++)
    {
        int l = L[i], r = R[i] + 1, k = K[i];
        int lb = -1, ub = N - 1;
        while (ub - lb > 1)
        {
            int md = (ub + lb) / 2;
            int c = query(l, r, sorted_nums[md], 0, 0, N);
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
    solve();
    
    for (i = 0; i < M; i++)
        printf ("%lld\n", ans[i]);
    
    return 0;
}
