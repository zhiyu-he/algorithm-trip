#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void p(vector<int>& v) {
    cout << "start" << endl;
    for (int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;
}


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int zeroCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zeroCnt += 1;
            }
            res[i] = -1;
        }
        if (zeroCnt >= 2)
            return res;
        int forward = nums[0];
        int backward = nums[nums.size()-1];
        for (int i = 1; i < nums.size() - 1; i++) {
            cout << "f " << forward << endl;
            res[i] = forward;
            forward *= nums[i];
        }
        res[nums.size()-1] = forward;

        p(res);
        for (int i = nums.size() - 2; i >= 1; i--) {
            cout << "b: " << backward << endl;
            res[i] *= backward;
            backward *= nums[i];
        }
        res[0] = backward;
        p(res);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v{1,2,3};
    auto res = s.productExceptSelf(v);
    v={1,2,0,2,1};
    res = s.productExceptSelf(v);
    v={1,2};
    res = s.productExceptSelf(v);
    v={0};
    res = s.productExceptSelf(v);
    v={4,3,2,1,2};
    res = s.productExceptSelf(v);


    

    return 0;
}
