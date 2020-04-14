#include<iostream>
#include<vector>

using namespace std;

/*
 * ref: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3299/
 */


class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sLength = s.length();
        int leftCnt, rightCnt;
        leftCnt = rightCnt = 0;
        for (auto op : shift) {
            if (op[0] == 0) {
                leftCnt += op[1];
            } else {
                rightCnt += op[1];
            }
        }
        leftCnt %= sLength;
        rightCnt %= sLength;
        if (leftCnt == rightCnt) {
            return s;
        } else {
            if (leftCnt > rightCnt) {
                int moveStep = leftCnt - rightCnt;
                string newS = s.substr(moveStep, sLength) + s.substr(0, moveStep);
                return newS;
            } else {
                int moveStep = rightCnt - leftCnt;
                string temp = s.substr(sLength-moveStep, sLength);
                reverse(temp.begin(), temp.end());
                string newS = temp + s.substr(0, sLength-moveStep);
                return newS;
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> v;
    s.stringShift("abcdefg", v);
    return 0;
}
