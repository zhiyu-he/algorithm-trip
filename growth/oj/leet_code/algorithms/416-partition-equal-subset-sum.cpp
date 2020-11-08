#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int total_sum = 0;
        for (auto num : nums) total_sum += num;
        if (total_sum % 2 == 1) return false;

        int target_k = total_sum / 2;

        vector<int> dp(target_k+1);

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = target_k; j >= 1; j--) {
                if (j - nums[i-1] >= 0) {
                    if (j - nums[i-1] == 0) {
                        dp[j] = 1;
                    } else {
                        dp[j] = max(dp[j], dp[j-nums[i-1]]);
                    }
                }
            }
        }
        return dp[target_k] > 0;
    }
};


class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int total_sum = 0;
        for (auto num : nums) total_sum += num;
        if (total_sum % 2 == 1) return false;

        int target_k = total_sum / 2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(target_k+1)); // dp[i][j] use [0...i]elements equal sum to j
        dp[0][0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target_k; j++) {
                if (j - nums[i-1] >= 0) {
                    if (j - nums[i-1] == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]]);
                    }
                }
            }
        }
        return dp[nums.size()][target_k] > 0;
    }
};


int main() {
    Solution s;
    return 0;
}
