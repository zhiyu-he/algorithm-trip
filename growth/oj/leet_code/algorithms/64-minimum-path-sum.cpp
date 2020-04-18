#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++)
            for (int j = 1; j < grid.size(); j++) {
                if (i-1 >= 0) {
                    dp[i][j] = dp[i-1][j];
                }
                if (j-1 >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                }
                dp[i][j] += grid[i][j];
            }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main() {
    return 0;
}
