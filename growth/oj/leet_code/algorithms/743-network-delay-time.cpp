#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int g[101][101] = {-1};
    int dist[101];
    bool visited[101] = {false};
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(dist, 0x3f, sizeof dist);
        for (auto edge: times) {
            g[edge[0]][edge[1]] = edge[2];
        }
        dist[k] = 0;
        /*
            dist[i] means: the min distance from k to i
            if dist[i] can be update that means dist[i] = dist[e.from] + e[from][i]
        */
        while(true) {
            bool update = false;
            for (auto edge : times) {
                int from = edge[0], to = edge[1], cost = edge[2];
                if (dist[from] != 0x3f3f3f3f && dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                    update = true;
                }
            }
            if (!update) break;
        }
        int max_cost = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 0x3f3f3f3f) return -1;
            //cout << "k " << k << " to " << i << " cost " << dist[i] << endl;
            max_cost = max(max_cost, dist[i]);
        }
        return max_cost;
    }
};

int main() {
	Solution s;
	return 0;
}
