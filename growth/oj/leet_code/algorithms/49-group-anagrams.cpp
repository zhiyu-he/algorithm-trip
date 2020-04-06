#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> table(26);
        vector<vector<string>> res;
        unordered_map<string, int> str2int;
        int i = 0;

        for (string& str : strs) {
            int index = 0;
            string sort_str = "";
            for (char ch : str) {
                table[ch - 'a'] += 1;
            }
            for(int i = 0; i < table.size(); i++) {
                if (table[i] != 0) {
                    sort_str += char(i + 'a');
                    while (table[i]) {
                        sort_str += char(table[i] % 10 + 48);
                        table[i] /= 10;
                    }
                }
            }

            auto pair = str2int.find(sort_str);
            if (pair == str2int.end()) {
                index = i;
                vector<string> v;
                res.push_back(v);
                str2int[sort_str] = i++;
            } else {
                index = pair->second;
            }
            res[index].push_back(str);

        }

        return res;
    }
};

void p(vector<vector<string>>& in) {
    for (vector<string> v : in) {
        cout << "----start----" << endl;
        for (string str : v)
            cout << str << endl;
    }
}


int main() {
    Solution s;
    vector<string> v1{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = s.groupAnagrams(v1);
    p(res);
    return 0;
}
