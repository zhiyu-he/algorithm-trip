class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hash[26] = {0};
        for (char ch : text) {
            hash[ch-'a'] += 1;
        }

        vector<char> once{'b', 'a', 'n'};
        vector<char> twice{'l', 'o'};
        int res = 1e9;
        for (char ch : once) {
            res = min(res, hash[ch-'a']);
        }
        for (char ch : twice) {
            res = min(res, hash[ch-'a'] / 2);
        }
        return res;
    }
};
