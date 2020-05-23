#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.length() == 0) return s;
        map<char, int> counter;
        for (auto ch : s)
            counter[ch] += 1;

        vector<int> count_vec;
        map<int, vector<char>> rel;
        for (auto pair: counter) {
            rel[pair.second].push_back(pair.first);
            if (rel[pair.second].size() == 1)
                count_vec.push_back(pair.second);
            //cout << "pair.first " << pair.first << " second " << pair.second << endl;
        }

        string res = "";
        int size = count_vec.size();
        make_heap(count_vec.begin(), count_vec.end());

        while(size > 0) {

            int count = count_vec.front();

            for (char ch : rel[count]) {
                int loop = count;
                while(loop--)
                    res += ch;
            }
            pop_heap(count_vec.begin(), count_vec.end());
            count_vec.pop_back();
            size--;
        }
        return res;
    }
};

int main() {
    return 0;
}
