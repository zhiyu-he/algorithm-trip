#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, p_prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = max(prev, p_prev + nums[i]);
            p_prev = prev;
            prev = cur;
        }
        return max(prev, p_prev);
    }
};

int main() {
    Solution s;
    return 0;
}
