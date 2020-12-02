#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size()+1);
        return min(slove(cost, 0, cache), slove(cost,1, cache));
    }
    int slove(vector<int>&cost, int i, vector<int>& cache) {
        if (i == cost.size()) return 0;
        if (i == cost.size()-1) return cost[i];
        if (i == cost.size()-2) return cost[i];
        if (cache[i] > 0) return cache[i];
        
        int case1 = INT_MAX, case2 = INT_MAX;
        if (i+2 < cost.size())
            case1 = cost[i] + slove(cost, i+2, cache);
        case2 = cost[i] + slove(cost, i+1, cache);
        cache[i] =  min(case1, case2);
        return cache[i];
    }
};

int main() {
    Solution s;
    return 0;
}
