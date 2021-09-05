#include<iostream>

using namespace std;

const int N = 110;

int v[N], w[N], s[N];
int dp[N][N];

int main() {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &v[i], &w[i], &s[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]*k] + w[i]*k);
            }
        }
    }
    cout << dp[n][V] << endl;
    return 0;
}
