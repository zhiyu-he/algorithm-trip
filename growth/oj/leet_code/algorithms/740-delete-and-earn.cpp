#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<vector<int>> dp(10000+2, vector<int>(2));
        vector<int> all_val(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            all_val[nums[i]] += 1;
        }
        dp[1][0] = 0;
        dp[1][1] = all_val[1] == 0 ? 0 :all_val[1];
        for (int val = 2; val <= 10000; val++) {
            dp[val][0] = max(dp[val-1][0], dp[val-1][1]);
            dp[val][1] = max(dp[val-2][1]+all_val[val]*val, dp[val][0]);
        }
        return max(dp[10000][0], dp[10000][1]);
    }
};

int main() {
    Solution s;
    return 0;
}
