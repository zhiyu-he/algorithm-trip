#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // m means zero, n means one
        vector<vector<int>> pair_list(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            int one_cnt = 0, zero_cnt = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == '0') 
                    zero_cnt += 1;
                else
                    one_cnt += 1;
            }
            pair_list[i] = {zero_cnt, one_cnt};
        }
        vector<vector<vector<int>>> cache(600+1, vector<vector<int>>(m+1, vector<int>(n+1)));
        return slove(pair_list, 0, m, n, cache);
    }
    
    int slove(vector<vector<int>>& input, int start_idx, int m, int n, vector<vector<vector<int>>>& cache) {
        if (m < 0 || n < 0) return -1;
        if (m == 0 && n == 0) return 0;
        if (start_idx == input.size()) return 0;
        if (cache[start_idx][m][n] != 0) return cache[start_idx][m][n];
        int case1 = 0, case2 = 0;
        case1 = slove(input, start_idx+1, m - input[start_idx][0], n - input[start_idx][1], cache);
        case2 = slove(input, start_idx+1, m, n, cache);
        cache[start_idx][m][n] =  max(case1 == -1 ? 0 : case1+1, case2 == -1 ? 0 : case2);
        return cache[start_idx][m][n];
    }
};

int main() {
    Solution s;
    return 0;
}
