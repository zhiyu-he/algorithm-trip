#include<iostream>

using namespace std;

const int N = 100010;

int s[N];

// method1: is_root = s[x] = x;
// method2: while(x != s[x]) x = s[x];
// method3: 合并, px是x的编号、py是y的编号。p[x]=y
int find(int a) {
    int x = a;
    while(s[x] != x) {
        x = s[x];
    }
    return x;
}

int find2(int a) {
    if (s[a] != a)
        s[a] = find2(s[a]);
    return s[a];
}

int main() {
    int n, m;
    scanf("%d %d", &n , &m);
    // init
    for (int i = 1; i <= n; i++) {
        s[i] = i;
    }
    while(m--) {
        char op[2];
        int a, b;
        scanf("%s %d %d", op, &a, &b);
        if (op[0] == 'M') s[find2(a)] = find2(b);
        else {
           if (find2(a) == find2(b)) puts("Yes");
           else puts("No");
        }
    }
    return 0;
}
