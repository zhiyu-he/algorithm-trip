#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        vector<int> pre_sum(nums.size()+1);
        for (int i = 1; i <= nums.size(); i++) {
            pre_sum[i] = nums[i-1] + pre_sum[i-1];
        }
        for (int i = 2; i <= nums.size(); i++) {
            for (int j = 1; i-j+1 >= 2; j++) {
                int delta = pre_sum[i] - pre_sum[j-1];
                if (delta == k || (k != 0 && delta % k == 0)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}
