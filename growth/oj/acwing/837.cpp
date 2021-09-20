#include<iostream>

using namespace std;

const int N = 100010;

int s[N], count[N];

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
        count[i] = 1;
    }
    while(m--) {
        char op[5];

        scanf("%s", op);
        if (op[0] == 'C') {
            int a, b;
            scanf("%d %d", &a, &b);
            if (find2(a) == find2(b)) continue;
            // 只看根节点的size, b<-a, 将a的值给b, 在将a的根设置为b
            count[find2(b)] += count[find2(a)];
            s[find2(a)] = find2(b);
        } else if (op[1] == '1') {
            int a, b;
            scanf("%d %d", &a, &b);
            if (find2(a) == find2(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else {
            int a;
            scanf("%d", &a);
           cout << count[find2(a)] << endl;
        }
    }
    return 0;
}
