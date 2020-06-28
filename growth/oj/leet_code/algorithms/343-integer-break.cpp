#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(dp[j], j) * max(dp[i-j], i-j));
            }
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    s.integerBreak(10);
    return 0;
}
