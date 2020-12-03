#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        vector<int> counter(nums.size()+1);
        vector<int> max_len_arr(nums.size()+1);
        int max_len = 1;
        for(int i = 1; i <= nums.size(); i++) {
            dp[i] = 1;
            counter[i] = 1;
            max_len_arr[i] = dp[i];
            for (int j = 1; j < i; j++) {
                if (nums[j-1] < nums[i-1]) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        counter[i] = counter[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        counter[i] += counter[j];
                    }
                }
                max_len = max(max_len, dp[i]);
            }
        }
        int res = 0;
        for (int i = 0; i <= nums.size(); i++) {
            if (max_len == dp[i])
                res += counter[i];
        }
        return max_len == 1 ? nums.size() : res;
    }
};

int main() {
    Solution s;
    return 0;
}
