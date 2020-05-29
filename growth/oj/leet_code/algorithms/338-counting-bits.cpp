#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return vector<int>{0};
        if (num == 1)
            return vector<int>{0, 1};
        if (num <= 2)
            return vector<int>{0,1,1};
        vector<int> res(num+1);
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
        int cur_2_power = 2;
        for (int i = 3; i <= num; i++) {
            if (i == cur_2_power * 2) {
                res[i] = 1;
                cur_2_power *= 2;
            } else {
                res[i] = 1 + res[i-cur_2_power];
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    auto res = s.countBits(3);
    cout << res.size() << endl;
    return 0;
}
