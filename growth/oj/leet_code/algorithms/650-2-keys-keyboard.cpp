#include<iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        return steps(1, 0, n-1);
    }

    int steps(int len, int copy, int left) {
        if (left == 0) return 0;
        if (copy == left) return 1;
        if (left < 0) return INT_MAX;
        if (copy!= 0 && left % copy != 0) return INT_MAX;
        //cout << "len " << len << " copy " << copy << " left " << left << endl;

        int res = INT_MAX;
        if (copy == 0) {
            res = 1 + steps(len, len, left);
        } else {
            int case1 = INT_MAX, case2 = INT_MAX;
            case1 = steps(len+copy, copy, left-copy);
            if (len != copy)
                case2 = steps(len, len, left);
            res = min(min(case1, case2)+1, res);
        }


        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
