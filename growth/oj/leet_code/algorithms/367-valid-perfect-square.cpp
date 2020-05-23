#include<iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;

        int left = 1, right = num / 2;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            float half = float(num) / mid;
            if (half == mid) return true;
            if (half < mid)
                right = mid-1;
            else
                left = mid + 1;
        }
        return false;
    }
};

int main() {
    return 0;
}
