#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount <= 0) return 0;
        if (coins.size() == 0) return -1;
        vector<int> dp = vector<int>(amount+1);
        for (int i = 1; i <= amount; i++) {
            dp[i] = -1;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    int ans = i - coins[j] == 0 ? 1 : dp[i];
                    if (dp[i-coins[j]] > 0)
                        ans = dp[i] == -1 ? dp[i-coins[j]] + 1 : min(ans, dp[i-coins[j]] + 1);
                    dp[i] = ans;
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,5};
    cout << s.coinChange(v, 11) << endl;
    v = {2};
    cout << s.coinChange(v, 3) << endl;
    return 0;
}
