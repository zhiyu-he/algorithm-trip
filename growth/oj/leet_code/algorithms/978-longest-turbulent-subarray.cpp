#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> up(arr.size()+10);
        vector<int> down(arr.size()+10);
        up[0] = down[0] = 1;
        int res = 1;
        for (int i = 1; i < arr.size(); i++) {
            up[i] = down[i] = 1;
            if (arr[i] > arr[i-1]) up[i] = down[i-1] + 1;
            if (arr[i] < arr[i-1]) down[i] = up[i-1] + 1;
            res = max(res, max(down[i], up[i]));
        }
        return res;
    }
};
