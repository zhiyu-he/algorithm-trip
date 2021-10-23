#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int nums[1010];
        memset(nums, -1, sizeof nums);
        
        for (int i = 0; i < nums1.size(); i++) {
            nums[nums1[i]] = 0;
        }
        for (int i = 0; i < nums2.size(); i++) {
            nums[nums2[i]] = nums[nums2[i]] == 0 ? nums[nums2[i]] + 1 : nums[nums2[i]];
        }
        vector<int> res;
        for (int i = 0; i < 1010; i++) {
            if (nums[i] >= 1) res.push_back(i);
        }
        return res;
    }
};

int main () {

	return 0;
}


