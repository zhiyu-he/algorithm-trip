#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> used(10, 0);
        vector<vector<int>> res;
        vector<int> l;
        dfs(res, used, l, 0, k, n);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& used, vector<int> cur_ans, int cur_sum, int k, int target) {
        if (cur_ans.size() == k && cur_sum == target) {
            res.push_back(cur_ans);
            return;
        }
        int start_i = cur_ans.size() == 0 ? 1 : cur_ans.back()+1;
        for (int i = start_i; i <= 9; i++) {
            if (used[i] == 0 && cur_sum + i <= target && cur_ans.size() + 1 <= k) {
                used[i] = 1;
                vector<int> next_cur_ans = cur_ans;
                next_cur_ans.push_back(i);
                dfs(res, used, next_cur_ans, cur_sum + i, k, target);
                used[i] = 0;
            }
        }
        return;
    }
};


int main() {
    Solution s;
    return 0;
}
