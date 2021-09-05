#include<iostream>
#include<algorithm>

using namespace std;

const int N = 50000 + 10;

struct p {
    int w;
    int s;
};

p pairs[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ;i < n; i++) {
        scanf("%d %d", &pairs[i].w, &pairs[i].s);
    }
    sort(pairs, pairs+n, [](p& p1, p& p2) {
       return p1.w + p1.s < p2.w + p2.s; 
    });

    int res = -pairs[0].s;
    int total_weight = 0;
    for (int i = 1; i < n; i++) {
        total_weight += pairs[i-1].w;
        res = max(res, total_weight - pairs[i].s);
    }
    cout << res << endl;
    return 0;
}
