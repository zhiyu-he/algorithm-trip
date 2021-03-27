#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// O(N^2 + N)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> res;
        for (int i = 0; i < B.size(); i++) {
            int t = B[i];
            bool found = false;
            for (int j = 0; j < A.size(); j++) {
                if (A[j] > t) {
                    found = true;
                    res.push_back(A[j]);
                    A[j] = -1;
                    break;
                }
            }
            if (!found) {
                for (int j = 0; j < A.size(); j++) {
                    if (A[j] >= 0) {
                        res.push_back(A[j]);
                        A[j] = -1;
                        break;
                    }
                }
            }
        }
        return res;
    }
};



int main() {
	Solution s;
    return 0;
}
