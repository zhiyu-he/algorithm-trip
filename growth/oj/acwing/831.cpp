#include<iostream>
#include<string>

using namespace std;

const int N = 1e6 + 10;
int ne[N];
char s[N];
char t[N];


int main() {
    int n, m;
    scanf("%d", &n);
    cin >> t;
    scanf("%d", &m);
    cin >> s;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while(j != 0 && t[i] != t[j]) {
            j = ne[j];
        }
        if (t[i] == t[j]) j++;
        ne[i+1] = j;
    }

    j = 0;
    for (int i = 0; i < m; i++) {
        while(j != 0 && s[i] != t[j]) j = ne[j];
        if (s[i] == t[j]) j++;
        if (j == n) {
            //cout << "i " << i << "n " << n << endl;
            printf("%d ", i - n + 1);
            j = ne[j];  // multi same string
        }
    }
    return 0;
}
