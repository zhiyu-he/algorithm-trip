#include<iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int bit_pos = 0;

        while((1<<bit_pos) <= N) {
            N = N^(1 << bit_pos);
            bit_pos += 1;
        }
        return N;
    }
};

int main() {
    return 0;
}
