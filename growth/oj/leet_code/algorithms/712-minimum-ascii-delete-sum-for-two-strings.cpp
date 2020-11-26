#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> cache(s1.length()+1, vector<int>(s2.length()+1));
        return minSum(s1, 0, s2, 0, cache);
    }
    int minSum(string& s1, int i, string& s2, int j, vector<vector<int>>& cache) {
        if (cache[i][j] != 0) return cache[i][j];
        int sum = 0;
        if (i == s1.length()) {
            for (int p = j; p < s2.length(); p++)
                sum += int(s2[p]);
            cache[i][j] = sum;
            return sum;
        }
        if (j == s2.length()) {
            for (int p = i; p < s1.length(); p++)
                sum += int(s1[p]);
            cache[i][j] = sum;
            return sum;
        }
        if (s1[i] == s2[j]) {
            sum = minSum(s1, i+1, s2, j+1, cache);
            cache[i][j] = sum;
            return sum;
        }


        int case1 = s1[i] + minSum(s1, i+1, s2, j, cache);
        int case2 = s2[j] + minSum(s1, i, s2, j+1, cache);
        cache[i][j] = min(case1, case2);
        return min(case1, case2);
    }
};

int main() {
    Solution s;
    return 0;
}
