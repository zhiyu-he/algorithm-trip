#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int input = n;
        unordered_set<int> setOfInt;
        bool res = false;
        while(1) {
            setOfInt.insert(input);
            int newInt = 0;
            while(input) {
                int eachI = input % 10;
                newInt +=  eachI * eachI;
                input /= 10;
            }
            input = newInt;
            if (newInt == 1) {
                res = true;
                break;
            }
            if (setOfInt.find(newInt) != setOfInt.end()) {
                res = false;
                break;
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    cout << s.isHappy(1) << endl;
    cout << s.isHappy(20) << endl;
    return 0;
}
