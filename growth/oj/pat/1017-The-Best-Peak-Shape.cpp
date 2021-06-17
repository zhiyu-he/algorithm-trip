#include<iostream>
using namespace std;

const int N = 1e4+10;

int pre[N];
int suf[N];
int input[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < n; i++) {
        pre[i] = 1;
        for (int j = 0; j < i; j++) {
            if (input[i] > input[j])
                pre[i] = max(pre[i], pre[j]+1);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        suf[i] = 1;
        for (int j = n-1; j > i; j--) {
            if (input[i] > input[j])
                suf[i] = max(suf[i], suf[j] + 1);
        }
    }
    /*
    for (int i = 0; i < n; i++)
        cout << " " << pre[i];
    cout << endl;
        cout << "---" << endl;
    for (int i = 0; i < n; i++)
        cout << " " << suf[i];
    cout << endl;
    cout << "---" << endl;
    */
    int max_idx = -1;
    int max_len = 0;
    int min_difference = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] == 1 || suf[i] == 1) continue;
        int difference = abs(pre[i] - suf[i]);
        if (pre[i] + suf[i] > max_len) {
            max_len = pre[i] + suf[i];
            max_idx = i;
            min_difference = difference;
        }

        if (pre[i] + suf[i] == max_len && difference < min_difference) {
            max_len = pre[i] + suf[i];
            max_idx = i;
            min_difference = difference;
        }
    }
        

        
    
    if (max_idx == -1)
        cout << "No peak shape"  << endl;
    else
        printf("%d %d %d", max_len-1, max_idx+1, input[max_idx]);
    return 0;
}
