#include<iostream>
#include<vector>

using namespace std;

// O(N)
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int peak = 1, valley = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) peak = valley + 1;
            if (nums[i] < nums[i-1]) valley = peak + 1;
        }
        return max(peak, valley);
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 0;
        vector<vector<int>> cache(nums.size()+1, vector<int>(3));
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, wiggle(nums, i, 0, cache));
            res = max(res, wiggle(nums, i, 1, cache));
        }
        return res;
    }
    int wiggle(vector<int>& nums, int start_idx, int direct, vector<vector<int>>& cache) {
        if (start_idx == nums.size()-1) return 1;
        if (cache[start_idx][direct] != 0) return cache[start_idx][direct];
        int len = 1;
        for (int i = start_idx+1; i < nums.size(); i++) {
            // up
            if (direct == 0 && nums[start_idx] < nums[i]) {
                len = max(len, 1 + wiggle(nums, i, 1, cache));
            }
            // down
            if (direct == 1 && nums[start_idx] > nums[i]) {
                len = max(len, 1 + wiggle(nums, i, 0, cache));
            }
        }
        cache[start_idx][direct] = len;
        return len;
    }
};



int main() {
    Solution s;
    return 0;
}
