#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;

        vector<vector<int>> counter = vector<vector<int>>(2, vector<int>(28, 0));
        for (char ch : word1) {
            counter[0][ch - 'a'] += 1;
        }
        for (char ch : word2) {
            counter[1][ch - 'a'] += 1;
        }

        // case1 same (char, score)
        bool isOk = true;
        for (int i = 0; i < 28; i++) {
            if (counter[0][i] != counter[1][i]) {
                isOk = false;
                break;
            }
        }
        if (isOk) return true;
        unordered_map<int, int> times2char1, times2char2;
        long long bit1 = 0, bit2 = 0;
        // case2
        for (int i = 0; i < 28; i++) {
            if (counter[0][i] != 0) {
                times2char1[counter[0][i]] += 1;
                bit1 |= 1 << i;
            }
            if (counter[1][i] != 0) {
                times2char2[counter[1][i]] += 1;
                bit2 |= 1 << i;
            }
        }

        if (bit1 != bit2) return false;

        for (auto kv : times2char1) {
            if (times2char2.count(kv.first) == 0) return false;
            if (times2char2[kv.first] != kv.second) return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    return 0;
}
