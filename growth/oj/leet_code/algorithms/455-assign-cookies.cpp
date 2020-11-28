#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_idx = 0;
        int fit = 0;
        for (int i = 0; i < s.size(); i++) {
            if (child_idx < g.size() && s[i] >= g[child_idx]) {
                fit += 1;
                child_idx += 1;
            }
        }
        return fit;
    }
};

int main() {
    Solution s;
    return 0;
}
