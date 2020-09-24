#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int counter = 0;
        for(int i = 2; i < nums.size(); i++) {
            int target = nums[i];
            int j = 0, k = i-1;
            while(j < k) {
                if (nums[j]+nums[k] > target) {
                    counter += (k-j);
                    k--;
                } else {
                    j++;
                }
            }
        }
        return counter;
    }
};

int main() {

    return 0;
}
