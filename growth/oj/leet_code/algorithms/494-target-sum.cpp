#include<iostream>
#include<vector>

using namespace std;

// TTL
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        slove(nums, 0, 0, S, res);
        return res;
    }
    void slove(vector<int>& nums, int start_i, int cur_sum, int target, int& res) {
        if (start_i == nums.size()) {
            res += cur_sum == target ? 1 : 0;
            return;
        }
        slove(nums, start_i+1, cur_sum + nums[start_i], target, res);
        slove(nums, start_i+1, cur_sum - nums[start_i], target, res);
        return;
    }
};


// AC
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        vector<vector<int>> cache(nums.size()+1, vector<int>(2001));
        return slove(nums, S, 0, 0, cache);
    }
    int slove(vector<int>& nums, int S, int cur_sum, int start_idx, vector<vector<int>>& cache) {
        if (start_idx == nums.size()) {
            if (cur_sum == S) return 1;
            return 0;
        }
        if (cache[start_idx][cur_sum+1000] > 0) return cache[start_idx][cur_sum+1000];
        int cnt1 = slove(nums, S, cur_sum + nums[start_idx], start_idx+1, cache);
        int cnt2 = slove(nums, S, cur_sum - nums[start_idx], start_idx+1, cache);
        cache[start_idx][cur_sum+1000] = cnt1 + cnt2;
        return cnt1 + cnt2;

    }
};


int main() {
    Solution s;
    return 0;
}
