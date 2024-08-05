#include <cstdint>
#include <cstdio>

int64_t fast_pow(long long base, long long idx, long long mod) {
    if (base == 0 || mod == 1) {
        return 0;
    }
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

int main() {
    long long t;
    long long n;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%ld\n", fast_pow(n, n, 10));
    }

    return 0;
}
