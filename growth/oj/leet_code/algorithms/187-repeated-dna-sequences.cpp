#include<iostream>
#include<vector>
#include<unordered_map>
#include<bitset>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 10) return res;
        unordered_map<string, int> counter;
        for (int i = 0; i <= s.size() - 10; i++) {
            counter[s.substr(i, 10)] += 1;
            //cout << "s.substr(i, 10) " << i << " " << s.substr(i, 10) << endl;
        }
        for (auto pair : counter) {
            if (pair.second > 1) res.push_back(pair.first);
        }
        return res;
    }

    vector<string> findRepeatedDnaSequences2(string s) {
        vector<string> res;
        if (s.size() < 10) return res;
        // we need 20bits to present a substr. so use mask to drop out left 2bit size
        int mask = (1<<21) - 1;
        bitset<1<<20> has_seen;
        bitset<1<<20> more_than_once;
        
        // handle first substr
        int val = 0;
        for(int i = 0; i < 10; i++) {
            val = (val << 2 | encode(s[i]));
        }
        has_seen.set(val);
        for (int i = 10; i < s.size(); i++) {
            // slide 1 window
            val = ((val << 2) & mask) | encode(s[i]);
            if (more_than_once[val]) continue;
            if (has_seen[val]) {
                res.push_back(s.substr(i-10+1,10));
                more_than_once.set(val);
            } else {
                has_seen.set(val);
            }

        }
        return res;
    }
    int encode(char ch) {
        switch(ch) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return 0;
    }


};


int main() {
    return 0;
}
