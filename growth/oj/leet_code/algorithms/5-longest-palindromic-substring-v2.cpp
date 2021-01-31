#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:

    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1));
        int max_len = 1, start_i = 0;
        for (int i = 0; i < s.length(); i++)
            dp[i][i] = 1;
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                max_len = 2;
                start_i = i;
            } else {
                dp[i][i+1] = 0;
            }
        }
        for (int len = 3; len <= s.length(); len++) {
            for (int i = 0, j = i + len - 1; j < s.length(); i++, j++) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    max_len = len;
                    start_i = i;
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(start_i, max_len);
    }

};

int main() {
    Solution s;
    return 0;
}
