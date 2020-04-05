#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
        int total_profit = 0;
        int i = 0;
        while (i < prices.size() -1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i+1])
                i++;
            int v_l = prices[i];

            while ( i < prices.size() - 1 && prices[i] <= prices[i+1])
                i++;
            int v_h = prices[i];

            total_profit += v_h - v_l;
            
        }
        return total_profit;
    }
};


int main() {
    Solution s;
    vector<int> v1{7,1,5,3,6,4}; // -> 7
    cout << s.maxProfit(v1) << endl;

    vector<int> v2{1,2,3,4,5};  // -> 4
    cout << s.maxProfit(v2) << endl;

    vector<int> v3{1,2,3,2,1};  // -> 2
    cout << s.maxProfit(v3) << endl;

    vector<int> v4{1,2,3,2,1,4,5,6,1}; // -> 2 + 5
    cout << s.maxProfit(v4) << endl;


    return 0;
}
