#include<iostream>

using namespace std;

const int N = 110;
int v[N][N], w[N][N], s[N];
int dp[N];

int main() {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        for (int j = 1; j <= s[i]; j++) {
            scanf("%d %d", &v[i][j], &w[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 0; j--) {
            for (int k = 1; k <= s[i]; k++) {
                if (v[i][k] <= j) {
                    dp[j] = max(dp[j], dp[j-v[i][k]] + w[i][k]);
                }
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
