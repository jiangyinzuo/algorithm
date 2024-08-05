//
// Created by Jiang Yinzuo on 2020/12/16.
//

#include <cstdio>

constexpr long long MOD = 998244353;
long long inv[10000001];
long long a[10000001];

long long fast_pow(long long base, long long idx, long long mod) {
    if (base == 0 || mod == 1)
        return 0;
    long long result = 1;
    base %= mod;
    while (idx > 0) {
        if (idx & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        idx >>= 1;
    }
    return result;
}

void getinv(int n) {
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] * i % MOD;
    inv[0] = 1;
    inv[n] = fast_pow(a[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int main() {
    int n;
    scanf("%d", &n);
    getinv(n);
    long long bad_cnt = 0;
    for (int i = 0; i <= n / 2 - 1; ++i) {
        bad_cnt = (bad_cnt + ((a[n] * inv[n - i]) % MOD * inv[i]) % MOD) % MOD;
    }
    bad_cnt = (bad_cnt * 2) % MOD;
    long long total = fast_pow(3, n, MOD);
    long long ans = total - bad_cnt;
    while (ans < 0) ans += MOD;
    printf("%lld\n", (ans) % MOD);
    return 0;
}