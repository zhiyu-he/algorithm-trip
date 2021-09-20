#include<iostream>
using namespace std;

const int N = 10010;

int t[N][26], cnt[N], idx_layer;
char str[N];

void insert(char str[]) {
    int p = 0;
    // str以空串结尾
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!t[p][u]) t[p][u] = ++idx_layer;
        p = t[p][u];
    }
    cnt[p] += 1;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!t[p][u]) return 0;
        p = t[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        char op[2];
        scanf("%s %s", op, str);
        if (op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return  0;
}
