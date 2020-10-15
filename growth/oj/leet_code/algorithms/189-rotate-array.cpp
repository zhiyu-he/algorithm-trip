#include<iostream>
#include<vector>

using namespace std;

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || nums.size() == 1) return;
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, k, nums.size()-1);
        reverse(nums, 0, k-1);
    }

    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || nums.size() == 1) return;
        k %= nums.size();
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
        i = k; j = nums.size() - 1;
        while(i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
        i = 0; j = k - 1;
        while(i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
};

int main() {
    Solution s;
    return 0;
}
