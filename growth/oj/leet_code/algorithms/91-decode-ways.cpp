#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> dp(s.length()+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.length(); i++) {
            int num_i = s[i-1] - '0';
            int num_ii = (s[i-2] - '0') * 10 + num_i;
            if (num_ii == 0) {return 0;}
            int cnt = 0;
            if (num_i != 0) {
                cnt = dp[i-1];
            }
            if (num_ii != num_i && num_ii <= 26) {
                cnt += dp[i-2];
            }
            dp[i] = cnt;
        }
        return dp[s.length()];
    }
};

int main() {
	Solution s;
	return 0;
}
