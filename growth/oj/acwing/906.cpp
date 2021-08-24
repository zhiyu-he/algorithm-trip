#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

struct seg {
    int l;
    int r;
};

seg segs[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &segs[i].l, &segs[i].r);
    sort(segs, segs+n, [](seg &s1, seg &s2) {
        return s1.l < s2.l;
    });
    priority_queue<int, std::vector<int>, std::greater<int>> q;
    
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            q.push(segs[i].r);
        } else {
            int top = q.top();
            if (segs[i].l > top) {
                q.pop();
                q.push(segs[i].r);
            } else {
                q.push(segs[i].r);
            }
        }
    }
    cout << q.size() << endl;
    return 0;
}
