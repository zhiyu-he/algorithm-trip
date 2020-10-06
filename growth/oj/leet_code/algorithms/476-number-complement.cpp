#include<iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int bit_pos = 0;
        int raw = num;
        unsigned int judge = 1 << bit_pos;
        while(judge <= raw) {
            num = num^(1 << bit_pos);
            bit_pos += 1;
            judge = 1 << bit_pos;
        }
        return num;
    }
    int findComplement2(int num) {
        if (num == 0) return 1;
        unsigned int output = 0;
        int bit_idx = 0;
        while(num) {
            output |= (((num & 1) == 1 ? 0 : 1) << bit_idx);
            num >>= 1;
            bit_idx += 1;
        }
        return output;
    }
};

int main() {
    Solution s;
    return 0;
}
