#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        vector<vector<int>> mark(grid.size(), vector<int>(grid[0].size()));
        int cnt = 0;
        for (int x = 0; x < grid.size(); x++)
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == '1' && mark[x][y] == 0) {

                    //cout << "x " << x << "  y " << y << endl;
                    cnt += 1;
                    mark[x][y] = 1;
                    dfs(x, y, grid, mark);
                }
            }

        return cnt;
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& mark) {
        //cout << "in x" << x << " y  " << y << endl;
        vector<int>direct_x{-1,1,0,0};
        vector<int>direct_y{0, 0,1, -1};
        for (int i = 0; i < 4; i++) {
            int next_x = x + direct_x[i];
            int next_y = y + direct_y[i];
            if (next_x >= grid.size() || next_x < 0 || next_y >= grid[0].size() ||  next_y < 0)
                //cout << "1-next_x "  << next_x << "  next_y " << next_y << endl;
                continue;
            if (mark[next_x][next_y] != 0 || grid[next_x][next_y] == '0')
                //cout << "2-next_x "  << next_x << "  next_y " << next_y << endl;
                continue;
            mark[next_x][next_y] = 1;
            dfs(next_x, next_y, grid, mark);
        }
    }
};




int main() {
    Solution s;
    return 0;
}
