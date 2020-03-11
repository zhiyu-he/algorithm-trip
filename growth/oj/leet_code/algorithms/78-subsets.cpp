#include<iostream>
#include<set>
#include<vector>

using namespace std;

/*
 *
 * AC: 
 *  https://leetcode.com/problems/subsets-ii/
 *  https://leetcode.com/problems/subsets/
 */


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;

        vector<vector<int>> res;
        res.push_back(cur);
        
        int sameLen = 1;
        int lastPush = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i-1] != nums[i]) {
                sameLen = 1;
            } else {
                sameLen += 1;
            }
            int n = res.size();
            int j = 0;
            if (sameLen > 1) {
                j = n - lastPush;
            }
            lastPush = 0;
            for (; j < n; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
                lastPush += 1;
            }
        }
        return res;
    }


    // 考虑input被处理到哪里了
    void dfs2(vector<vector<int>>& res, vector<int> cur, vector<int>& input, int curIdx) {
        if (curIdx == input.size()) {
            res.push_back(cur);
            return;
        }
        // pick or no-pick
        dfs2(res, cur, input, curIdx+1);
        if (cur.size() == 0 && curIdx > 0 && input[curIdx-1] == input[curIdx]) {
            cout << "cur_idx: " << curIdx << endl;
            return;
        }

        cur.push_back(input[curIdx]);
        dfs2(res, cur, input, curIdx+1);
    }


    // 这种dfs考虑的是已处理的元素个数
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& input, set<int>& indexSet, int cur_start) {
        if (cur.size() < input.size()) {
            res.push_back(cur);
        }
        if (cur.size() == input.size()) {
            return;
        }
        for(int i = cur_start; i < input.size(); i++) {
            if(indexSet.find(i) == indexSet.end()) {
                cur.push_back(input[i]);
                indexSet.insert(i);
                dfs(res, cur, input, indexSet, i + 1);
                cur.pop_back();
                auto it = indexSet.find(i);
                indexSet.erase(it);
            }
        }
    }
};


int main() {
    Solution s;
    vector<int>  vec{1,2,2};
    
    auto a = s.subsets(vec);
    for (auto v : a) {
        cout << "start: " << endl;
        for ( auto i : v) {
            cout << i << " ";
        }
        cout << "\nend: " << endl;
    }
}
