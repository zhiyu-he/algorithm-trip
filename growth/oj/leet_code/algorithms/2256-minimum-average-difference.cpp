#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefixSum(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefixSum[i] = nums[i];
            } else {
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
        }
        
        double avg = INT_MAX;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            double avg1 = prefixSum[i] / (i - 0 + 1);
            double avg2 = 0;
            if (i != nums.size() - 1) {
                avg2 = (prefixSum[nums.size()-1] - prefixSum[i]) / (nums.size() - (i+1));
            }
            //cout << "size: " << i - 0 + 1 << " size2 " << nums.size() - (i+1) << " avg1 " << avg1 << " avg2 " << avg2 << " avg " << avg << endl;
            if (abs(avg1 - avg2) < avg) {
                idx = i;
                avg = min(avg, abs(avg1 - avg2));
            }
        }
        return idx;
        
    }
};


int main() {
    Solution s;
    return 0;
}
