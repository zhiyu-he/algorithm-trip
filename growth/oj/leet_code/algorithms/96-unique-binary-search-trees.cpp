#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 2) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int total_cnt = 0;
            for (int j = 1; j <= i; j++) {
                int left = j - 1;
                int right = i - j;
                if (left == right) {
                    total_cnt += dp[left] * dp[right];
                } else {
                    if (dp[left] == 0) {
                        total_cnt += dp[right];
                    } else if (dp[right] == 0) {
                        total_cnt += dp[left];
                    } else {
                        total_cnt += dp[left] * dp[right];
                    }
                }
            }
            dp[i] = total_cnt;

        }
        return dp[n];
    }
};

int main() {
	Solution s;
	return 0;
}
