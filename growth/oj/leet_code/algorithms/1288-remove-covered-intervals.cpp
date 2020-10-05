#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int remain = intervals.size();
        int last_interval = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= intervals[last_interval][1]) {
                remain -= 1;
            } else {
                last_interval = i;
            }
        }
        return remain;
    }
};

int main() {
	Solution s;
    return 0;
}
