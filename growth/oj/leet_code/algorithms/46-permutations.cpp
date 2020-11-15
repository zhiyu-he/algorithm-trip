#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> ans;
        permutation(nums, 0, ans, res);
        return res;
    }
    void permutation(vector<int>& data, int cur_idx, vector<int>& ans, vector<vector<int>>& res) {
        if (data.size() == cur_idx) {
            res.push_back(ans);
            return;
        }
        for (int i = cur_idx; i < data.size(); i++) {
            ans.push_back(data[i]);
            int tmp = data[i];
            data[i] = data[cur_idx];
            data[cur_idx] = tmp;
            permutation(data, cur_idx+1, ans, res);
            ans.pop_back();
            tmp = data[i];
            data[i] = data[cur_idx];
            data[cur_idx] = tmp;
        }
    }
};


int main() {
    return 0;
}

