#include<iostream>

using namespace std;

const int N = 1e4 + 10;
int v[N], w[N];
int dp[N] = {0};

int main() {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = V; j > 0; j--) {
            if (j - v[i] >= 0) {
                dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
            }
        }
    }
    
    cout << dp[V] << endl;
    return 0;
}
