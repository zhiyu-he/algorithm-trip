#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return slove(s, set, 0);
    }
    int slove(string& s, unordered_set<string>& set, int str_pos) {
        if (str_pos == s.length()) {
            return set.size();
        }
        int cur_max = 0;
        for (int size = 1; size + str_pos <= s.length(); size++) {
            string sub = s.substr(str_pos, size);
            if (set.find(sub) != set.end()) continue;
            set.insert(sub);
            cur_max = max(cur_max, slove(s, set, str_pos+size));
            set.erase(sub);
        }
        return cur_max;
    }
};

int main() {
    Solution s;
    return 0;
}
