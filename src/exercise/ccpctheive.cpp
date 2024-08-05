//
// Created by jiang on 2020/9/20.
//

#include <iostream>
#include <algorithm>
#include <cmath>

const int maxn = 110;

inline long long v_2_idx(long long v, long long N, long long Ndr, long long nv) {
    return v >= Ndr ? (N / v - 1) : (nv - v);
}

long long prime_sum(long long n) {
    long long r = (long long) sqrt((double)n);
    long long Ndr = n / r;
    long long nv = r + Ndr - 1;

    long long *V = new long long[nv], *S = new long long[nv];
    for (long long i = 0; i < r; i++)
        V[i] = n / (i + 1);
    for (long long i = r; i < nv; i++) V[i] = V[i - 1] - 1;
    for (long long i = 0; i < nv; i++) S[i] = V[i] * (V[i] + 1) / 2 - 1;
    for (long long p = 2; p <= r; p++) {
        if (S[nv - p] > S[nv - p + 1]) {
            long long sp = S[nv - p + 1];
            long long p2 = p * p;
            for (long long i = 0; i < nv; i++) {
                if (V[i] >= p2) S[i] -= p * (S[v_2_idx(V[i] / p, n, Ndr, nv)] - sp);
                else break;
            }
        }
    }
    return S[0];
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long ret = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}

long long getInv(int a, int mod) {
    long long x, y;
    long long d = exgcd(a, mod, x, y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}

long long a[maxn] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                     101};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n, K;
        std::cin >> n >> K;
        long long sum = 0;
        sum += (((n % K) * ((n + 3) % K)) % K * (getInv(2, K))) % K;
        long long ans = prime_sum(n + 1) % K;
        sum = (sum + ans) % K;
        sum = (sum - 4) % K;
        std::cout << sum << std::endl;
    }
    return 0;
}