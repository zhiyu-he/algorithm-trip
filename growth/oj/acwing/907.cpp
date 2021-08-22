#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

struct seg {
    int l;
    int r;
};
seg segs[N];

int main() {
    int s, t;
    scanf("%d %d", &s, &t);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segs[i].l, &segs[i].r);
    }
    sort(segs, segs+n, [](seg &s1, seg &s2) {
        return s1.l < s2.l;
    });


    int last_l = s;
    bool ok = false;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int max_right = -1;
        int right_val = -2e9;
        while(segs[i].l <= last_l && i < n) {
            if (segs[i].r > right_val) {
                right_val = segs[i].r;
                max_right = i;
            }
            i++;
        }
        if (max_right == -1) {
            break;
        }
        res += 1;
        last_l = segs[max_right].r;
        if (last_l >= t) {
            ok = true;
            break;
        }
        i -= 1;
    }
    if (ok) cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}
