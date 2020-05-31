#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> visits(N + 1);
        vector<vector<int>> dislike_nn(N + 1, vector<int>(N + 1));
        for (auto dislike : dislikes) {
            dislike_nn[dislike[0]][dislike[1]] = 1;
            dislike_nn[dislike[1]][dislike[0]] = 1;
        }

        for (int i = 1; i <= N; ++i) {
            if (visits[i] == 0 && !dfs(dislike_nn, i, 1, visits)) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>& dislike_nn, int cur, int visit, vector<int>& visits) {
        visits[cur] = visit;
        for (int i = 0; i < visits.size(); ++i) {
            if (dislike_nn[cur][i] == 1) {
                if (visits[i] == visit) return false;
                if (visits[i] == 0 && !dfs(dislike_nn, i, -visit, visits)) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}
