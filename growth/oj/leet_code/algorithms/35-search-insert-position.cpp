#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int i = 0;
        int j = nums.size() - 1;

        int res = 0;
        while(i <= j) {
            int mid = (j - i) / 2 + i;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return i;
    }
};

int main() {
    Solution s;
    return 0;
}
