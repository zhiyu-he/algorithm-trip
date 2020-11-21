#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> cache(5+1, vector<int>(n+1));
        return slove(n, 0, 0, cache);
    }
    int slove(int n, int size, int k, vector<vector<int>>& cache) {
        if (size == n) {
            return 1;
        }
        if (cache[k][size] != 0) return cache[k][size];

        int cnt = 0;
        int num = k == 0 ? 1 : k;
        for (; size < n && num <= 5; num++) {
            cnt += slove(n, size+1, num, cache);
        }
        cache[k][size] = cnt;
        return cnt;
    }
};

// no cache
class Solution2 {
public:
    int countVowelStrings(int n) {
        return slove(n, 0, 0);
    }
    int slove(int n, int size, int k) {
        if (size == n) {
            return 1;
        }
        int cnt = 0;
        int num = k == 0 ? 1 : k;
        for (; size < n && num <= 5; num++) {
            cnt += slove(n, size+1, num);
        }
        return cnt;
    }
};

int main() {
    Solution s;
    return 0;
}
