#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        slove(res, S, 0);
        return res;
    }
    void slove(vector<string>& res, string& S, int idx) {
        if (idx == S.length()) {
            res.push_back(S);
            return;
        }
        int code = int(S[idx]);
            if (code >= 48 && code <= 57)
                slove(res, S, idx+1);
            else {
                if (code >= 65 && code <= 90) {
                    slove(res, S, idx+1);
                    S[idx] = S[idx] + 32;
                    slove(res, S, idx+1);
                    S[idx] = S[idx] - 32;
                } else {
                    slove(res, S, idx+1);
                    S[idx] = S[idx] - 32;
                    slove(res, S, idx+1);
                    S[idx] = S[idx] + 32;
                }
            }

    }
};



int main() {
    Solution s;
    return 0;
}
