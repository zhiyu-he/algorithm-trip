#include <stdio.h>

/**
 *
 * 本质上是等比数列求和, 公式为a1*(1-q^n)/(1-q)
 * 对于本题, 则转化为(3^n - 1) / (3-1)
 * 变成了, 如何快速计算3^n.
 * 计算3^n, 直接开log即可.
 * eg. 
 * n=3, log3 = 1.xx = 1 * 2
 * n=4, log4 = 2 = 1 * 2 *2
 * n=5, log5 = 2.xxx = 4 + 1
 *
 */
#define MOD 1000000007


long long three_3(long long n) {
    long long idx = 1;
    long long base = 3;
    while (idx * 2 <= n) {
        base = (base * base) % MOD;
        idx *= 2;
    }
    return base;
}

long long divide(long long n) {
    long long two = 1;
    long long rsp = 1;
    while (n > 0) {
        long long idx = 1;
        while (idx * 2 <= n) {
            idx *= 2;
        }
        rsp *= three_3(idx);
        rsp %= MOD;
        n -= idx;
    }
    return rsp;
}


int main() {
    long long n;
    scanf("%lld", &n);
    n = n+1;    // 这里的n是3头上的系数, 实际上整个等比数列有 n+1项
    long long sum = 0;
    long long idx = 1;
    long long base;
    base = divide(n);
    // 这里要考虑乘法逆元
    base = (base-1) * 500000004 % MOD;
    printf("%lld\n", base);
    return 0;
}
