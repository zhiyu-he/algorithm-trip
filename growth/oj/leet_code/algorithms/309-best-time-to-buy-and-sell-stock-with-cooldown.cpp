#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        for (int i = 0; i < prices.size(); i++) {
            if (i - 1 < 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(-prices[i], dp[i-1][1]);
            if (i - 2 >= 0) {
                dp[i][1] = max(dp[i][1], dp[i-2][0]-prices[i]);
            }
        }
        return dp[prices.size()-1][0];
    }
};

int main() {
    Solution s;
    return 0;
}
