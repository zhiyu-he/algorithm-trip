#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> weights;
    default_random_engine generator;
    uniform_int_distribution<int> distrib;

    Solution(vector<int>& w) {
        int sum = 0;
        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            weights.push_back(sum);
        }
        distrib = uniform_int_distribution<int>(1, weights[weights.size()-1]);
    }

    int pickIndex() {

        int num = distrib(generator);
        int return_idx = -1;
        int left = 0;
        int right = weights.size();

        int res = weights.size() == 1 ? 0 : -1;
        while (left < right) {
            int mid = (right-left) / 2 + left;
            if (num <= weights[mid]) {
                right = right-1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
