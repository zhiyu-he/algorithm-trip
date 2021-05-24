#include<iostream>

using namespace std;

const int N = 100010;

int a[N];
int shash[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        shash[a[i]] += 1;
        while(shash[a[i]] > 1) {
            shash[a[j]] -= 1;
            j++;
        }
        res = max(res, i-j+1);
    }
    cout << res << endl;
    return 0;
}
