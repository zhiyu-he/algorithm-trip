#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         vector<int> prefix_zero;
        vector<int> prefix_one;
        prefix_zero.reserve(nums.size()+1);
        prefix_one.reserve(nums.size()+1);

        prefix_zero[0] = prefix_one[0] = 0;
        int zero_cnt, one_cnt;
        zero_cnt = one_cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zero_cnt += 1;
            else
                one_cnt += 1;
            prefix_zero[i+1] = zero_cnt;
            prefix_one[i+1] = one_cnt;
        }
        int max_len = 0;
        for (int start = 0; start <= nums.size(); start++) {
            for (int end = nums.size(); end > start;) {
                if (end - start < max_len) {
                    break;
                }
                int one_cnt = prefix_one[end] - prefix_one[start];
                int zero_cnt = prefix_zero[end] - prefix_zero[start];
                if (one_cnt == zero_cnt) {
                    if (end-start > max_len)
                        max_len = (end-start);
                    break;
                }
                //end -= prefix_one[end] > prefix_zero[end] ? prefix_one[end] - prefix_zero[end] : prefix_zero[end] - prefix_one[end];
                end -= one_cnt > zero_cnt ? one_cnt - zero_cnt : zero_cnt - one_cnt;
            }
        }
        return max_len;
    }
};

int main() {
    Solution s;
    vector<int> v{0,1,1}; // 2
    cout << s.findMaxLength(v) << endl;
    v = {0,0,0,1,1,1,1}; // 6
    cout << s.findMaxLength(v) << endl;
    v= {0,1}; // 2
    cout << s.findMaxLength(v) << endl;
    v = {1,0,1,0,1,1,0,0}; // 8
    cout << s.findMaxLength(v) << endl;
    v = {0,1,0}; // 2
    cout << s.findMaxLength(v) << endl;
    return 0;
}
