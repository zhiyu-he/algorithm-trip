#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        /*
        int satisfied = 0;
        int max_satisfied = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
        }
        max_satisfied = satisfied;
        for (int i = 0; i < X && i < customers.size(); i++) {
            if (grumpy[i] == 1)
                satisfied += customers[i];
        }
        max_satisfied = satisfied;
        for (int i = X; i < customers.size(); i++) {
            if (grumpy[i] == 1)
                satisfied += customers[i];
            if (grumpy[i-X] == 1)
                satisfied -= customers[i-X];
            if (satisfied > max_satisfied)
                max_satisfied = satisfied;
        }
                
        return max_satisfied;
        */

        int max_satisfied = 0;
        int satisfied = 0;
        for (int i = 0; i < X; i++) {
            satisfied += customers[i];
        }
        max_satisfied = satisfied;
        for (int i = X; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
                max_satisfied = satisfied;
            }

            if (grumpy[i] == 1)
                satisfied += customers[i];
            if (grumpy[i-X] == 1)
                satisfied -= customers[i-X];
            if (satisfied > max_satisfied)
                max_satisfied = satisfied;
        }

        return max_satisfied;
    }
};



int main() {
    vector<int> customers{1,0,1,2,1,1,7,5};
    vector<int>    grumpy{0,1,0,1,0,1,0,1};
    int x = 3;

    Solution s;
    auto res = s.maxSatisfied(customers, grumpy, 3);
    cout << res << endl;
    
    
    vector<int> customers2{4,10,10};
    vector<int>    grumpy2{1,1,0};
    x = 2;
    
    auto res2 = s.maxSatisfied(customers2, grumpy2, x);
    cout << res2 << endl;


    return 0;
}
