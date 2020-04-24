#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.length() == 0) return false;


        bool find = false;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0] && !find) {
                    vector<vector<int>> set(board.size(), vector<int>(board[0].size()));
                    set[row][col] = 1;
                    string search = "";
                    search += board[row][col];
                    find = dfs(board, row, col, 0, search, word, set);
                }
            }
        }
        return find;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, int idx, string cur_str, string& word, vector<vector<int>>& set) {
        if (idx == word.length()-1) return cur_str == word;
        if (idx == word.length()) return false;
        //cout << "idx " << idx << " cur_str " << cur_str << endl;
        vector<int> d_x{-1, 1, 0, 0};
        vector<int> d_y{0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int next_x = row +  d_x[i];
            int next_y = col + d_y[i];
            if (next_x < 0 || next_x >= board.size()) continue;
            if (next_y < 0 || next_y >= board[0].size()) continue;
            if (board[next_x][next_y] != word[idx+1]) continue;
            if (set[next_x][next_y] == 1) continue;
            set[next_x][next_y] = 1;
            auto find = dfs(board, next_x, next_y, idx+1, cur_str+board[next_x][next_y], word, set);
            if (find) return true;
            set[next_x][next_y] = 0;
        }
        return false;
    }
};


int main() {
    return 0;
}
