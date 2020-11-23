#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0;
        vector<int> cache(pairs.size()+1);
        for (int i = 0; i < pairs.size(); i++)
            res = max(res, slove(pairs, pairs[i], i, cache));
        return res;
    }

    int slove(vector<vector<int>>& pairs, vector<int>& cur_pair, int idx, vector<int>& cache) {
        if (cache[idx] != 0) return cache[idx];
        int res = 1;
        int next_max = 0;
        for (int i = 0; i < pairs.size(); i++) {
            if (cur_pair[1] < pairs[i][0]) {
                next_max = max(next_max, slove(pairs, pairs[i], i, cache));
            }
        }
        cache[idx] = res + next_max;
        return res + next_max;
    }

};

int main() {
    Solution s;
    return 0;
}
