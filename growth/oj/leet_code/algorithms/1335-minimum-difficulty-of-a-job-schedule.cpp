#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (d > jobDifficulty.size()) return -1;
        vector<vector<int>> dp(jobDifficulty.size()+1, vector<int>(d+1));
        for (int i = 1; i <= jobDifficulty.size(); i++) {
            for (int k = 1; k <= min(i, d); k++) {
                int cur_max = jobDifficulty[i-1];
                dp[i][k] = INT_MAX;
                for (int j = i; j >= k; j--) {
                    cur_max = max(cur_max, jobDifficulty[j-1]);
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + cur_max);
                }
                if (k == 1) dp[i][k] = cur_max;
                //cout << "i " << i << " k " << k << " dp[i][k] " << dp[i][k] << endl;
            }
        }
        return dp[jobDifficulty.size()][d];
    }
};


int main() {
    Solution s;
    return 0;
}
