#include<vector>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left_ptr = 0;
        int right_ptr = nums.size() - 1;

        int next = 0;
        while(next <= right_ptr) {
            if (nums[next] == 0) {
                int tmp = nums[next];
                nums[next] = nums[left_ptr];
                nums[left_ptr] = tmp;
                left_ptr += 1;
            } else if (nums[next] == 2) {
                int tmp = nums[next];
                nums[next] = nums[right_ptr];
                nums[right_ptr] = tmp;
                right_ptr--;
                next--;
            }
            next += 1;

        }


    }
};


int main() {
    Solution s;
    return 0;
}
