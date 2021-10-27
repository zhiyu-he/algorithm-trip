#include<iostream>

using namespace std;

class Solution {
public:
    const static int N = 366;
    int dp[N];
    int cache[N];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // cost[0] 相当于dp[i-cost[0]-day], dp[i-cost[1]-day] dp[i-cost[2]-day] 取最小
        // 但是, days不连续, 此时要如何处理呢？
        // dp[i] 代表从day[i]出发到结尾的最小费用
        memset(cache, -1, sizeof cache);
        slove(0, days, costs);
        return dp[0];
    }
    int slove(int i, vector<int>& days, vector<int>& costs) {
        if (i >= days.size()) return 0;
        if (cache[i] != -1) return cache[i];
        // dp[i] + {1, 7, 30} < dp[j] 不可触达，则需要进行求解
        vector<int> k_days = {1, 7, 30};
        int j = i;
        int ans = INT_MAX;
        for (int _k = 0; _k < 3; _k++) {
            // 如何判断终止, 即当前可以达到的最远的地方
            while(j < days.size() && days[i] + k_days[_k] > days[j]) {
                j++;
            }
            ans = min(ans,  slove(j, days, costs) + costs[_k]);
        }
        dp[i] = ans;
        cache[i] = ans;
        return ans;
    }
};


int main() {
	return 0;
}
