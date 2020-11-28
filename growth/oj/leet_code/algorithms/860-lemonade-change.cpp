#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() == 0) return true;
        vector<int> count(21);
        count[bills[0]] += 1;
        for (int i = 1; i < bills.size(); i++) {
            if (bills[i] == 5) count[bills[i]] += 1;
            if (bills[i] == 10) {
                if (count[5] == 0) return false;
                count[10] += 1;
                count[5] -= 1;
            }
            if (bills[i] == 20) {
                int refund = 15;
                if (count[10] > 0) {
                    refund -= 10;
                    count[10] -= 1;
                }
                if (refund / 5 > count[5]) return false;
                count[5] -= refund / 5;
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    return 0;
}
