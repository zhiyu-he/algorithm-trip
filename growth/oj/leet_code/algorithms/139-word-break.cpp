#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<int> cache(s.size()+1, -1);
        return dfs(s, 0, dict, cache);
    }

    bool dfs(string s, int start, unordered_set<string>& dict, vector<int>& cache) {
        if (start == s.size()) {
            return true;
        }
        if (cache[start] != -1) return cache[start];

        for (int i = start+1; i <= s.size(); i++) {
            string sub = s.substr(start, i-start);
            if (dict.count(sub) == 1) {
                if(dfs(s, i, dict, cache)) {
                    cache[start] = 1;
                    return true;
                }
            }
        }
        cache[start] = 0;
        return false;
    }
};


int main() {
    Solution s;
    return 0;
}
