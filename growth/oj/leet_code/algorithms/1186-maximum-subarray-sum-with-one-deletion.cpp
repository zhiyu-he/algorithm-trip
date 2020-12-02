#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size()==1) return arr[0];
        vector<vector<int>> dp(arr.size()+1, vector<int>(2));
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0) {
                dp[i][0] = arr[i];
                dp[i][1] = arr[i];
            } else {
                dp[i][0] = max(arr[i], arr[i] + dp[i-1][0]);
                dp[i][1] = max(dp[i-1][0], arr[i] + dp[i-1][1]);
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
            res = max(res, max(dp[i][0], dp[i][1]));
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
