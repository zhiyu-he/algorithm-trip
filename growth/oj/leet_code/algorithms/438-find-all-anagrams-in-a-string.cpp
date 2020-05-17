#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        unordered_map<char, int> counter;

        for (auto c : p)
            counter[c] += 1;

        int expected_cnt = p.length();
        int miss_cnt = 0;



        for (int i = 0; i < s.length(); i++) {
            if (i >= p.length()) {
                if (counter.find(s[i-p.length()]) == counter.end()) {
                    miss_cnt -= 1;
                } else {
                    if (counter[s[i-p.length()]] < 0) {
                        expected_cnt -= 1;
                    } else {
                        expected_cnt += 1;
                    }
                    counter[s[i-p.length()]] += 1;

                }
            }
            if (counter.find(s[i]) == counter.end()) {
                miss_cnt += 1;
            } else {
                if (counter[s[i]] > 0) {
                    expected_cnt -= 1;
                } else {
                    expected_cnt += 1;
                }
                counter[s[i]] -= 1;

            }
            if (expected_cnt == 0 && miss_cnt == 0) {
                res.push_back(i-p.length()+1);
            }
        }


        return res;
    }
};

int main() {
    return 0;
}
