#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
    
public:
    static const int N = 101;
    bool visit[N][N];
    int direction[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        visit[0][0] = true;
        int layer = 0;
        while(!q.empty()) {
            layer += 1;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x_y = q.front();
                q.pop();
                int x = x_y.first;
                int y = x_y.second;
                
                if (x == n-1 && y == n -1) {
                    return layer;
                }
                for (int k = 0; k < 8; k++) {
                    int next_x = x + direction[k][0];
                    int next_y = y + direction[k][1];
                    if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visit[next_x][next_y] == false && grid[next_x][next_y] == 0) {
                        visit[next_x][next_y] = true;
                        q.push(make_pair(next_x, next_y));
                    }
                }
            }
            
        }
        return -1;
    }
};

int main() {
	Solution s;
	return 0;
}
