#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        //cout << matrix.size() << endl;

        int counter_cnt = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++) {
                dp[i][j] = 0;
                if (matrix[i][j] == 1) {
                    int left = i-1 >= 0 ? dp[i-1][j] : 0;
                    int up = j -1 >= 0 ? dp[i][j-1] : 0;
                    int left_cor = i - 1 >= 0 && j -1 >= 0 ? dp[i-1][j-1] : 0;
                    dp[i][j] = min(min(left, up), left_cor) + 1;
                }
                if (dp[i][j] > 0) {
                    counter_cnt += dp[i][j];
                }
            }

        return counter_cnt;
    }
};

int main() {
    return 0;
}
