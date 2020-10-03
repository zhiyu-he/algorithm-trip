#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, i = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            int idx = bs(nums, nums[i] + k);
            if (idx > i) {
                res += 1;
                //cout << "( " << nums[i] << " " << nums[idx] << ")" << endl;
            }
        }
        return res;
    }

    int bs(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                idx = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return idx;
    }
};


int main() {
    Solution s;
    vector<int> input{-1,-2,-3};
    
    cout << s.findPairs(input, 1) << endl;
    return 0;
}
