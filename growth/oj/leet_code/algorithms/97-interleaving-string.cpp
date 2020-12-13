#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<vector<int>>> cache(s1.length()+1, vector<vector<int>>(s2.length()+1, vector<int>(s3.length()+1, -1)));


        return dfs(s1, s2, s3, 0, 0, 0, cache);
    }
    bool dfs(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& cache) {
        if (k == s3.size() && i == s1.length() && j == s2.length()) return true;
        if (k == s3.size()) return false;
        if (cache[i][j][k] != -1) {
            return cache[i][j][k] == 1 ? true : false;

        }
        bool res = false;
        if (i < s1.length()) {
            if (s1[i] == s3[k]) {
                res = res || dfs(s1, s2, s3, i+1, j, k+1, cache);
            } else {
                res = res || dfs(s1, s2, s3, i+1, j, k, cache);
            }
        }
        if (j < s2.length()) {
            if (s2[j] == s3[k]) {
                res = res || dfs(s1, s2, s3, i, j+1, k+1, cache);
            } else {
                res = res || dfs(s1, s2, s3, i, j+1, k, cache);
            }
        }
        cache[i][j][k] = res == true ? 1 : 0;
        return res;
    }

};


int main() {
    Solution s;
    return 0;
}
