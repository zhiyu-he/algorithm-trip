#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long mod = 1e9 + 7;
        int counter = 0;
        int odd = 0;
        int even = 1;   // cur_sum = 0 when start so this is an even subarray
        int cur_sum = 0;
        for (auto item : arr) {
            cur_sum += item;
            if (cur_sum % 2 == 0) {
                counter += odd;
                even += 1;
            } else {
                counter += even;
                odd += 1;
            }
            counter = counter % mod;
        }
        return counter;
    }
};


int main() {
    Solution s;

    return 0;
}
