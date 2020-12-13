#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());

        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1));
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= reverse_s.length(); j++) {
                if (s[i-1] == reverse_s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return s.length() - dp[s.length()][s.length()];
    }
};

int main() {
    Solution s;
    return 0;
}
