#include<iostream>

using namespace std;

class Solution {
public:
    int dp[210][210];
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0,  1, -1};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof dp);
        int max_val = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) {
                max_val = max(max_val, 1 + dfs(i, j, matrix[i][j], matrix));
            }
        return max_val;
    }
    
    int dfs(int row, int col, int pre, vector<vector<int>>& matrix) {
        if (row < 0 || col < 0 || row == matrix.size() || col == matrix[matrix.size()-1].size()) return 0;
        if (dp[row][col] != -1) return dp[row][col];

        int max_val = 0;

        for (int i = 0; i < 4; i++) {
            int n_row = row + x[i];
            int n_col = col + y[i];
            
            if (n_row < 0 || n_col < 0 || n_row == matrix.size() || n_col == matrix[matrix.size()-1].size()) continue;
            if (matrix[n_row][n_col] > pre) {
                int n_pre = matrix[n_row][n_col];
                max_val = max(max_val, 1 + dfs(n_row, n_col, n_pre, matrix));
            }
        }
        dp[row][col] = max_val;
        return max_val;
    }
};


int main() {
	return 0;
}
