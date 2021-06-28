#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

const int N = 110;
const int limits = 200;
int cnt = 0;

int global_min = INT_MAX;
int global_max = INT_MIN;

vector<vector<int>> table(N, vector<int>(256));

vector<vector<int>> suffix(N, vector<int>(256));

int dfs(vector<int>& curBuy, vector<int>& target, vector<vector<int>>& table, vector<vector<int>>& suffix, vector<bool>& itemOK, int idx, int n) {
    cnt += 1;
    if (cnt > limits) return INT_MAX;
    bool r_is_ok = true;
    bool pre_is_ok = true;
    int r_pos_cnt = 0;
    for (int i = '0'; i <= 'z'; i++) {
        if (curBuy[i] < target[i]) r_is_ok = false;
        if (curBuy[i] + suffix[idx][i] < target[i]) pre_is_ok = false;
        int delta = curBuy[i] - target[i];
        if (r_is_ok && delta >= 0) {
            r_pos_cnt += delta;
        }
    }
    if (r_is_ok) {
        global_min = min(global_min, r_pos_cnt);
        return global_min;
    }

    if (!pre_is_ok) return INT_MAX;
    if (idx > limits) return -1;
    
    if (idx == n) {
        int pos_cnt = 0;
        int neg_cnt = 0;
        bool is_ok = true;
        for (int i = '0'; i <= 'z'; i++) {
            int delta = curBuy[i] - target[i];
            if (curBuy[i] < target[i]) is_ok = false;
            if (is_ok && delta >= 0) {
                pos_cnt += delta;
            }
            if (!is_ok && delta < 0) neg_cnt += delta;
        }
        if (is_ok) {
            global_min = min(global_min, pos_cnt);
        }
        if (!is_ok) {
            global_max = max(global_max, neg_cnt);
        }
        return pos_cnt;
    }

    
    int pick = 0, nopick = 0;
    
    if (itemOK[idx]) {
        for (int i = '0'; i <= 'z'; i++)
            curBuy[i] += table[idx][i];
        pick = dfs(curBuy, target, table, suffix, itemOK, idx+1, n);
        for (int i = '0'; i <= 'z'; i++)
            curBuy[i] -= table[idx][i];
    }
    nopick = dfs(curBuy, target, table, suffix, itemOK, idx+1, n);

    if (pick < 0 && nopick < 0) return max(pick, nopick);
    if (pick >= 0 && nopick >= 0) return min(pick, nopick);
    if (pick >= 0 && nopick < 0) return pick;
    if (pick < 0 && nopick >= 0) return nopick;
}

int main() {
    string target;
    cin >> target;
    vector<string> items;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        items.push_back(tmp);
    }
    // 处理target
    vector<int> targetT = vector<int>(256);
    for (auto ch : target)
        targetT[int(ch)] += 1;
    
    vector<bool> itemOk;
   
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (auto ch : items[i]) {
            table[i][int(ch)] += 1;
            if (targetT[int(ch)] > 0) ok = true;
        }
        itemOk.push_back(ok);
    }

    // 构造suffix, [idx, ...]
    for (int i = n-1; i >= 0; i--) {
        for (int j = '0'; j <= 'z'; j++) {
            suffix[i][j] = suffix[i+1][j] + table[i][j];
        }
    }
    
    bool is_ok = true;
    for (int i = '0'; i <= 'z'; i++) {
        if (targetT[i] > 0 && targetT[i] > suffix[0][i]) {
            is_ok = false;
            break;
        }
    }
    //cout << "is_ok " << is_ok << endl;
    int neg_cnt = 0;
    if (!is_ok) {
        for (int i = '0'; i <= 'z'; i++) {
            if (targetT[i] > 0) {
                int delta = suffix[0][i] - targetT[i];
                if (delta < 0) neg_cnt += delta;
            }
        }
        cout << "No " << abs(neg_cnt) << endl;
        return 0;
    }
    
    vector<int> curBuy(256);
    dfs(curBuy, targetT, table, suffix, itemOk, 0, n);
    
    if (global_min != INT_MAX)
        cout << "Yes " << global_min << endl;
    else
        cout << "No " << abs(global_max) << endl;
    return 0;
}

