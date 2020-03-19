#include<iostream>
#include<vector>
#include<string>


using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapping{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.length() == 0) {
            return res;
        }

        int targetLen = 0;
        for (auto c : digits) {
            if (c != '1') {
                targetLen += 1;
            }
        }
        dfs(digits, 0, targetLen, "", res, mapping);
        return res;
    }
    int parseChar(char c) {
        return int(c) - 48;
    }
    
    void dfs(string& digits, int digitsPos, int endLen, string str, vector<string>& res, vector<string>& mapping) {
        if (str.length() == endLen) {
            res.push_back(str);
            return;
        }
        if (digits.length() == digitsPos) {
            return;
        }

        char c = digits[digitsPos];
        if (c == '1') {
            dfs(digits, digitsPos+1, endLen, str, res, mapping);
        } else {
            int intC = parseChar(c);
            for (auto c : mapping[intC-1]) {
                dfs(digits, digitsPos+1, endLen, str, res, mapping);
                dfs(digits, digitsPos+1, endLen, str+c, res, mapping);
            }
        }
    }
};


int parseChar(char c) {
    return int(c) - 48;
}


void p(vector<string> res) {
    for (auto s : res) {
        cout << s << endl;
    }
}

int main() {
    Solution s;
    string str = "123";
    for (auto c : str) {
    
        cout << parseChar(c) << endl;
    }
    cout << str[2] << endl;
    cout << str << endl;

    auto res = s.letterCombinations("23");
    p(res);
    auto res2 = s.letterCombinations("12");
    p(res2);



    return 0;
}
