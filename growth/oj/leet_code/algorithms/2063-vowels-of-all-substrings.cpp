#include<iostream>

using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        long long res = 0;
        string target = "aeiou";
        for (int i = 0; i < word.size(); i++) {
            if (target.find(word[i]) == string::npos)
                continue;
            // 本质上我们构造了一个字符串 [0, i-1] [i] [i+1, n]
            // 对于任意一个如上的字符串，i - 0 + 1种选法，后面则有 (n - i - 1 + 1)种选法
            res += (i - 0 + 1) * (word.size() - i);
        }
        return res;
    }
};

int main() {
	Solution s;
	return 0;
}
