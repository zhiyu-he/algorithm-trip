#include<iostream>
#include<string>
#include<vector>

using namespace std;


class CombinationIterator {
public:
    vector<string> all;
    int next_element;
    CombinationIterator(string characters, int combinationLength) {
        next_element = 0;
        build(characters, combinationLength, "", 0);
    }
    
    void build(string& characters, int combinationLength, string str, int idx) {
        if (str.length() == combinationLength) {
            all.push_back(str);
            return;
        }
        if (characters.length() == idx) return;
        build(characters, combinationLength, str + characters[idx], idx+1);
        build(characters, combinationLength, str, idx+1);
    }
    
    string next() {
        return all[next_element++];
    }
    
    bool hasNext() {
        return next_element < all.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
	Solution s;
	return 0;
}
