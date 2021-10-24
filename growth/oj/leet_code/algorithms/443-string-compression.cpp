#include<iostream>

using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return chars.size();
        int i = 0;
        int cnt = 1;
        for (int j = 1; j <= chars.size(); j++) {
            while(j < chars.size() && chars[j-1] == chars[j]) {
                cnt += 1;
                j++;
            }
            chars[i++] = chars[j-1];
            if (cnt >= 2) {
                for (auto ch : to_string(cnt))
                    chars[i++] = ch;
            }
            cnt = 1;
        }
        return i;
    }
};

int main() {
	return 0;
}
