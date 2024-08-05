//
// Created by jiang on 2020/9/24.
//

#include <cstdio>

constexpr int MAX_N = 5000005;
int mu[MAX_N], primes[MAX_N], tot = 0;

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
}

int main() {
    get_mu(30);
    for (int i = 1; i < 30; ++i) printf("%d ", mu[i]);
    return 0;
}
