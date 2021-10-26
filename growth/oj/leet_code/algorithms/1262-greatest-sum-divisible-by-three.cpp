#include<iostream>

using namespace std;

class Solution {
public:
    int max_res = 0;
    /*
        dfs会导致超时
    int maxSumDivThree(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0] % 3 == 0 ? nums[0] : 0;
        dfs(nums, 0, 0);
        return max_res;
    }
    

    
    
    void dfs(vector<int>& nums, int idx, int cur_sum) {
        if (idx == nums.size()) {
            if (cur_sum % 3 == 0)
                max_res = max(max_res, cur_sum);
            return;
        }
        dfs(nums, idx+1, cur_sum + nums[idx]);
        dfs(nums, idx+1, cur_sum);
    }
    */
    const static int N = 40010;
    int dp[N][3];
    int maxSumDivThree(vector<int>& nums) {
        // 余数为0，1，2
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            // dp[i-1][0] 保存的是[0~i-1]最大被3整除的数，其他的类似
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            for (int j = 0; j < 3; j++) {
                int val = dp[i-1][j] + nums[i-1];
                dp[i][val%3] = max(dp[i][val%3], val);
            }
        }
        return dp[nums.size()][0];
    }
};


int main() {
	return 0;
}
