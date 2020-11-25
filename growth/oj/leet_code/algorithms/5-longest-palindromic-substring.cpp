#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int max_i = 0, max_j = 0;
    int max_len = 1;
    string longestPalindrome(string s) {
        vector<vector<int>> cache(s.length()+1, vector<int>(s.length()+1));
        int max_len = slove(s, 0, s.length(), cache);
        //cout << max_len << endl;
        return s.substr(max_i, max_len);
    }
    int slove(string& s, int i, int j, vector<vector<int>>& cache) {
        if (i == j) return 1;
        if (cache[i][j] > 0) return cache[i][j];
        if (cache[i][j] == -1) return 0;
        if (s[i] == s[j] && i+1 == j) {
            //cout << "i " << i << " j " << j << endl;
            if (2 > max_len) {
                max_len = 2;
                max_i = i;
                max_j = j;
            }
            cache[i][j] = 2;
            return 2;
        };
        if (s[i] == s[j] && j-i+1-2 == 1) {if (3 > max_len) {max_len = 3; max_i = i; max_j = j;}return 3;};
        if (s[i] == s[j]) {
            int tmp = slove(s, i+1, j-1, cache);
            //cout << "i " << i << " j " << j << " tmp " << tmp << endl;
            if (tmp == j-i+1-2) {
                if (2 + tmp > max_len) {
                    max_len = 2 + tmp;
                    max_i = i;
                    max_j = j;
                }
                cache[i][j] = 2 + tmp;
                return 2 + tmp;
            }

        }
        int c1 = slove(s, i+1, j, cache);
        int c2 = slove(s, i, j-1, cache);
        if (c1 > max_len) {
            max_len = c1;
            max_i = i;
            max_j = j;
        }
        if (c2 > max_len) {
            max_len = c2;
            max_i = i;
            max_j = j;
        }
        cache[i][j] = max(c1, c2);
        return max(c1, c2);
    }
};

int main() {
    Solution s;
    return 0;
}
