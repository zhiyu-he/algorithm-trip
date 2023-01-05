#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int minimum_cnt = points.size();
        int overlap_start = 0;
        for(int i = 1; i < points.size(); i++) {
            if(points[overlap_start][1] >= points[i][0] && points[overlap_start][1] <= points[i][1]) {
                minimum_cnt -= 1;
            } else if (points[i][0] >= points[overlap_start][0] && points[i][1] <= points[overlap_start][1]) {
                minimum_cnt -= 1;
                overlap_start = i;
            } else {
                overlap_start = i;
            }
        }
        return minimum_cnt;
    }
};

class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int nums = 1;
        int left = points[0][0], right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (right < points[i][0]) {
                left = points[i][0];
                right = points[i][1];
                nums += 1;
            } else {
                int l = points[i][0], r = points[i][1];
                if (left < l && r < right) {
                    left = l;
                    right = r;
                } else if (left < l) {
                    left = l;
                } else if (r < right) {
                    right = r;
                } else {
                    
                }
            }
        }
        return nums;
    }
};


int main() {
    return 0;
}
