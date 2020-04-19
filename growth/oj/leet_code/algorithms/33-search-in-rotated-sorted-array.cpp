#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        return divide(nums, target, 0, nums.size()-1);
    }


    int divide(vector<int>&nums, int target, int left, int right) {
        if (left < 0 || left > right)
            return -1;
        int left_idx = -1;
        int right_idx = -1;
        int mid = (right - left) / 2 + left;
        if (nums[left] <= nums[mid]) {
            left_idx = bs(nums, target, left, mid);
        } else {
            left_idx = divide(nums, target, left, mid-1);
        }
        if (nums[mid] <= nums[right]) {
            right_idx = bs(nums, target, mid, right);
        } else {
            right_idx = divide(nums, target, mid+1, right);
        }
        if (right_idx == -1 && left_idx == -1)
            return -1;
        else
            return left_idx >= 0 ? left_idx : right_idx;
    }

    int bs(vector<int>&nums, int target, int left, int right) {
        //cout << "[ " << left << " " << right << " ]" << endl;
        if (left < 0)
            return -1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> v{4,5,6,7,0,1,2};
    Solution s;
    cout << s.search(v, 0) << endl;
    v={4,5,6,7,0,1,2};
    cout << s.search(v, 3) << endl;

    v={2,0,1};
    cout << s.search(v, 1) << endl;
    cout << s.search(v, 0) << endl;
    v={0};
    cout << s.search(v, -1) << endl;
    cout << s.search(v, 0) << endl;


    
    return 0;
}
