#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
            num ^= nums[i];
        return num;
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
