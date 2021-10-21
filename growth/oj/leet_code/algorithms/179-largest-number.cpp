#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1+s2 > s2+ s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for (int i = 0; i < nums.size(); i++)
            res += to_string(nums[i]);
        if (nums[0] == 0) return "0";
        return res;
    }
};


int main() {
    return 0;
}
