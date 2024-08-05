//
// Created by Jiang Yinzuo on 2020/12/10.
//

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <random>

constexpr int N = 200001;
long long a[N];

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

long long solve(int left, int right, long long n, long long p) {
    long long q = a[right] * fast_pow(a[left], p - 2, p) % p;
    long long prev = a[right], length = 2;
    for (int i = right + 1; i <= n; ++i) {
        if (prev * q % p == a[i]) {
            prev = a[i];
            ++length;
        }
    }
    prev = a[left];
    for (int i = left - 1; i >= 1; --i) {
        if (a[i] * q % p == prev) {
            prev = a[i];
            ++length;
        }
    }
    return length;
}

int main() {

    std::mt19937 random(time(nullptr));
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        long long p;
        scanf("%lld %lld", &n, &p);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
        }

        long long result = 0;
        for (int i = 0; i < 200; ++i) {
            int left = std::min(random() % (n - 1) + 1, n - 1);
            result = std::max(result, solve(left, left + 1, n, p));
            if (left + 2 <= n)
                result = std::max(result, solve(left, left + 2, n, p));
        }
        if (result * 2 >= n)
            printf("%lld\n", result);
        else
            puts("-1");
    }
    return 0;
}