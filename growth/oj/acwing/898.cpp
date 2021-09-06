#include<iostream>

using namespace std;

const int N = 510;
const int INF = 1e9;

int matric[N][N],  dp[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            scanf("%d", &matric[i][j]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i+1; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[1][1] = matric[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + matric[i][j];
        }
    }
    int res = -INF;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[n][i]);
    }
    cout << res << endl;
    return 0;
}
