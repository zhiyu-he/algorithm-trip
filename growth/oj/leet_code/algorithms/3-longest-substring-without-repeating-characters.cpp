#include<iostream>
#include<vector>

using namespace std;
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int length = 0;
        int pos = 0;
		vector<int> set;
        set.reserve(256); // note, input source like " " so reserve 2^8 for char
        for (int i = 0; i < s.length(); i++) {
            int idxInSet = char2int(s[i]);
            while (pos < i && set[idxInSet] == 1) {
                int delIdx = char2int(s[pos]);
                set[delIdx] = 0;
                length -= 1;
                pos += 1;
            }
            set[idxInSet] = 1;
            length += 1;
            if (length > max_length) {
                max_length = length;
            }

        }
		return max_length;
    }

    int char2int(char ch) {
        return int(ch);
    }
    
};

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int res = 0;
        int counter[256] = {0};
        int start_idx = 0;
        for (int i = 0; i < s.size(); i++) {
            while(counter[s[i]] != 0 && start_idx < i) {
                counter[s[start_idx]] -= 1;
                start_idx += 1;
            }
            counter[s[i]] += 1;
            res = max(res, i - start_idx + 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.char2int('a') << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
