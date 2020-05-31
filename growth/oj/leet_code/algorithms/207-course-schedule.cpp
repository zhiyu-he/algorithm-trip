#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1 && prerequisites.size() == 0) return true;
        if (numCourses == 1) return false;

        vector<vector<int>> g(numCourses+1, vector<int>(numCourses+1));
        unordered_map<int, vector<int>> required;
        vector<int> visits(numCourses+1);
        for (auto v : prerequisites) {
            required[v[0]].push_back(v[1]);
            g[v[0]][v[1]] = 1;
        }
        unordered_set<int> global;
        vector<int> need_handled;
        for (auto pair : required) {
            if (global.find(pair.first) != global.end())
                continue;
            auto res = helper(required, visits, global, pair.first);
            if (!res) return res;
        }
        return true;

    }
    bool helper(unordered_map<int, vector<int>>& required, vector<int>& visits, unordered_set<int>& global, int cur_course) {
        cout << " " << cur_course;
        if (visits[cur_course] != 0) return false;

        visits[cur_course] = 1;
        for (auto next_course : required[cur_course]) {
            bool res = helper(required, visits, global, next_course);
            if (!res) return false;
        }
        visits[cur_course] = 0;
        global.insert(cur_course);
        return true;
    }
};

int main() {
    return 0;
}
