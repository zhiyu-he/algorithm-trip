#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        if (s.size() == 0)
            return true;
        stack<int> s1, s2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                s1.push(i);
            if (s[i] == '*')
                s2.push(i);
            if (s[i] == ')') {
                if (!s1.empty()) {
                    s1.pop();
                    continue;
                }
                if (!s2.empty()) {
                    s2.pop();
                    continue;
                }
                return false;
            }
        }
        while(!s1.empty() && !s2.empty()) {
            if (s2.top() > s1.top()) {
                s1.pop();
                s2.pop();
            } else
                break;
        }
        return s1.empty();
    }
};


int main() {
    Solution s;
    /*
    cout << s.checkValidString("()") << endl;
    cout << s.checkValidString("(*)") << endl;
    cout << s.checkValidString("(*))") << endl;
    cout << s.checkValidString("") << endl;
    cout << s.checkValidString("*******") << endl;

    cout << s.checkValidString(")(") << endl;
    cout << s.checkValidString("((") << endl;
    cout << s.checkValidString("(*") << endl;
    cout << s.checkValidString("()*((()(((((*))))((*()((*(())()(**)()()*))((((()**((())((()()(()(()()*)()))(()))))))*(((()()()())()") << endl;
    */
    cout << s.checkValidString("*()(())*()(()()((()(()()*)(*(())((((((((()*)(()(*)") << endl;




    return 0;
}
