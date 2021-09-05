#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000+10;

int v[N], w[N];

int dp[N][N];

int main() {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = 0; k * v[i] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]*k] + w[i]*k);
            }
        }
    }
    cout << dp[n-1][V] << endl;
    return 0;
}
