#include<iostream>

using namespace std;

class Solution {
public:
    long countPairs(vector<int>& nums1, vector<int>& nums2) {
        // a_i + a_j > b_i + b_j
        // a_i - b_i > b_j - a_j
        // a_i - b_i > -(a_j - b_j)
        // a1 - b1 > -(a2 - b2)
        // d1 > -(d2)

        // a_i - b_i + a_j - b_j > 0
        // d1 + d2 > 0

        // i < j
        vector<int> diff(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
            diff[i] = nums1[i] - nums2[i];

        sort(diff.begin(), diff.end());

        int i = 0;
        int j = diff.size()-1;
        long long res = 0;
        while(i < j) {
            if (diff[i] + diff[j] > 0) {
                res += (j-i); // 升序排序, diff[i+1] > diff[i] 所以区间内均成立
                j--;
            } else {
                i++;
            }
        }
        return res;
        /*
        // TTL
        int res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int j = i + 1;
            while(j < nums2.size()) {
                if (nums1[i] + nums1[j] > nums2[i] + nums2[j]) {
                    res += 1;
                }
                j++;
            }
        }
        */

        return res;
    }
};


int main() {
    return 0;
}
