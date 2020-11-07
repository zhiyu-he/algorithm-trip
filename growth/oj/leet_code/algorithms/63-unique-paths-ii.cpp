#include<iostream>
#include<vector>


using namespace std;


// TTL, more duplicate subproblem
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int count = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp_table(m, vector<int>(n));
        dfs(obstacleGrid, 0, 0, m - 1, n - 1, count);
        return count;
    }
    void dfs(vector<vector<int>>& obstacleGrid, int x, int y, int m, int n, int& count) {
        if (x == m && y == n) {
            count += 1;
            return;
        }
        // go right
        int next_x = x + 1;
        int next_y = y;

        if (next_x <= m && next_y <= n && obstacleGrid[next_x][next_y] == 0) {
            dfs(obstacleGrid, next_x, next_y, m, n, count);
        }
        // go down
        next_x = x;
        next_y = y + 1;
        if (next_x <= m && next_y <= n && obstacleGrid[next_x][next_y] == 0) {
            dfs(obstacleGrid, next_x, next_y, m, n, count);
        }
        return;
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp_table(m, vector<int>(n));
        return dfs(obstacleGrid, dp_table, 0, 0, m - 1, n - 1);

    }
    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& table, int x, int y, int m, int n) {
        if (x == m && y == n) {
            return 1;
        }
        if (table[x][y] > 0) return table[x][y];

        int right_count = 0, down_count = 0;

        // go right
        int next_x = x + 1;
        int next_y = y;

        if (next_x <= m && next_y <= n && obstacleGrid[next_x][next_y] == 0) {
            right_count = dfs(obstacleGrid, table, next_x, next_y, m, n);
        }
        // go down
        next_x = x;
        next_y = y + 1;

        if (next_x <= m && next_y <= n && obstacleGrid[next_x][next_y] == 0) {
            down_count = dfs(obstacleGrid, table, next_x, next_y, m, n);
        }
        table[x][y] = right_count + down_count;
        return right_count + down_count;
    }
};





int main() {
    Solution s;
    return 0;
}
