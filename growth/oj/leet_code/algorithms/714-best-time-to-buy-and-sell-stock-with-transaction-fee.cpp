#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0, buy = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            sell = max(sell, buy + prices[i]);
            buy = max(buy, sell - prices[i] - fee);
        }
        return sell;
    }
};

int main() {
    Solution s;
    return 0;
}
