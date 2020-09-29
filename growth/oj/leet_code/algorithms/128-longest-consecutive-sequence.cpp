#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int, int> parent;
        // initial union-find set
        unordered_map<int, int> counter;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            parent[nums[i]] = nums[i];
            counter[nums[i]] = 1;

        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                continue;
            }
            s.insert(nums[i]);
            auto pair = parent.find(nums[i]-1);
            if (pair == parent.end()) continue; // not exists
            int cur_p = find(parent, nums[i]-1);
            parent[nums[i]] = cur_p;
            counter[cur_p] += counter[nums[i]];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (parent[nums[i]] == nums[i] && counter[nums[i]] > ans)
                ans = counter[nums[i]];
        }

        return ans;
    }
    
    int find(unordered_map<int, int>& m, int child) {
        int parent = child;
        auto pair = m.find(parent);
        
        while(pair != m.end() && parent != pair->second) {
            parent = pair->second;
            pair = m.find(parent);
        }
        return parent;
    }
};

int main() {
	Solution s;
	
    return 0;
}
