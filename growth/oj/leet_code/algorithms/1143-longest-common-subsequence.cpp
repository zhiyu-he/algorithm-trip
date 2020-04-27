#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length()));
    

        int max_seq = 0;
        for (int i = 0; i < text1.length(); i++)
            for (int j = 0; j < text2.length(); j++) {
                int incr = text2[j] == text1[i] ? 1 : 0;
                if (i == 0 && j == 0) {
                    dp[i][j] = incr;
                    continue;
                }
                if (i == 0){
                    dp[i][j] = max(dp[i][j-1], incr);
                } else if (j == 0) {
                    dp[i][j] = max(dp[i-1][j], incr);
                } else {
                    if (incr == 0)
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    else
                        dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+1);
                }
                if (dp[i][j] > max_seq)
                    max_seq = dp[i][j];
            }
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                cout << dp[i][j] << "  ";
            }

            cout << endl;
        }
        return max_seq;
    }
};

int main() {
    Solution s;
    cout << s.longestCommonSubsequence("abcde", "ace") << endl;
    cout << s.longestCommonSubsequence("abc", "abc") << endl;
    cout << s.longestCommonSubsequence("abc", "def") << endl;

    cout << s.longestCommonSubsequence("bsbininm", "jmjkbkjkv") << endl;

    cout << s.longestCommonSubsequence("xybrgc", "bgcrcbh") << endl;




    return 0;
}
