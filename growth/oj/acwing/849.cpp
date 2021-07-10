#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
 
 const int N = 510;
 
 int n, m;
 int g[N][N];
 
 int dis[N];
 bool st[N] = {false};
 
 int slove() {
     // 迭代N次
    memset(dis, 0x3f, sizeof(dis));
     dis[1] = 0;
     for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dis[j] < dis[t])) {
                t = j;
            }
        }
        st[t] = true;
        
        // update dis[j] = min(dis[j], g[t][j] + dis[t]);

        for (int j = 1; j <= n; j++) {
            //cout << "dis[j] " << dis[j] << endl;
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
     }
     if (dis[n] == 0x3f3f3f3f) return -1;
     return dis[n];
 }
 
 int main() {
     
     scanf("%d %d", &n, &m);
     memset(g, 0x3f, sizeof g);
     while(m--) {
         int start, end, weight;
         scanf("%d %d %d", &start, &end, &weight);
         g[start][end] = min(g[start][end], weight);
     }
     int res = slove();
     cout << res << endl;
     
     return 0;
 }
