#include<iostream>
#include<vector>

using namespace std;

// TTL
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target+1);
        return slove(nums, target, cache);
    }

    int slove(vector<int>& nums, int target, vector<int>& cache) {
        if (target == 0) return 1;
        if (cache[target] != 0) {
            return cache[target];
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                cnt += slove(nums, target-nums[i], cache);
            }
        }
        cache[target] = cnt;
        return cnt;
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target+1);
        const int kMaxInt = (1 << 31) - 1;
        cache[0] = 1;
        for (int i = 1; i <= target; i++) {
            cache[i] = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    if (kMaxInt - cache[i] < cache[i-nums[j]]) break;
                    cache[i] += cache[i-nums[j]];
                }
            }
        }
        return cache[target];
    }

};

int main() {
    Solution s;
    return 0;
}
