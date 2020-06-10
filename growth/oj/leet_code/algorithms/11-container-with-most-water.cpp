#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;

        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while (i < j) {
            int cur_area = 0;
            if (height[i] <= height[j]) {
                cur_area = height[i] * (j - i);
                i++;
            } else if (height[i] > height[j]) {
                cur_area = height[j] * (j - i);
                j--;
            }
            if (cur_area > max_area)
                max_area = cur_area;
        }
        return max_area;
    }
};

int main() {
    Solution s;

    return 0;
}
