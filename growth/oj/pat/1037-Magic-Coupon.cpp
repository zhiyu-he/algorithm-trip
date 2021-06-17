#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n1, n2;
    scanf("%d", &n1);
    vector<int> c1(n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &c1[i]);
    }
    scanf("%d", &n2);
    vector<int> c2(n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &c2[i]);
    }
    
    sort(c1.begin(), c1.end(), greater<int>());
    sort(c2.begin(), c2.end(), greater<int>());
    int forward_c = 0, backward_c = c1.size()-1;
    int forward_p = 0, backward_p = c2.size()-1;
    
    int res = 0;
    while(forward_c < c1.size() && c1[forward_c] > 0 && c2[forward_p] > 0) {
        int tmp = c1[forward_c] * c2[forward_p];
        res += tmp;
        forward_c++;
        forward_p++;
    }
    while(backward_c > 0 && c1[backward_c] < 0 && c2[backward_p] < 0) {
        res += c1[backward_c] * c2[backward_p];
        backward_c--;
        backward_p--;
    }
    cout << res << endl;
    return 0;
}
