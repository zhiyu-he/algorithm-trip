#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> seq;
        int sum = 0;
        combine(candidates, res, seq, target, sum, 0);
        return res;
    }

    void combine(vector<int>& candidates, vector<vector<int>>& res, vector<int> seq, int target, int sum, int pos) {
        if (sum == target) {
            res.push_back(seq);
            return;
        }
        if (pos == candidates.size()) {
            return;
        }


        combine(candidates, res, seq, target, sum, pos+1);
        
        int times = 1;

        while (sum + candidates[pos] * times <= target) {
            seq.push_back(candidates[pos]);
            combine(candidates, res, seq, target, sum + candidates[pos] * times, pos+1);
            times += 1;
        }
    }
};


void p(vector<vector<int>>& res) {
    for (auto v : res) {
        for (auto i : v) {
            cout << i;
        }
        cout << endl;
    }
}


int main() {
    Solution s;
    vector<int> test1{2,3,6,7};
    auto res = s.combinationSum(test1, 7);
    p(res);   
    vector<int> test2{2,3,5};
    auto res2 = s.combinationSum(test2, 8);
    p(res2);
    return 0;
}
