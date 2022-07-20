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

int main() {
	Solution s;
    return 0;
}
