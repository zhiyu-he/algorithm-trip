#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 310;

int m[N][N];
int cache[N][N];
int r, c;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int dfs(int i, int j) {
    int &ch = cache[i][j];
    if (ch != -1) return ch;
    ch = 1;
    for (int idx = 0; idx < 4; idx++) {
        int ni = i + dx[idx];
        int nj = j + dy[idx];
        if (ni >= 1 && ni <= r && nj >= 1 && nj <= c && m[i][j] > m[ni][nj] ) {
            ch = max(ch, dfs(ni, nj)+1);
        }
    }
    return ch;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    memset(cache, -1, sizeof cache);
    int res = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            res = max(res, dfs(i, j));
        }
    cout << res << endl;
    return 0;
}
