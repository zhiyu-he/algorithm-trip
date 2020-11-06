#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int case1 = dp(nums, 0, nums.size()-2);
        int case2 = dp(nums, 1, nums.size()-1);
        return max(case1, case2);
    }

    int dp(vector<int>& nums, int start , int end) {
        int prev = 0, p_prev = 0;
        for (int i = start; i <= end; i++) {
            int cur = max(prev, p_prev + nums[i]);
            p_prev = prev;
            prev = cur;
        }
        return max(prev, p_prev);
    }
};


int main() {
    Solution s;
    return 0;
}
