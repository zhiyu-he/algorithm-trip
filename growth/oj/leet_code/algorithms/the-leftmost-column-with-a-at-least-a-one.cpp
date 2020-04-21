#include<iostream>
#include<vector>

using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int row = d[0];
        int col = d[1]-1;
        int returnIdx = -1;

        for (int i = 0; i < row; i++) {
            int tmpIdx = -1;
            int left = 0, right=col;
            while(left <= right) {
                int mid = (right-left) / 2 + left;
                int mid_val = binaryMatrix.get(i, mid);
                if (mid_val == 1) {
                    tmpIdx = mid;
                    right = mid - 1;
                } else if (mid_val == 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            //cout << "tmp " << tmpIdx << " row " << i << endl;
            if (returnIdx == -1 || (tmpIdx != -1 && tmpIdx < returnIdx))
                returnIdx = tmpIdx;
        }
        return returnIdx;
    }

    int bs(BinaryMatrix &binaryMatrix, int row, int right) {
        //cout << "row " << row << "right " << right << endl;
        int left = 0;
        int returnIdx = -1;


        return returnIdx;
    }
};


int main() {
    return 0;
}
