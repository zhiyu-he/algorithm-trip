#include<iostream>
#include<vector>
#include<set>


using namespace std;

class Solution2 {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> init;
        dfs(nums, 0, res, init);

        return res;
    }

    void dfs(vector<int>& nums, int cur_pos, vector<vector<int>>& res, vector<int> l) {
        if (l.size() >= 2) res.push_back(l);
        unordered_set<int> dup;
        for (int i = cur_pos; i < nums.size(); i++) {
            if ((l.size() > 0 && l.back() > nums[i]) || (dup.count(nums[i]))) continue;
            dup.insert(nums[i]);
            l.push_back(nums[i]);
            dfs(nums, i+1, res, l);
            l.pop_back();
        }

    }
};

class Solution {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int>> res;
        vector<int> init;
        dfs(nums, 0, res, init);

        vector<vector<int>> ans;
        for (auto item : res) {
            ans.push_back(item);
        }
        return ans;
    }

    void dfs(vector<int>& nums, int i, set<vector<int>>& res, vector<int> l) {
        if (i == nums.size()) {
            if (l.size() >= 2) {
                res.insert(l);
            }
            return;
        }
        // take
        if (l.size() == 0 || (l.size() != 0 && l[l.size()-1] <= nums[i])) {
            vector<int> next = l;
            next.push_back(nums[i]);
            dfs(nums, i+1, res, next);
        }
        dfs(nums, i+1, res, l);
    }
};


int main() {
    Solution s;
    return 0;
}
