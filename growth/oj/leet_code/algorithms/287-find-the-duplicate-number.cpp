#include<iostream>
#include<vector>

using namespace std;

// TIPS: 注意数组中元素填不满的情况
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        

        for (int i = 0; i < size; i++) {
            if (nums[i]-1 == i) {
                continue;
            }
            int tmp = nums[nums[i]-1];
            // value = index+1
            if (tmp-1 == nums[i]-1) {
                return nums[i];
            }
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
            i = i-1;
        }
        return 0;
    }
};



int main() {
    Solution s;
    //vector<int> nums{8,7,1,10,17,15,18,11,16,9,19,12,5,14,3,4,2,13,18,18};
    vector<int> nums{2,5,9,6,9,3,8,9,7,1};
    auto a = s.findDuplicate(nums);
    cout << a << endl;
    return 0;
}
