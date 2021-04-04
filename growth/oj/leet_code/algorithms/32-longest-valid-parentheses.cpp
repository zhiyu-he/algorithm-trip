#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0) return 0;
        stack<int> stack;
        int res = 0, left_most = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stack.push(i);
            else {
                if (stack.empty()) {
                    left_most = i;
                } else {
                    stack.pop();
                    if (stack.empty()) {
                        res = max(res, i - left_most);
                    } else {
                        res = max(res, i - stack.top());
                    }
                }
            }
        }
        return res;
    }

};


int main() {
	Solution s;
    return 0;
}
