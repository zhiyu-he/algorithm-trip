#include<iostream>
#include<vector>

using namespace std;

// TTL
class Solution1 {
public:
    int longestSubstring(string s, int k) {

        int length = s.length() - 1;
        while(length >= k-1) {
            for (int i = 0; i + length < s.length(); i++) {
                vector<int> counter = vector<int>(26);
                for (int j = i; j <= i + length; j++) {
                    counter[s[j]-'a'] += 1;
                }
                //cout << "length " << length << endl;
                bool ok = true;
                for (int j = i; j <= i + length; j++) {
                    if (counter[s[j]-'a'] < k) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return length + 1;
            }
            length--;
        }
        return 0;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longest(s, 0, s.length(), k);
    }
    int longest(string& s, int start, int end, int k) {
        // [start, end)
        if (end - start < k) return 0;
        int counter[26] = {0};
        for (int i = start; i < end; i++) {
            counter[s[i]-'a'] += 1;
        }
        // find the first ch, not efficent the
        for (int mid = start; mid < end; mid++) {
            if (counter[s[mid]-'a'] >= k) continue;
            int mid_next = mid + 1;
            while(mid_next < end && counter[s[mid_next]-'a'] < k) mid_next++;
            return max(longest(s, start, mid, k), longest(s, mid_next, end, k));
        }
        return end - start;
    }
};


int main() {
    Solution s;
    return 0;
}
