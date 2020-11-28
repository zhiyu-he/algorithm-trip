#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() <= 2) return 0;
        int res = 0;
        slove(A, 0, res);
        return res;
    }
    int slove(vector<int>& A, int start_i, int& res) {
        if (start_i + 2 == A.size()) return 0;
        if (A[start_i] - A[start_i+1] == A[start_i+1] - A[start_i+2]) {
            int ans = 1 + slove(A, start_i+1, res);
            res += ans;
            return ans;
        } else {
            slove(A, start_i+1, res);
            return 0;
        }
    }
};
int main() {
    Solution s;
    return 0;
}
