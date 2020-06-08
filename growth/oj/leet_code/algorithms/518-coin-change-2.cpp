#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                int delta = j - coins[i];
                if (delta >= 0)
                    dp[j] += dp[delta]
            }
        }
        return dp[amount];
    }
};

int main() {
    return 0;
}
