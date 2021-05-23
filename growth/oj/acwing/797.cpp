#include<iostream>

using namespace std;

const int N = 100010;

int a[N];
int b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r+1] -= c;
}

int main () {
    
    int m, n;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);

    while(m--) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i++) b[i] = b[i-1] + b[i];
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    cout << endl;
    return 0;
}
