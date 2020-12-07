#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1));
        for (int i = 1; i <= str1.length(); i++)
            for (int j = 1; j <= str2.length(); j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        string res = "";
        int l1 = str1.length(), l2 = str2.length();
        while(l1 > 0 && l2 > 0) {
            if (str1[l1-1] == str2[l2-1]) {
                res += str1[l1-1];
                l1--;
                l2--;
            } else if (dp[l1-1][l2] == dp[l1][l2]) {
                res += str1[l1-1];
                l1--;
            } else {
                res += str2[l2-1];
                l2--;
            }
        }
        while(l1 > 0) res += str1[--l1];
        while(l2 > 0) res += str2[--l2];
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
