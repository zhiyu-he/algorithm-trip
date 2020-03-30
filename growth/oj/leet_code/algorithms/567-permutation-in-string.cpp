#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() == 0)
            return false;
        vector<int> table_cnt(26);
        for(int i = 0; i < 26; i++)
            table_cnt[i] = 0;
        for(int i = 0; i < s1.length(); i++) {
            int idx = char2int(s1[i]);
            table_cnt[idx] += 1;
        }
        
        int j = 0;
        vector<int> search = table_cnt;
        for(int i = 0; i < s2.length(); i++) {
            int head = char2int(s2[i]);
            search[head] -= 1;

            for (; j < i && search[head] < 0; j++) {
                int tail = char2int(s2[j]);
                search[tail] += 1;
            }
            
            //cout << "s1: " << s1 << "  s2: " << s2 << " i: " << i << "  j " << j << " i -j: " << i -j <<  "  len: " << s1.length() << endl;

            if (i -j >= s1.length()) {
                int tail = char2int(s2[j]);
                search[tail] += 1;
                j++;
            }
            if (i-j == s1.length() -1 && checkTable(search) == 0)
                return true;
        }
        return false;
    }

    int char2int(char ch) {
        return int(ch) - 'a';
    }
    int checkTable(vector<int>& t) {
        int cnt = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if (t[i] > 0)
                cnt += 1;

        }
        return cnt;
    }
};

int main() {

    Solution s;
    //cout << s.checkInclusion("ab", "eidbaooo");
   // cout << s.checkInclusion("ab", "eidboaoo");
    //cout << s.checkInclusion("adc", "dcda");
    cout << s.checkInclusion("foo", "money");
    return 0;
}
