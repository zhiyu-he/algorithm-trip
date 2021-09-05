#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000+10;

int v[N], w[N];

int dp[N];

int main() {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            if (j >= v[i]) {
                dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
