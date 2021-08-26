#include<iostream>
#include<algorithm>

using namespace std;

int input[1000010];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);
    sort(input, input + n);
    
    float a = input[n/2];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int delta = a - input[i];
        res += delta > 0 ? delta : -delta;
    }
    cout << res << endl;
    return 0;
}
