#include<iostream>
#include<vector>

class NumArray {
public:
    vector<int> prefix;
    int size;
    NumArray(vector<int>& nums) {
        size = nums.size();
        prefix.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                prefix[i] = nums[i];
            else
                prefix[i] = prefix[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return prefix[j];
        return prefix[j] - prefix[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


int main() {
    Solution s;
    return 0;
}
