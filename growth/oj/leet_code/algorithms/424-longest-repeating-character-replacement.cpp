#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counter(26);
        int start = 0;
        int res = 0;
        int cur_max_counter = 0;
        for (int end = 0; end < s.length(); end++) {
            counter[s[end]-'A'] += 1;
            cur_max_counter = max(cur_max_counter, counter[s[end]-'A']);
            while(end-start+1 - cur_max_counter > k) {
                counter[s[start]-'A'] -= 1;
                start += 1;
            }
            res = max(res, end-start+1);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
