#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        for (; j < nums.size(); j++)
            nums[j] = 0;
    }
};

void p(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;
}


int main() {
    Solution s;
    vector<int> v{0,1,0,3,12};
    s.moveZeroes(v);
    p(v);
    vector<int> v2{0,0,1,2,3};
    s.moveZeroes(v2);
    p(v2);

    vector<int> v3{0,1,0,0};
    s.moveZeroes(v3);
    p(v3);

    vector<int> v4{1,2,0,0};
    s.moveZeroes(v4);
    p(v4);


    return 0;
}
