#include<iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        
        string table = "0123456789abcdef";
        string res = "";
        unsigned int input = num;
        do {
            res = table[input%16] + res;
            input = input >> 4;
        }while(input);
        return res;
    }
};


int main() {
	return 0;
}
