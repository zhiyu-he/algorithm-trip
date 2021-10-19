#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l = lower_bound(nums, target);
        int r = upper_bound(nums, target);
        if (l == -1 && r == -1) return vector<int>{-1,-1};
        if (l == r) return vector<int>{l, r};
        res = vector<int>{l, r};
        return res;
    }
    
    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, res = -1;
        while (l <= r) {
            int mid = (r-l) / 2 + l;
            if (nums[mid] == target) {
                res =  mid;
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, res = -1;
        while (l <= r) {
            int mid = (r-l) / 2 + l;
            if (nums[mid] == target) {
                res =  mid;
                r = mid - 1;
            } else if (nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};


int main() {
	Solution s;
	return 0;
}
