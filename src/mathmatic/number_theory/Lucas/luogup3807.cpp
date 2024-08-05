//
// Created by jiang on 2020/9/18.
// luogup3807

#include <cstdio>

constexpr int N = 100001;
long long a[N];

// 快速幂求逆元
long long pow(long long x, int idx, int p) {
    x %= p;
    long long ans = 1;
    while (idx) {
        if (idx & 1)
            ans = ans * x % p;
        idx >>= 1;
        x = x * x % p;
    }
    return ans;
}

// 初始化n！% p
void init_a(int p) {
    a[0] = 1;
    for (int i = 1; i <= p; i++)
        a[i] = (a[i - 1] * i) % p;
}

// C_n^m % p = n!/(m! * (n - m)!) % p
long long C(long long n, long long m, int p) {
    if (m > n) return 0;
    return ((a[n] * pow(a[m], p - 2, p)) % p * pow(a[n - m], p - 2, p) % p);
}

// 求C_n^m % p
long long lucas(long long n, long long m, int p) {
    if (m == 0) return 1;
    return (C(n % p, m % p, p) * lucas(n / p, m / p, p)) % p;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n, m;
        int p;
        scanf("%lld %lld %d", &n, &m, &p);
        init_a(p);
        printf("%lld\n", lucas(n + m, m, p));
    }
    return 0;
}
