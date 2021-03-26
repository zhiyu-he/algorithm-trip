#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> t = vector<int>(26);
        for (int i = 0; i < B.size(); i++) {
            vector<int> c(26);
            for (char ch : B[i]) {
                c[ch-'a'] += 1;
            }
            for (char ch : B[i]) {
                t[ch-'a'] = max(t[ch-'a'], c[ch-'a']);
            }
        }
        int total = 0;
        for (int i = 0; i < 26; i++) {
            total += t[i];
        }
        vector<string> res;
        for (int i = 0; i < A.size(); i++) {
            if (A[i].size() < total) continue;
            vector<int> c(26);
            for (char ch : A[i])
                c[ch-'a'] += 1;
            bool ok = true;
            for (int j = 0; j < 26; j++)
                if (t[j] > 0 && t[j] > c[j]) {
                    ok = false;
                    break;
                }
            if (ok) res.push_back(A[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
