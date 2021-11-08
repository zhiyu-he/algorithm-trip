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
            res += (i - 0 + 1) * (word.size() - i);
        }
        return res;
    }
};

int main() {
	Solution s;
	return 0;
}
