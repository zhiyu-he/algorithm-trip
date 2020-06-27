#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int layer_cnt = 1;
        int times = 0;
        while(q.size()) {
            int num = q.front();
            layer_cnt -= 1;
            q.pop();

            for (int i = 1; i * i <= num; i++) {
                if (num - i * i == 0) return times+1;
                q.push(num - i * i);
            }
            if (layer_cnt == 0) {
                layer_cnt = q.size();
                times += 1;
            }
        }
        return 1;
    }
};

int main() {
    Solution s;
    cout << s.numSquares(7168) << endl;
    return 0;
}
