#include<iostream>
#include<vector>
#include<unordered_set>


using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        slove(nums, res, ans, 0);
        return res;
    }
    void slove(vector<int>&nums, vector<vector<int>>& res, vector<int>& ans, int idx) {
        if (idx == nums.size()) {
            res.push_back(ans);
            return;
        }
        unordered_set<int> s;
        for (int i = idx; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            ans.push_back(nums[i]);
            int tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
            slove(nums, res, ans, idx+1);
            ans.pop_back();
            tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;

        }
    }
};

int main() {
    Solution s;
    return 0;
}
