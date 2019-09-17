#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = -1;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < min_length || min_length == -1) {
                min_length = strs[i].length();
            }
        }
        string common_length = "";
        for (int i = 0; i < min_length; i++) {
            bool equal = true;
            for(int j = 0; j < strs.size()-1; j++) {
                if (strs[j].at(i) != strs[j+1].at(i)) {
                    equal = false;
                    break;
                }
            }
            if (!equal) {
                break;
            }
            common_length += strs[0].at(i);
        }
        return common_length;
    }
};


int main() {
    Solution obj;
    //vector<string> vec = {"flower","flow","flight"};
    vector<string> vec = {"abcd", "abc"};

    cout << obj.longestCommonPrefix(vec) << endl;
}
