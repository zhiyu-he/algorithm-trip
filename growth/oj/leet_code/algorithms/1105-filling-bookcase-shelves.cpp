#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        if (books.size() == 0) return 0;
        vector<int> dp(books.size()+1);
        dp[1] = books[0][1];
        for (int i = 1; i <= books.size(); i++) {
            // base case
            dp[i] = dp[i-1] + books[i-1][1];
            int total_width = books[i-1][0];
            int cur_max_height = books[i-1][1];
            for (int j = i - 1; j >= 1; j--) {
                total_width += books[j-1][0];
                if (total_width <= shelf_width) {
                    cur_max_height = max(books[j-1][1], cur_max_height);
                    dp[i] = min(dp[i], dp[j-1] + cur_max_height);
                } else {
                    break;
                }
            }
            //cout << "dp[" << i << "]" <<  " " << dp[i] << endl;
        }
        return dp[books.size()];
    }
};

int main() {
    Solution s;
    return 0;
}
