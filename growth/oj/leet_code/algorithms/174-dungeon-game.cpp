#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size()));

        int x_bound = dungeon.size();
        int y_bound = dungeon[0].size();


        vector<vector<int>> steps{{-1, 0}, {0, -1}};

        dp[x_bound-1][y_bound-1] = max(1, -dungeon[x_bound-1][y_bound-1]+1);

        for (int i = x_bound-1; i >= 0; i--)
            for (int j = y_bound-1; j >= 0; j--) {
                if (i == x_bound-1 && j == y_bound-1) continue;

                if (i == x_bound-1) {
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
                    continue;
                }
                if (j == y_bound-1) {
                    dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
                    continue;
                }
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);

            }


        return dp[0][0];
    }
};


int main() {
    Solution s;
    return 0;
}
