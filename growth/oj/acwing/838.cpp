#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int h[N];
int idx;

void down(int i) {
    int t = i;
    if (i * 2 <= idx-1 && h[i*2] < h[t]) t = i * 2;
    if (i * 2 + 1 <= idx-1 && h[i*2+1] < h[t])  t = i * 2 + 1;
    if (t != i) {
        swap(h[t], h[i]);
        down(t);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    idx = n+1;
    for (int i = n/2; i >= 1; i--)
        down(i);

    for (int i = 0; i < m; i++) {
        cout << h[1] << " ";
        h[1] = h[idx-1];
        idx -= 1;
        down(1);
    }
    cout << endl;
    return 0;
}
