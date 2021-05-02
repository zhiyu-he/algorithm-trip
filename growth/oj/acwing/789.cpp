#include<iostream>

using namespace std;

const int N = 100001;
int a[N];

// [l, mid], [mid+1, r]
int bs_1(int input[], int t, int l, int r) {
    if (l >= r) return l;
    while(l < r) {
        int mid = (l+r) >> 1;
        if (input[mid] >= t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// [l, mid-1], [mid, r]
int bs_2(int input[], int t, int l, int r) {
    if (l >= r) return l;
    while (l < r) {
        int mid = (l+r+1) >> 1;
        if (input[mid] <= t) {
            l = mid;
        } else {
            r = mid - 1;
        }
       
    }
    return l;
}


int main() {
    int n, q, k;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    

    while(q--) {
        scanf("%d", &k);
        int l = bs_1(a, k, 0, n-1);
        if (a[l] != k) cout << "-1 -1" << endl;
        else {
            cout << l;
            l = bs_2(a, k, 0, n-1);
            cout << " " << l << endl;
        }
    }

    return 0;
}
