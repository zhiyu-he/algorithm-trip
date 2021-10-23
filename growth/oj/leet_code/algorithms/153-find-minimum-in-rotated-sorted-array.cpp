#include<iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[l] < nums[r]) return nums[l];
            if (nums[r] < nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return  nums[r];
    }
};

int main() {
	return 0;
}
