#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> bucket(1001);
        for (int i = 0; i < bucket.size(); i++)
            bucket[i] = 0;
        
        for (int i = 0; i < stones.size(); i++)
            bucket[stones[i]] += 1;
        
        while(1) {
            int first_idx = -1;
            int second_idx = -1;
            for (int i = 1000; i > 0; i--) {
                if (bucket[i] > 0 && first_idx == -1) {
                    first_idx = i;
                    if (bucket[i] > 1)
                        i += 1;
                    continue;
                }
                if (bucket[i] > 0 && second_idx == -1)
                    second_idx = i;

                if (first_idx > 0 && second_idx > 0)
                    break;
            }
            cout << "f " << first_idx << " s " << second_idx << endl;
            if (first_idx > 0 && second_idx > 0) {
                bucket[first_idx - second_idx] += 1;
                bucket[first_idx] -= 1;
                bucket[second_idx] -= 1;
            } else {
                if (first_idx == -1 && second_idx == -1)
                    return 0;
                if (first_idx != -1 && second_idx == -1)
                    return first_idx;
                if (second_idx != -1 && first_idx == -1)
                    return second_idx;
            }
        }       
        return 0;
    }
};


int main() {
    Solution s;
    vector<int> v{2,7,4,1,8,1};
    cout << s.lastStoneWeight(v) << endl;
    vector<int> v2{1,1};
    cout << s.lastStoneWeight(v2) << endl;

    vector<int> v3{3, 7, 2};
    cout << s.lastStoneWeight(v3) << endl;

    vector<int> v4{7,6,7,6,9};
    cout << s.lastStoneWeight(v4) << endl;


    return 0;
}
