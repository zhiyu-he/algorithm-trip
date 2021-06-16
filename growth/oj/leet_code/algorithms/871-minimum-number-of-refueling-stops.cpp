#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<long> dp(stations.size()+1);
        dp[0] = startFuel;
        for (int cnt = 1; cnt <= stations.size(); cnt++) {
            for (int j = cnt; j > 0; j--) {
                if (dp[j-1] >= stations[cnt-1][0]) {
                    dp[j] = max(dp[j-1]+stations[cnt-1][1], dp[j]);
                }
            }
        }
        for (int i = 0; i <= stations.size(); i++) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }
};


int main() {
    Solution s;
    return 0;
}
