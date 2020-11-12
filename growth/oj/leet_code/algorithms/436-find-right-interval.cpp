#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, vector<int>> p1, pair<int, vector<int>> p2) {
        return p1.second[0] == p2.second[0] ? p1.second[1] < p2.second[1] : p1.second[0] < p2.second[0];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, vector<int>>> intervals_with_idx;
        for (int i = 0; i < intervals.size(); i++) {
            intervals_with_idx.push_back(make_pair(i, intervals[i]));
        }
        vector<int> res;
        sort(intervals_with_idx.begin(), intervals_with_idx.end(), cmp);

        for (int i = 0; i < intervals.size(); i++) {
            res.push_back(bs(intervals_with_idx, intervals[i]));
        }
        return res;
    }
    int bs(vector<pair<int, vector<int>>>& intervals, vector<int>& target) {
        int i = 0; int j = intervals.size()-1;
        int res = -1;
        while(i <= j) {
            int mid = (j-i) / 2 + i;
            if (intervals[mid].second[0] >= target[1]) {
                res = intervals[mid].first;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
