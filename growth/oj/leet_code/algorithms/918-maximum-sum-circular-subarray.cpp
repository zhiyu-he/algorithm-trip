#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.size() == 1) return A[0];

        int cur_max = A[0];
        int ans1  = A[0];
        int cur_min = A[0];
        int min = A[0];

        int total_sum = A[0];
        for (int i = 1; i < A.size(); i++) {
            total_sum += A[i];

            cur_max = cur_max + A[i] > A[i] ? cur_max + A[i]: A[i];
            if (cur_max > ans1) ans1 = cur_max;
            //cout << "in ans1 " << ans1 << endl;
            cur_min = cur_min + A[i] < A[i] ? cur_min + A[i]: A[i];
            if (cur_min < min) min = cur_min;
        }

        int ans2 = total_sum - min;
        //cout << "ans1 " <<  ans1 << " ans2 " << ans2 << endl;



        return ans2 == 0 ? ans1 : max(ans1, ans2);
    }
};

int main() {
    return 0;
}
