#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> cache(s.length()+1, vector<int>(s.length()+1));
        return slove(s, 0, s.length()-1, cache);
    }
    
    int slove(string& s, int i, int j, vector<vector<int>>& cache) {
        if (cache[i][j] != 0) return cache[i][j];
        if (i > j) return 0;
        if (i == j) return 1;
        if (s[i] == s[j]) {
            int res = 2 + slove(s, i+1, j-1, cache);
            cache[i][j] = res;
            return res;
        }
        int res = max(slove(s, i+1, j, cache), slove(s, i, j-1, cache));
        cache[i][j] = res;
        return res;
    }
};


int main() {
	Solution s;
    return 0;
}
