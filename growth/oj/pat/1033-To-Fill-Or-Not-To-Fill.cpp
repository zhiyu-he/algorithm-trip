#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

const int N = 510;

typedef pair<double, int> PII;

PII stations[N];

bool cmp(PII& p1, PII& p2) {
    return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second ;
}

int main() {
    int c, d, avg, n;
    scanf("%d %d %d %d",  &c, &d, &avg, &n);
    for (int i = 0; i < n; i++) scanf("%lf %d", &stations[i].first, &stations[i].second);

    sort(stations, stations+n, cmp);
    /*
    for (int i = 0; i < n; i++) {
        cout << i << " th " << "price " << stations[i].first << " pos " << stations[i].second << endl;
    }
    */
    

    
    // initial fail
    if (stations[0].second > 0) {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    
    // cur state
    int startIdx = 0;
    
    // global state
    double maxDis = 0;
    double totalPrice = 0;
    double left_c = 0;
    
    // pre state
    int preGasIdx = -1;
    while(maxDis < d) {
        //cout << "totalPrice " << totalPrice << endl;
        // 处理耗油
        //printf("%.3f\n", totalPrice);
        if(preGasIdx != -1) {
            double cost_c = (stations[startIdx].second - stations[preGasIdx].second) / double(avg);
            left_c -= cost_c;
        }
        
        int minIdx = -1;
        float minPrice = stations[startIdx].first;
        for (int i = startIdx+1; i < n && stations[i].second <= stations[startIdx].second + c * avg; i++) {
            if (stations[i].first < minPrice) {
                minIdx = i;
                break;
            }
        }
        if (minIdx != -1) {
            int tmp = stations[minIdx].second > d ? d : stations[minIdx].second;
            double need_c = double(tmp - stations[startIdx].second) / double(avg);

            need_c -= left_c;
            totalPrice += need_c * stations[startIdx].first;
            //printf("case1, price: %.3f totalPrice: %.3f need_c: %.3f\n", stations[startIdx].first, need_c * stations[startIdx].first, need_c);
            preGasIdx = startIdx;
            left_c += need_c;
            maxDis += need_c * avg;
            //cout << "case1 need_c " << need_c << " gas_from " << preGasIdx << " to " << minIdx << " cur_price " << need_c * stations[startIdx].first << "max_dis " << maxDis << endl;

            startIdx = minIdx;
            
            continue;
        }
        
        minPrice = INT_MAX;
        for(int i = startIdx + 1; i < n && stations[i].second <= stations[startIdx].second + c * avg; i++) {
            if (stations[i].first < minPrice) {
                minPrice = stations[i].first;
                minIdx = i;
            }
        }
        
        if (minIdx != -1) {
            // 直接加满
            double need_c = c - left_c;
            if (need_c * avg + maxDis > d) {
                need_c = (d - maxDis) / double(avg);
            }
            double p = totalPrice + need_c * stations[startIdx].first;
            //printf("before %.3f   price: %.3f p: %.3f\n", totalPrice, need_c * stations[startIdx].first, p);
            totalPrice += need_c * stations[startIdx].first;
            //printf("after %.3f\n", totalPrice);
            
            preGasIdx = startIdx;
            left_c = c;
            maxDis += need_c * avg;
            //cout << "case2 need_c " << need_c << " gas_from " << preGasIdx << " to " << minIdx << " cur_price " << need_c * stations[startIdx].first << " each-price " << stations[startIdx].first << "max_dis " << maxDis << endl;

            startIdx = minIdx;
            continue;
        }
        
        // 没有找到任何一个点
        double need_c = (d-maxDis) / avg;
        if (need_c > c) need_c = c;
        //cout << "final-round ? " << totalPrice << " need_c " << need_c << endl;
        
        totalPrice += need_c * stations[startIdx].first;
        
        //cout << "final-round finish " << totalPrice << " need_c " << need_c << endl;
        maxDis += c * avg;
        if (startIdx == n-1) {
            break;
        }
        if (maxDis < stations[startIdx+1].second) break;
    }
    if (maxDis < d) {
        printf("The maximum travel distance = %.2f\n", maxDis);
    } else {
        printf("%.2f\n", totalPrice);
    }

    return 0;
}
