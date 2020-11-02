#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 0; i < intervals.size()-1; i++) {
            if (right >= intervals[i+1][0]) {
                right = max(right, intervals[i+1][1]);
                continue;
            }
            res.push_back(vector<int>{left, right});
            left = intervals[i+1][0];
            right = intervals[i+1][1];
        }
        res.push_back(vector<int>{left, right});
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
