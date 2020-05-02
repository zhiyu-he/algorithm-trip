#include<iostream>
#include<unordered_set>

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> j;
        for (auto ch : J) {
            j.insert(ch);
        }
        int cnt = 0;
        for (auto s : S)
            cnt += j.find(s) == j.end() ? 0 : 1;
        return cnt;
    }
};

int main() {
    return 0;
}
