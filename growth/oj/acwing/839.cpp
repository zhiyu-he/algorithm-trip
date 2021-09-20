#include<iostream>
using namespace std;

const int N = 100010;

// hp, heap2pointer, 堆中的idx, 对应第k次插入的
// ph, pointer2headp, 第k次插入的元素, 在heap中的位置
int h[N], hp[N], ph[N];
int heap_cnt, m;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void up(int u) {
    while(u / 2  && h[u/2] > h[u]) {
        heap_swap(u, u/2);
        u /= 2;
    }
}

void down(int u) {
    int t = u;
    if (2 * u <= heap_cnt && h[2 * u] < h[t]) t = 2 * u;
    if (2 * u + 1 <= heap_cnt && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if (u != t) {
        heap_swap(t, u);
        down(t);
    }
}


int main() {
    int n;
    scanf("%d %d", &n);
    char op[5];
    while(n--) {
        scanf("%s", op);
        if (op[0] == 'I') {
            int a;
            scanf("%d", &a);
            heap_cnt += 1;
            m += 1;
            h[heap_cnt] = a;
            hp[heap_cnt] = m;
            ph[m] = heap_cnt;
            up(heap_cnt);
        } else if (op[0] == 'D' && op[1] == 'M') {
            heap_swap(1, heap_cnt);
            heap_cnt -= 1;
            down(1);
        } else if (op[0] == 'C') {
            int k, x;
            scanf("%d %d", &k, &x);
            int idx = ph[k];
            h[idx] = x;
            down(idx);
            up(idx);
        } else if (op[0] == 'D') {
            int k;
            scanf("%d", &k);
            // 第k的数在h数组中的位置
            int idx = ph[k];
            heap_swap(idx, heap_cnt);
            heap_cnt -= 1;
            down(idx);
            up(idx);
        } else {
            // 'PM'
            cout << h[1] << endl;
        }
    }
    
    return 0;
}
