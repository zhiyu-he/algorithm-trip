#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static const int N = 2 * 1e4 + 10;
    int l[N], r[N];
    
    int trap(vector<int>& height) {
        l[0] = height[0];
        r[height.size()-1] = height[height.size()-1];
        for (int i = 1; i < height.size(); i++) {
            l[i] = max(l[i-1], height[i]);
        }
        for (int i = height.size()-2; i >= 0; i--) {
            r[i] = max(r[i+1], height[i]);
        }
        
        int res = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int max_l = l[i-1];
            int max_r = r[i+1];
            res += max(min(max_l, max_r) - height[i], 0);
        }
        return res;
    }
};


int main() {
	Solution s;
	return 0;
}
