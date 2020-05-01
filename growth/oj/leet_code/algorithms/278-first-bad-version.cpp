#include<iostream>

using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, ans = -1;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (isBadVersion(mid)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
