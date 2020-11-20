#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        slove(candidates, target, res, ans, 0, 0);
        return res;
    }
    void slove(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& ans, int cur_sum, int idx) {
        if (cur_sum == target) {
            res.push_back(ans);
        }
        unordered_set<int> du;
        for (int i = idx; i < candidates.size(); i++) {
            if (du.find(candidates[i]) != du.end()) continue;
            if (cur_sum + candidates[i] <= target) {
                du.insert(candidates[i]);
                ans.push_back(candidates[i]);
                slove(candidates, target, res, ans, cur_sum + candidates[i], i + 1);
                ans.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}
