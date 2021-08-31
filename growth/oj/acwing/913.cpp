#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int input[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);
    sort(input, input+n);
    
    long long total_cost = 0;
    for (int i = 1; i <= n; i++) {
        total_cost += input[i-1] * (n-i);
    }
    cout << total_cost << endl;
    return 0;
}
