#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counter(26);
        for(auto ch : s)
            counter[ch-'a'] += 1;
        int res = -1;
        for(int i = 0; i < 26; i++) {
            if (counter[i] == 1) {
                res = i;
                break;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
