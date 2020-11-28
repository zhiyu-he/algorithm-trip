#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> delta(gas.size());
        int total_cost = 0;
        for (int i = 0; i < gas.size(); i++) {
            delta[i] = gas[i] - cost[i];
            total_cost += delta[i];
        }
        if (total_cost < 0) return -1;

        int start_i = 0;
        while(delta[start_i] < 0) start_i += 1;

        int pick_cnt = 0;
        int sum = 0;
        for (int loop_i = start_i; loop_i < gas.size()*2; loop_i++) {
            sum += delta[loop_i % gas.size()];
            pick_cnt += 1;
            if (sum < 0) {
                pick_cnt = 0;
                sum = 0;
            }
            if (pick_cnt == gas.size() && sum >= 0)  {
                //cout << "loop_i " << loop_i << " sum " << sum << endl;

                return (loop_i-gas.size()+1) % gas.size();
            }
        }

        return -1;
    }
};
int main() {
    Solution s;
    return 0;
}
