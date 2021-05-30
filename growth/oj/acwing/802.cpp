#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

const int c = 1e5 + 10;
typedef pair<long, long> P;
unordered_map<long ,long> m;
vector<P> v;
vector<int> prefix_sum;

int bs(vector<P>& input, int t) {
    int l = 0, r = input.size()-1;
    while(l < r) {
        int mid = (r + l) >> 1;
        
        //cout << "l " << l << " r " << r << "  " << mid << endl;
        if (input[mid].first >= t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    //cout << "finish " << l << endl;
    return l;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    for (int i = 0; i < n; i++) {
        int pos, val;
        scanf("%d %d", &pos, &val);
        if (m.find(pos) == m.end())
            m[pos] = val;
        else
            m[pos] += val;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
         v.push_back(P(it->first, it->second));
    }
    sort(v.begin(), v.end());

    // construct prefix-sum array

    vector<int> prefix_sum(v.size()+1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= v.size(); i++) {
        prefix_sum[i] = prefix_sum[i-1] + v[i-1].second;
    }
  
    
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ql = bs(v, l);
        int qr = bs(v, r);
    
        if (v[ql].first < l && ql == v.size()-1) {
            cout << 0 << endl;
            continue;
        }
        // 当相等时, 需要qr+1
        if (v[qr].first <= r) qr += 1;
        cout << prefix_sum[qr] - prefix_sum[ql] << endl;
    }
    return 0;
}
