#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = (nums.size() + 1) / 2 - 1;
        
        int sum = 0;
        for(int i = 0; i < target; i++)
            sum += (nums[target] - nums[i]);
        
        for (int i = target + 1; i < nums.size(); i++)
            sum += (nums[i] - nums[target]);
        return sum;
    }
};


int main() {
	Solution s;
	return 0;
}
