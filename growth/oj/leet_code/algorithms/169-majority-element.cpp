#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> tmp(nums.size());
        merge_sort(nums, tmp, 0, nums.size()-1);
        for (int i = 0; i < nums.size(); i++)
            cout << " " << nums[i];
        cout << endl;

        return nums[nums.size()/2];
    }

    void merge_sort(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left < right) {
            int mid = (right - left) / 2 + left;
            merge_sort(nums, tmp, left, mid);
            merge_sort(nums, tmp, mid+1, right);
            merge(nums, tmp, left, mid+1, right);
            for (int i = left; i <= right; i++)
                cout << nums[i] << " " ;
            cout << endl;
        }

    }

    void merge(vector<int>& nums, vector<int>& tmp, int left, int mid, int right) {
        for (int i = left; i <= right; i++)
            tmp[i] = nums[i];
        int i = left;
        int j = mid;
        while (i < mid && j <= right) {
            if (tmp[i] <= tmp[j]) {
                nums[left++] = tmp[i++];
            } else {
                nums[left++] = tmp[j++];
            }
        }
        while(i < mid) {
            nums[left++] = tmp[i++];
        }
        while(j <= right) {
            nums[left++] = tmp[j++];
        }
    }


};

int main() {
    Solution s;
    vector<int> nums{5,4,3,3,2,2,1};
    nums = {3,2,1};
    s.majorityElement(nums);
    return 0;
}
