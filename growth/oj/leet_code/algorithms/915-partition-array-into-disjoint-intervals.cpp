#include<iostream>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        
        vector<int> l_max(nums.size());
        vector<int> r_min(nums.size(), INT_MAX);

        l_max[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            l_max[i] = max(l_max[i-1], nums[i]);
        }
      
        r_min[0] = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--) {
            r_min[i] = min(r_min[i+1], nums[i]);
        }

        // max(0, idx) < min(idx+1, r)
        for (int i = 0; i < nums.size()-1; i++) {
            //cout << "l " << l_max[i] << " r " << r_min[i+1] << endl;
            if (l_max[i] <= r_min[i+1]) return i+1;
        }
        return 1;
    }
};


int main() {
	return 0;
}
