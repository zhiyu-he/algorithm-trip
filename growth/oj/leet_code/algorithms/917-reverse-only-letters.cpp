class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) {
                i++;
                continue;
            }
            if (!(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')) {
                j--;
                continue;
            }

            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
