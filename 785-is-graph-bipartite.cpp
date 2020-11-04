#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size());
        for (int v = 0; v < graph.size(); v++) {
            if (color[v] == 0) {
                if (!dfs(graph, color, v, 1)) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int v, int c) {
        color[v] = c;
        for (int i = 0; i < graph[v].size(); i++) {
            if (color[graph[v][i]] == c) return false;
            if (color[graph[v][i]] == 0 && !dfs(graph, color, graph[v][i], -c)) return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    return 0;
}
