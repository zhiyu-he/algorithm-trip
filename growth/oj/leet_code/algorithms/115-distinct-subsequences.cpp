#include<iostream>
#include<vector>

using namespace std;
// TTL
class Solution2 {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> cache(s.size()+1, vector<int>(t.size()+1));
        return slove(s, t, 0, 0, cache);
    }
    int slove(string& s, string& t, int s_idx, int t_idx, vector<vector<int>>& cache) {
        if (t_idx == t.size()) return 1;
        if (s_idx == s.size()) return 0;
        if (cache[s_idx][t_idx] != 0) return cache[s_idx][t_idx];

        int cnt = 0;

        if (s[s_idx] == t[t_idx]) {
            cnt += slove(s, t, s_idx+1, t_idx+1, cache);
            cnt += slove(s, t, s_idx+1, t_idx, cache);
        } else {
            cnt += slove(s, t, s_idx+1, t_idx, cache);
        }
        cache[s_idx][t_idx] = cnt;
        return cnt;
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> dp(s.size()+1, vector<long>(t.size()+1));
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {

                    if (s[i-1] == t[j-1]) {
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
            }
        }
        return dp[s.size()][t.size()];
    }

};



int main() {
    Solution s;
    return 0;
}
