#include<iostream>

using namespace std;

const int N = 310;

int dp[N][N];
int input[N];
int s[N];
int cache[N][N] = {0};
int dfs(int l, int r) {
    if (l == r) return 0;
    if (cache[l][r] > 0) return cache[l][r];
    int res = 1e9;
    for (int i = 0; l + i < r; i++) {
        res = min(res, dfs(l, l+i) + dfs(l+i+1,r) + s[r] - s[l-1]);
    }
    cache[l][r] = res;
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &input[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i-1] + input[i];
    int res = dfs(1, n);
    cout << res << endl;
    return 0;
}

