#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(m+1));
        for (int i = 1; i <= nums.size(); i++) {
            for (int k = 1; k <= min(i, m); k++) {
                dp[i][k] = INT_MAX;
                int total_sum = 0;
                for (int j = i; j >= k; j--) {
                    total_sum += nums[j-1];
                    dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], total_sum));
                }
                if (k == 1) dp[i][k] = total_sum;
            }
        }
        return dp[nums.size()][m];
    }
};

int main() {
    return 0;
}
