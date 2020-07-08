#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {

                if (grid[i][j] == 1) {

                    // left
                    if (j == 0 || (j > 0 && grid[i][j-1] == 0)) total += 1;
                    // up
                    if (i == 0 || (i > 0 && grid[i-1][j] == 0)) total += 1;
                    // right
                    if (j == grid[0].size() - 1 || grid[i][j+1] == 0) total += 1;
                    // down
                    if (i == grid.size()-1 || grid[i+1][j] == 0) total += 1;
                }
            }
        }
        return total;
    }
};

int main() {
    Solution s;
    return 0;
}
