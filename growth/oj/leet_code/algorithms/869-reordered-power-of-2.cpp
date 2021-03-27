#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n <= 10) {
            if (n == 1 || n == 2 || n == 4 || n == 8) return true;
            return false;
        }
        vector<vector<int>> t = vector<vector<int>>(28, vector<int>(10));
        for (int i = 4; i <= 31; i++) {
            unsigned int num = 1 << i;
            while(num) {
                t[i-4][num%10] += 1;
                num /= 10;
            }
        }

        vector<int> c = vector<int>(10);
        while(n) {
            c[n%10] += 1;
            n /= 10;
        }

        for (int i = 0; i < t.size(); i++) {
            bool ok = true;
            for (int j = 0; j < 10; j++) {
                if (t[i][j] != c[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};


int main() {
    Solution s;
    return 0;
}
