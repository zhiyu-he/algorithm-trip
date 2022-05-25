#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static const int N = 1e5 + 1;
    int counter = 0;
    int visited[N], low[N], time[N];
    vector<vector<int>> ans, g;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.resize(n);
        for (auto e : connections) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int u, int parent = -1) {
        low[u] = time[u] = counter += 1;
        visited[u] = 1;
        for (auto v : g[u]) {
            if (v == parent) continue;
            if (visited[v] == 0) {
                dfs(v, u);
            }
            low[u] = min(low[u], low[v]);
            if (time[u] < low[v] /*如果要访问v则必须要经过u*/)
                ans.push_back({u, v});
        }
    }
};

int main() {
	Solution s;
	return 0;
}
