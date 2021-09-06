#include<iostream>

using namespace std;

const int N = 1010;

int input[N], dp[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &input[i]);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (input[j] < input[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int res = dp[1];
    for (int i = 2; i <= n; i++)
        res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}
