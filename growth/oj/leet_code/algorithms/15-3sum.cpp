#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || (i > 0 && nums[i-1] != nums[i])) {
                int target = -nums[i];
                int lo = i + 1, hi = nums.size() - 1;
                while(lo < hi) {
                    if (nums[lo] + nums[hi] == target) {
                        res.push_back(vector<int>{nums[i], nums[lo], nums[hi]});

                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;
                        lo++;
                        hi--;
                    } else if (nums[lo] + nums[hi] < target) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
