#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        
        int max_sq = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) {
                dp[i][j] = 0;
                if (matrix[i][j] == 1) {
                    int left = i-1 >= 0 ? dp[i-1][j] : 0;
                    int up = j -1 >= 0 ? dp[i][j-1] : 0;
                    int left_cor = i - 1 >= 0 && j -1 >= 0 ? dp[i-1][j-1] : 0;
                    dp[i][j] = min(min(left, up), left_cor) + 1;
                }
                if (dp[i][j] > max_sq)
                    max_sq = dp[i][j];
                    
            }
        return max_sq;
    }
};


int main() {
    return 0;
}
