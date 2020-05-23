#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int raw_color = image[sr][sc];
        if (raw_color != newColor) {
            dfs(image, raw_color, newColor, sr, sc);
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int raw_color, int new_color, int r, int c) {
        if (image[r][c] == raw_color) {
            image[r][c] = new_color;
            if (r >= 1) dfs(image, raw_color, new_color, r-1, c);
            if (c >= 1) dfs(image, raw_color, new_color, r, c-1);
            if (r+1 < image.size()) dfs(image, raw_color, new_color, r+1, c);
            if (c+1 < image[0].size()) dfs(image, raw_color, new_color, r, c+1);
        }
    }
};

int main() {
    return 0;
}
