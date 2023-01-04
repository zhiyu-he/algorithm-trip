#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counter;
        for (int i = 0; i < tasks.size(); i++)
            counter[tasks[i]] += 1;
        priority_queue<int> q;
        for (auto kv : counter) {
            q.push(kv.second);
            if (kv.second == 1) return -1;
        }
        int opCnt = 0;
        unordered_map<int, int> cache;
        while(!q.empty()) {
            int num = q.top();
            q.pop();
            if (num == -1) return -1;
            int cnt = slove(num, cache);
            if (cnt == -1) return -1;
            opCnt += cnt;
        }
        return opCnt;
    }

    int slove(int num, unordered_map<int, int>& cache) {
        if (cache.find(num) != cache.end()) return cache[num];
        if (num < 0) return -1;
        if (num == 1) return -1;
        if (num == 0) return 0;
        if (num == 2 || num == 3) return 1;
        int r1 = slove(num - 2, cache);
        int r2 = slove(num - 3, cache);
        int ans = -1;
        if (r1 == -1 && r2 == -1) {
            ans = -1;
        } else if (r1 == -1) {
            ans = r2 + 1;
        } else if (r2 == -1) {
            ans = r1 + 1;
        } else {
            ans = min(r1, r2) + 1;
        }
        cache[num]  = ans;
        return ans;
    }
};

class Solution2 {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counter;
        for (int i = 0; i < tasks.size(); i++)
            counter[tasks[i]] += 1;
        int opCnt = 0;
        for (auto kv : counter) {
            if (kv.second == 1) return -1;
            opCnt += (kv.second + 2) /3 ;
        }
        return opCnt;
    }

};


int main() {
    Solution s;
    return 0;
}
