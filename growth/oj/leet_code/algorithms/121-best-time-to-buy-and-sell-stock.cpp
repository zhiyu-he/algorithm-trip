#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
        int max_profit = 0;
        int cur_min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int cur_profit = prices[i] - cur_min;
            if (cur_profit > max_profit)
                max_profit = cur_profit;
            if (prices[i] < cur_min)
                cur_min = prices[i];
        }
        return max_profit;
    }
};


int main() {
    Solution s;
    vector<int> v{7,1,5,3,6,4};
    cout << s.maxProfit(v) << endl;

    vector<int> v1{7,6,4,3,1};
    cout << s.maxProfit(v1) << endl;
    return 0;
}
