#include<iostream>

using namespace std;

class Solution {
public:
    static const int N = 1e5 + 10;
    int ne[N];
    string longestPrefix(string s) {
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while(j != 0 && s[i] != s[j]) {
                j = ne[j];
                //cout << "j " << j << " i " << i << " ne " << ne[j] << endl;
            }
            if (s[i] == s[j]) j++;
            ne[i+1] = j;
        }
        
        return s.substr(0, ne[s.size()]);
        
    }
};

int main() {
	Solution s;
	return 0;
}
