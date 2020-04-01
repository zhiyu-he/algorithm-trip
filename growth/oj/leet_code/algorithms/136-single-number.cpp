#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[nums.size()-1] != nums[nums.size()-2])
            return nums[nums.size()-1];
        int cnt = 0;
        for(int i = 0; i < nums.size() - 2; i += 2)
            if (nums[i] != nums[i+1]) {
                if (nums[i-1] == nums[i])
                    return nums[i+1];
                else
                    return nums[i];
            }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> v{4,1,2,1,2};
    cout << s.singleNumber(v) << endl;
    


    vector<int> v2{2,2,1};
    cout << s.singleNumber(v2) << endl;
    vector<int> v3{17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6};
    cout << s.singleNumber(v3) << endl;

    return 0;
}
