#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        cout << matrix.size() << endl;
        if (matrix.size() == 0) return false;
        if (matrix.size() == 1 && matrix[0].size() == 0) return false;
        int idx = bs(matrix[0], target);
        //cout << "col " << idx << endl;
        if (idx >= 0 && matrix[0][idx] == target) return true;
        for (int i = 0; i < matrix.size(); i++) {
            int col = idx;
            for (int j = 0; j <= col; j++) {
                if (matrix[i][j] == target) return true;
            }
        }
        return false;
    }

    int bs(vector<int>& row, int target) {
        int idx = row.size()-1;
        int i = 0, j = row.size() - 1;
        while(i <= j) {
            int mid = (j - i) / 2 + i;
            if (row[mid] >= target) {
                idx = mid;
                j = mid - 1;
            } else if (row[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return idx;
    }
};

int main() {
    Solution s;
    return 0;
}
