#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int next_a = 0;
        int next_b = 0;
        vector<vector<int>> res;
        while(next_a < A.size() && next_b < B.size()) {
            vector<int>& pair_a = A[next_a];
            vector<int>& pair_b = B[next_b];

            if (pair_a[1] < pair_b[0]) {
                next_a++;
                continue;
            }

            if (pair_a[0] > pair_b[1]) {
                next_b++;
                continue;
            }

            int left_a = pair_a[0];
            int left_b = pair_b[0];
            int right_a = pair_a[1];
            int right_b = pair_b[1];
            // left_b, left_a, right_a, right_b
            if (left_b <= left_a && right_a <= right_b) {
                res.push_back(vector<int>{left_a, right_a});
                pair_b[0]=right_a;
                next_a += 1;
                continue;
            }
            // left_a, left_b, right_a, right_b
            if (left_a <= left_b && right_a <= right_b) {
                res.push_back(vector<int>{left_b, right_a});
                pair_b[0] = right_a;
                next_a += 1;
                continue;
            }
            // left_a, left_b, right_b, right_a
            if (left_a <= left_b && right_b <= right_a) {
                res.push_back(vector<int>{left_b, right_b});
                pair_a[0] = right_b;
                next_b += 1;
                continue;
            }
            // left_b, left_a, right_b, right_a
            if (left_b <= left_a && right_b <= right_a) {
                res.push_back(vector<int>{left_a, right_b});
                pair_a[0] = right_b;
                next_b += 1;
            }

        }
        return res;
    }
};

int main() {
    return 0;
}
