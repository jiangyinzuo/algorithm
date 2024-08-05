//
// Created by Jiang Yinzuo on 2020/8/13.
//

#include <cstdio>
#include <algorithm>

const long long MOD = 998244353LL;

long long calc(long long a, long long n) {
    long long ans = 0;
    for (long long b = a, t = 1; b <= n; b *= a, ++t) {
        ans = (ans + t * (std::min(b * a, n + 1) - b) % MOD) % MOD;
    }
    return ans;
}

inline long long s1(long long n) {
    n %= MOD;
    return n * (n + 1) / 2 % MOD;
}

inline long long s2(long long n) {
    n %= MOD;
    // 6的逆元
    return (n % MOD * (n + 1) % MOD * (2 * n + 1) % MOD * 166374059) % MOD;
}

int main() {
    long long n;
    scanf("%lld", &n);
    long long ans = 0, a;
    for (a = 2; a * a < n; ++a) {
        ans = (ans + a * calc(a, n) % MOD) % MOD;
    }
    ans = (ans + (n + 1) % MOD * (s1(n) - s1(a - 1) + MOD) % MOD - (s2(n) - s2(a - 1) + MOD) % MOD + MOD) % MOD;

    printf("%lld\n", (ans + MOD) % MOD);
    return 0;
}
