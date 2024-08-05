//
// Created by jiang on 2020/9/26.
//

#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 10000008;
int mu[MAX_N], primes[MAX_N], tot = 0;
long long f[MAX_N];

void get_mu(int n) {
    static bool flag[MAX_N] = {false};
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!flag[i]) primes[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * primes[j] <= n; ++j) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                break;
            }
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= tot; ++i) {
        for (int j = 1; primes[i] * j < MAX_N; ++j) {
            f[primes[i] * j] += mu[j];
        }
    }
    for (int i = 2; i < MAX_N; ++i) {
        f[i] += f[i - 1];
    }
}

long long solve(int n, int m) {
    long long res = 0;
    for (int i = 1, j; i <= std::min(n, m); i = j + 1) {
        j = std::min(n / (n / i), m / (m / i));
        res += (f[j] - f[i - 1]) * (n / i) * (m / i);
    }
    return res;
}

int main() {
    get_mu(MAX_N - 1);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%lld\n", solve(n, m));
    }
    return 0;
}