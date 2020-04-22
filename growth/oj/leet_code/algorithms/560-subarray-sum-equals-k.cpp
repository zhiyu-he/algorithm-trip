#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    /*
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i-1] + nums[i];
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (i == j) {
                    cnt = nums[i] == k ? cnt + 1 : cnt;
                }
                else {
                    if (i - 1 < 0)
                        cnt += (prefix[j] == k ? 1 : 0);
                    else
                        cnt += (prefix[j] - prefix[i-1] == k ? 1 : 0);
                }

            }
        }

        return cnt;
    }
    */
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.find(sum-k) != m.end())
                cnt += m[sum-k];
            m[sum] += 1;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> v{1,1,1};
    cout << s.subarraySum(v, 2) << endl;
    v={1,1};
    cout << s.subarraySum(v, 2) << endl;
    v={1};
    cout << s.subarraySum(v, 2) << endl;
    v={};
    cout << s.subarraySum(v, 2) << endl;




    return 0;
}
