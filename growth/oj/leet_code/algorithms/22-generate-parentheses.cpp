#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    int n;
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return vector<string>{"()"};
        }
        vector<string> res;

        dfs(n, 0, 0, "", res);
        return res;
    }
    void dfs(int n, int l_n, int r_n, string str, vector<string>& res) {
        if (str.size() == 2 * n) {
            res.push_back(str);
            return;
        }
        if (l_n == 0) {
            dfs(n, l_n+1, r_n, str + '(', res);
        } else if (l_n < n) {
            dfs(n, l_n+1, r_n, str + '(', res);
            if (l_n > r_n) {
                dfs(n, l_n, r_n+1, str + ')', res);
            }
        } else {
            dfs(n, l_n, r_n+1, str + ')', res);
        }
        return;
    }
};

int main() {
    Solution s;
    return 0;
}
