#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size());
        for (int i = 0; i < ratings.size(); i++) candy[i] = 1;

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i-1] < ratings[i]) {
                candy[i] = candy[i-1]+1;
            }
        }
        for (int j = ratings.size()-2; j >= 0;j--) {
            if (ratings[j+1] < ratings[j] && candy[j] <= candy[j+1]) {
                candy[j] = candy[j+1]+1;
            }
        }
        int items = 0;
        for (int i = 0; i < candy.size(); i++) items += candy[i];
        return items;
    }
};

int main() {
    Solution s;
    return 0;
}
