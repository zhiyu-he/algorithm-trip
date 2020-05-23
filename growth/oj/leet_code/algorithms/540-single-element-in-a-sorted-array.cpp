#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int single_idx = -1;


        while(left <= right) {
            bool is_left = false;
            bool is_right = false;
            int mid = (right - left) / 2 + left;


            if (mid+1 <= right && nums[mid] == nums[mid+1]) {
                is_left = true;
            } else if (mid-1 >= left && nums[mid] == nums[mid-1]) {
                is_right = true;
            }
            cout << "  " << left << "  " << right << "   " << mid << " " << is_left << " " << is_right << endl;

            if (is_left) {
                int l_dis = mid - left;
                if (l_dis % 2 != 0) {
                    right = mid-1;
                } else {
                    left = mid+2;
                }
                continue;
            }
            if (is_right) {
                int r_dis = right - mid;
                if (r_dis % 2 != 0) {
                    left = mid + 1;
                } else {
                    right = mid - 2;
                }
                continue;
            }
            if (!is_left && !is_right) {
                single_idx = mid;
                break;
            }

        }
        return nums[single_idx];
    }
};

int main() {
    return 0;
}
