#include<iostream>
#include<algorithm>

using namespace std;

struct seg {
    int l;
    int r;
};

const int N = 1e5 + 10;

seg segs[N];


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segs[i].l, &segs[i].r);
    }
    sort(segs, segs+n, [](seg &s1, seg &s2){
        return s1.r < s2.r;
    });
    int res = 0, end = -2e9;
    for (int i = 0; i < n; i++) {
        if (segs[i].l > end) {
            res += 1;
            end = segs[i].r;
        }
    }
    cout << res << endl;
    return 0;
}
