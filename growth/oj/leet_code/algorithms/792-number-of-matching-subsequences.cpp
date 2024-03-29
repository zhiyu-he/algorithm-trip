#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    unordered_map<string, int> counter;
    int numMatchingSubseq(string s, vector<string>& words) {
        for (string& word : words) {
            counter[word] += 1;
        }
        int cnt = 0;
        for (auto pair : counter) {
            string str = pair.first;
            if (is_subsequence(s, str)) {
                cnt += pair.second;
            }
        }
        return cnt;
    }
    
    bool is_subsequence(string& s, string& word) {
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j == word.length()) break;
            if (s[i] == word[j]) j++;
        }
        return j == word.length();
    }
};

class Solution2 {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = words.size();
        vector<vector<int>> cMap(26);
        for (int i = 0; i < s.length(); i++)
            cMap[s[i]-'a'].push_back(i);
        for(string& word : words) {
            int last = -1;
            for (char ch : word) {
                vector<int>& l = cMap[ch-'a'];
                auto res = upper_bound(l.begin(), l.end(), last);
                if (res == l.end()) {
                    ans -= 1;
                    break;
                } else {
                    last = *res;
                }
            }
        }
        return ans;

    }


};

int main() {
	Solution s;
    Solution2 s2;
    return 0;
}
