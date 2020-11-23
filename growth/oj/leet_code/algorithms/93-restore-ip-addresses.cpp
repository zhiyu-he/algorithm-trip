#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        if (s.length() > 12) return ans;
        slove(res, ans, s, 4, 0, 0);
        vector<string> ret;
        for (auto item : res) {
            stringstream ss;
            for (int i = 0; i < item.size(); i++) {
                ss << item[i];
                if (i + 1 != item.size())
                    ss << ".";
            }
            ret.push_back(ss.str());
        }
        return ret;
    }
    void slove(vector<vector<string>>& res, vector<string>& ans, string& s, int target_size, int cur_size, int str_start_pos) {
        if (target_size == cur_size && str_start_pos == s.length()) {
            res.push_back(ans);
            return;
        }
        for (int step = 1; step <= 3; step++) {
            if (str_start_pos + step > s.length()) continue;
            int first_code = s[str_start_pos];
            int number = -1;
            if (first_code >= 48 && first_code <= 57) {
                number = first_code - 48;
            }
            if (step == 3 && !(number != -1 && number <= 2 && number > 0)) {
                continue;
            }
            if (step == 2 && !(number != -1 && number != 0)) {
                continue;
            }
            string subStr = s.substr(str_start_pos, step);
            if (stoi(subStr) > 255) continue;
            ans.push_back(subStr);
            slove(res, ans, s, target_size, cur_size+1, str_start_pos+step);
            ans.pop_back();
        }
    }
};

int main() {
    Solution s;
    return 0;
}
