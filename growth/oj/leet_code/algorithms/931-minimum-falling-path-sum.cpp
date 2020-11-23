#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // original problem. pick item from first row
        // sub problem is row-1, column -1 column 1 column +1
        int res = INT_MAX;
        vector<vector<int>> cache(A.size()+1, vector<int>(A[0].size()));
        for (int col = 0; col < A[0].size(); col++) {
            res = min(res, slove(A, 0, col, cache));
        }
        return res;
    }
    int slove(vector<vector<int>>& A, int row, int column, vector<vector<int>>& cache) {
        if (row >= A.size()) return INT_MAX;
        if (column < 0 || column == A[0].size()) return INT_MAX;
        if (cache[row][column] != 0) return cache[row][column];
        int cur_number = A[row][column];
        int subAns = min(min(slove(A, row+1, column-1, cache), slove(A, row+1, column, cache)), slove(A, row+1, column+1, cache));
        cur_number += subAns == INT_MAX ? 0 : subAns;
        cache[row][column] = cur_number;
        return cur_number;

    }
};

int main() {
    return 0;
}
