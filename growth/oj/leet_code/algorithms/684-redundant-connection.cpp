#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> begin(edges.size()+1);
        // initial
        for (int i = 1; i < begin.size(); i++)
            begin[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];

            int parent1 = find(begin, edge[0]);
            int parent2 = find(begin, edge[1]);
            // delete edge
            if (parent1 == parent2) {
                return edge;
            }
            begin[max(parent1, parent2)] = min(parent1, parent2);
        }
        return ans;
    }

    int find(vector<int>& u, int child) {
        int parent = child;
        while(parent != u[parent]) {
            parent = u[parent];
        }
        return parent;
    }
};

int main() {
    Solution s;
    return 0;
}
