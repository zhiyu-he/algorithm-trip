#include<iostream>

using namespace std;

const int N = 1010;

int v[20050], w[20050];

int dp[20050];

int main() {
    
    int n, V;
    scanf("%d %d", &n, &V);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int _v, _w, _s;
        scanf("%d %d %d", &_v, &_w, &_s);
        int k = 1;
        while(k < _s) {
            v[cnt] = k * _v;
            w[cnt] = k * _w;
            cnt += 1;
            _s -= k;
            k *= 2;
        }
        if (_s > 0) {
            v[cnt] = _s * _v;
            w[cnt] = _s * _w;
            cnt += 1;
        }
    }
    n = cnt;
    for (int i = 0; i < n; i++) {
        for (int j = V; j >= 0; j--) {
            if (v[i] <= j) {
                dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
