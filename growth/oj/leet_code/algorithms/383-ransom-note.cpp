#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counter(256);
        for (auto ch : magazine)
            counter[ch] += 1;
        for (auto ch : ransomNote) {
            if (counter[ch] == 0)
                return false;
            counter[ch] -= 1;
        }
        return true;
    }
};

int main() {
    return 0;
}
