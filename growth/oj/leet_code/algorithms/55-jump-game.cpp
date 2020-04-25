#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;

        for (int i = 0; i <= nums.size()-1;) {
            if (nums[i] == 0) return false;
            if (i + nums[i] >= nums.size()-1) return true;
            int max_dis = 0;
            int next_i = 0;
            for(int j = 1; j <= nums[i]; j++) {
                if(nums[i+j] != 0 && i+j + nums[i+j] > max_dis) {
                    next_i = i + j;
                    max_dis = i + j + nums[i+j];
                }
            }
            if (next_i == 0) return false;
            cout << "next_i " << next_i << endl;
            i = next_i;
        }
        cout << "endl" << endl;
        return false;
    }
};
int main() {
    Solution s;
    vector<int> v{3,2,1,0,4};
    cout << s.canJump(v) << endl;
    return 0;
}
