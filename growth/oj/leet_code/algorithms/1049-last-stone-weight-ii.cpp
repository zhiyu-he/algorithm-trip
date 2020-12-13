#include<iostream>
#include<vector>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>> cache(stones.size()+1, vector<int>(6001));
        return slove(stones, 0, 0, cache);
    }
    int slove(vector<int>& stones, int cur_idx, int cur_sum, vector<vector<int>>& cache) {
        if (cur_idx == stones.size()) {
            if (cur_sum >= 0) return cur_sum;
            return INT_MAX;
        }
        if (cache[cur_idx][cur_sum+3000] != 0) return cache[cur_idx][cur_sum+3000];
        int case1 = slove(stones, cur_idx+1, cur_sum+stones[cur_idx], cache);
        int case2 = slove(stones, cur_idx+1, cur_sum-stones[cur_idx], cache);
        cache[cur_idx][cur_sum+3000] = min(case1,case2);
        return cache[cur_idx][cur_sum+3000];
    }
};

int main() {
    Solution s;
    return 0;
}
