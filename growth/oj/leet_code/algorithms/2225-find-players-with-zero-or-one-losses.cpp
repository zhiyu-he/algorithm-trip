#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winMap, lossMap;
        for (int i = 0; i < matches.size(); i++) {
            winMap[matches[i][0]] += 1;
            lossMap[matches[i][1]] += 1;
        }
        vector<vector<int>> res(2, vector<int>(0));
        for (auto const& kv : winMap) {
            if (lossMap.count(kv.first) == 0) {
                res[0].push_back(kv.first);
            }
        }
        for (auto const& kv : lossMap) {
            if (kv.second == 1) {
                res[1].push_back(kv.first);
            }
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};


int main() {
	Solution s;
	return 0;
}
