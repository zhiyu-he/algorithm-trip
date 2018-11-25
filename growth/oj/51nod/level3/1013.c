#include <stdio.h>

/**
 *
 * 本质上是等比数列求和, 公式为a1*(1-q^n)/(1-q)
 * 对于本题, 则转化为(3^n - 1) / (3-1)
 * 变成了, 如何快速计算3^n.
 * 计算3^n, 直接开log即可. 进行快速幂运算
 * 对于快速幂, 实际上我理解是对bit的展开, 好比3^15, 15=B(1111), 即(8+4+2+1)-> 对于ans=3^(1+2+4+8),
 * 每次n的最低位为1时,都需要进行一次乘法操作
 * 
 * 这里面有两个时机, 乘法操作, 当n & 1 -> 1时
 * 第二个时机, 贯穿始终的, 计算最高位的幂次, 好比15, 则需要右移4次。使得3的幂次最高达到3^8
 *
 * 另一方面对于对于任意一个数字, 我们都可以写成2的幂次和形式. 也就是eg. 15=1+2+4+8、3=1+2、4=4
 */
#define MOD 1000000007


long long pow_up(long long n) {
    long long ans = 1;
    long long base = 3;
    while (n) {
        if (n & 1)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        n >>= 1;
    }
    return ans;
}


int main() {
    long long n;
    scanf("%lld", &n);
    n = n+1;    // 这里的n是3头上的系数, 实际上整个等比数列有 n+1项
    long long base;
    base = pow_up(n);
    // 这里要考虑乘法逆元
    base = (base-1) * 500000004 % MOD;
    printf("%lld\n", base);
    return 0;
}
