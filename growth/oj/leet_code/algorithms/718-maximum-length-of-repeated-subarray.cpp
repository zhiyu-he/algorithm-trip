#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() == 0 || B.size() == 0) return 0;
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));
        int max_len = 0;
        for (int i = 1; i <= A.size(); i++) {
            for(int j = 1; j <= B.size(); j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};

int main() {
    Solution s;
    return 0;
}
