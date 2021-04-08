#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int length = s.length();
        
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            bool isVowels = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U';
            if (isVowels) {
                cnt += i < length/2 ? 1 : -1;
            }
        }
        return cnt == 0;
    }
};

int main() {
    Solution s;
    return 0;
}
