#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> step{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.size() == 0) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n));
        vector<vector<int>> flag = vector<vector<int>>(m, vector<int>(n));
        for (int x = 0; x  < m; x++)
            for (int y = 0; y < n; y++) {
                dfs(m, n, x, y, matrix, flag, res, visited);
            }
        
        return res;
    }
    void dfs(int m, int n, int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& flag, vector<vector<int>>& res, vector<vector<int>>& visited) {
        bool pacific_ok = pacific(m, n, x, y, matrix, flag,visited);
        bool atlantic_ok = atlantic(m, n, x, y, matrix, flag,visited);

        if (pacific_ok) flag[x][y] += 1;
        if (atlantic_ok) flag[x][y] += 2;
        if (pacific_ok && atlantic_ok) {
            res.push_back(vector<int>{x, y});
        }
    }
    bool pacific(int m, int n, int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& flag, vector<vector<int>>& visited) {
        if (flag[x][y] > 0) return (flag[x][y] == 1 || flag[x][y] == 3);
        if (x == 0 || y == 0) return true;
        int cur_val = matrix[x][y];
        
        for (int d = 0; d < 4; d++) {
            int next_x = x + step[d][0];
            int next_y = y + step[d][1];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && matrix[next_x][next_y] <= cur_val && visited[next_x][next_y] == 0) {
                visited[next_x][next_y] = 1;
                bool ok = pacific(m, n, next_x, next_y, matrix, flag,visited);
                visited[next_x][next_y] = 0;
                if (ok) return ok;
            }
        }
        return false;
    }
    bool atlantic(int m, int n, int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& flag, vector<vector<int>>& visited) {
        //cout << "x " << x << " y " << y << endl;
        if (flag[x][y] > 0) return (flag[x][y] == 2 || flag[x][y] == 3);
        if (x == m-1 || y == n-1) return true;
        int cur_val = matrix[x][y];
         for (int d = 0; d < 4; d++) {
            int next_x = x + step[d][0];
            int next_y = y + step[d][1];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && matrix[next_x][next_y] <= cur_val&& visited[next_x][next_y] == 0) {
                visited[next_x][next_y] = 1;
                bool ok = atlantic(m, n, next_x, next_y, matrix, flag,visited);
                visited[next_x][next_y] = 0;
                if (ok) return ok;
            }
        }
        return false;
    }
};


int main() {
	Solution s;
    return 0;
}
