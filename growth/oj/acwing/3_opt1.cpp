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
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= v[i]) {
                dp[i][j] = max(dp[i][j], dp[i][j-v[i]]+w[i]);
            }
        }
    }
    cout << dp[n][V] << endl;
    return 0;
}
