#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust_from(N+1);
        vector<int> trust_to(N+1);

        for (auto pair: trust) {
            trust_from[pair[1]] += 1;
            trust_to[pair[0]] += 1;
        }
        for (int i = 1; i <= N; i++) {
            if (trust_from[i] == N-1 && trust_to[i] == 0)
                return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}
