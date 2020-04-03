#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max, cur_max;

        max = cur_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur_max = nums[i]+cur_max > nums[i] ? nums[i]+cur_max: nums[i];
            if (cur_max > max)
                max = cur_max;
        }
        return max;
    }
};


int main() {
    
    Solution s;
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v) << endl;
    //vector<int> v2{0, -1, 0};
    //cout << s.maxSubArray(v2) << endl;
    return 0;
}
