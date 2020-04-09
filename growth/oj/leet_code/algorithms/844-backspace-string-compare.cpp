#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int target_size = 0;
        int p = 0;
        for (int i = 0; i< S.size(); i++) {
            if (S[i] == '#') {
                p = p == 0 ? 0 : p - 1;
                continue;
            }
            S[p++] = S[i];
        }
        target_size = p;
        p = 0;
        for (int i = 0; i < T.size(); i++) {
            if (T[i] == '#') {
                p = p == 0 ? 0 : p - 1;
                continue;
            }
            T[p++] = T[i];
        }
        if (target_size != p)
            return false;
        target_size = target_size > p ? p : target_size;
        for (int i = 0; i < target_size; i++) {
            if (S[i] != T[i])
                return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    cout << s.backspaceCompare("ab#c", "ad#c") << endl;

    cout << s.backspaceCompare("ab##", "c#d#") << endl;

    cout << s.backspaceCompare("a##c", "#a#c") << endl;

    cout << s.backspaceCompare("a#c", "b") << endl;
    cout << s.backspaceCompare("#####", "b") << endl;

    cout << s.backspaceCompare("isfcow#","isfco#w#") << endl;




    return 0;
}
