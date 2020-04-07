#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = 1;
            } else {
                m[arr[i]] += 1;
            }
        }

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (m.find(arr[i]+1) != m.end())
                cnt += 1;
        }
        return cnt;
    }
};


int main() {
    Solution s;
    vector<int> v{1, 2, 3};
    cout << s.countElements(v) << endl;

    vector<int> v1{1,1,3,3,5,5,7,7};
    cout << s.countElements(v1) << endl;

    vector<int> v2{1,3,2,3,5,0};
    cout << s.countElements(v2) << endl;

    vector<int> v3{1,1,2,2};
    cout << s.countElements(v3) << endl;

    return 0;
}
