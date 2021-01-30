#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<int>> cache(s.length()+1, vector<int>(s.length()+1));
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (slove(s, i, j, cache) == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
    int slove(string& s, int i , int j, vector<vector<int>>& cache) {
        if (cache[i][j] != 0) return cache[i][j];
        if (i > j) {
            cache[i][j] = -1;
            return -1;
        }
        if (i == j) {
            cache[i][j] = 1;
            return 1;
        }
        if (i + 1 == j) {
            cache[i][j] = s[i] == s[j] ? 1 : -1;
            return s[i] == s[j] ? 1: -1;
        }
        if (s[i] == s[j]) {
            cache[i][j] = slove(s, i+1, j-1, cache);
            return cache[i][j];
        } else {
            cache[i][j] = -1;
            return -1;
        }
    }
};

int main() {
    Solution s;
    return 0;
}
