#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        slove(n, k, res, ans, 0);
        return res;
    }
    void slove(int n, int k, vector<vector<int>>& res, vector<int> ans, int size) {
        if (size == k) {
            res.push_back(ans);
        }
        int num = ans.size() == 0 ? 1 : ans.back() + 1;
        for (; num <= n && size < k; num++) {
            ans.push_back(num);
            slove(n, k, res, ans, size+1);
            ans.pop_back();
        }

    }
};

// TODO add dp solution


int main() {
    Solution s;
    return 0;
}
