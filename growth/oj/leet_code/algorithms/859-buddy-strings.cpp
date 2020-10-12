#include<iostream>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;

        int i = 0;
        while(i < A.length() && A[i] == B[i]) i++;

        int j = A.length()-1;
        while(j >= 0 && A[j] == B[j]) j--;

        if (i == A.length() || j == -1) {
            int cnt[26] = {0};
            for (int k = 0; k < A.length(); k++) {
                cnt[A[k]-'a'] += 1;
                if (cnt[A[k]-'a'] > 1) return true;
            }
            return false;
        }
        if (i == j) return false;

        char ch = A[i];
        A[i] = A[j];
        A[j] = ch;

        i = 0;
        while(A[i] == B[i] && i < A.length()) i++;
        return i == A.length();
    }
};

int main() {
    return 0;
}
