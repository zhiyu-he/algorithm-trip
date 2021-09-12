#include<iostream>
#include<algorithm>
#include<cstring> // has memset

using namespace std;

int const N = 6010;
int happy[N];
bool has_father[N];
// 数据结构， 树的表示，题目中仅给出父子关系，因此需要自己处理出父节点是谁
int h[N], e[N], ne[N], idx = 0;

int dp[N][2];

void add(int a, int b) {
    // edge a->b
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u) {
    dp[u][1] = happy[u];
    // dp[u][0] 不选u点

    // dp[u][1] 选u点, 从u出发的所有边
    for (int edge_idx = h[u]; edge_idx != -1; edge_idx = ne[edge_idx]) {
        int j = e[edge_idx];
        dfs(j); // 每一次计算两个结果选与不选
        dp[u][0] += max(dp[j][1], dp[j][0]); // 对下面的子节点都计算一边
        dp[u][1] += dp[j][0];
    }
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &happy[i]);
    }
    memset(h, -1, sizeof(h));
    for (int i = 1; i < n; i++) {
        int l, k;
        scanf("%d %d", &l, &k);   // k是l的上级
        has_father[l] = true;
        add(k, l);
    }
    int f_u = -1;
    for (int i = 1; i <= n; i++) {
        if (!has_father[i]) f_u = i;
    }

    dfs(f_u);

    cout << max(dp[f_u][0], dp[f_u][1]) << endl;
    return 0;
}
