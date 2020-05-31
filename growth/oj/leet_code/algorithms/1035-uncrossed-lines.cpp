#include<vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));

        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                if(A[i] == B[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }

        return dp[A.size()][B.size()];
    }
};


int main() {
    return 0;
}
