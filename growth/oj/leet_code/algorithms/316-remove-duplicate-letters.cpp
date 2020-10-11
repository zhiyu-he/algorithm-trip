#include<iostream>
#include<stack>


using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {0};
        int visit[26] = {0};
        for (int i = 0; i < s.length(); i++)
            cnt[s[i]-'a'] += 1;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            //cout << "st.size() " << st.size() << endl;
            cnt[s[i]-'a'] -= 1;
            if (visit[s[i]-'a']) continue;
            // handle lexicographical order
            while(!st.empty() && st.top() > s[i] && cnt[st.top()-'a'] > 0) {
                //cnt[st.top()-'a'] -= 1;
                visit[st.top()-'a'] = 0;
                //cout << "pop " << st.top() << endl;
                st.pop();

            }
            //cout << "s[i] " << s[i] << endl;
            st.push(s[i]);
            visit[s[i]-'a'] = 1;
            //cnt[s[i]-'a'] -= 1;
        }
        stack<char> res;
        //cout << "size " << st.size() << endl;
        while(!st.empty()) {
            //cout << "st " << st.top() << endl;
            res.push(st.top());
            st.pop();
        }
        string ans = "";
        while(!res.empty()) {
            //cout << "res " << res.top() << endl;
            ans += res.top();
            res.pop();
        }
        return ans;
    }
};

int main() {
    return 0;
}
