#include<iostream>

using namespace std;

const int N = 1010;

char s1[N], s2[N];
int dp[N][N];

int main() {
    int l1,  l2;
    scanf("%d %d", &l1, &l2);
    scanf("%s", s1);
    scanf("%s", s2);
    dp[0][0] = 0;
    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++) {
            int equal = s1[i-1] == s2[j-1] ? 1 : 0;
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + equal);
        }
    cout << dp[l1][l2] << endl;
    return 0;
}
