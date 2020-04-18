#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;

        int c_n = m + n - 2;
        int c_m = n - 1;
        return combine(c_n, c_m);
    }

    int combine(int n, int m) {
        int numerator = 1;
        int denominator = 1;

        int loop_times = m;
        while (loop_times) {
            numerator *= n;
            denominator *= m;
            if (numerator % denominator == 0) {
                numerator /= denominator;
                denominator = 1;
            }
            loop_times--;
            n--;
            m--;
        }
        while (m) {
            numerator /= m;
            m--;
        }
        return numerator;
    }
};


int main() {
    Solution s;
    cout << s.uniquePaths(3, 2) << endl;
    cout << s.uniquePaths(7, 3) << endl;
    cout << s.uniquePaths(100, 100) << endl;
    return 0;
}
