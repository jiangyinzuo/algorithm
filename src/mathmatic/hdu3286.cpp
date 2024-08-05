//
// Created by Jiang Yinzuo on 2020/7/17.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

bool is_prime[1000006];
std::vector<int> primes;

void sieve(int n) {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool solve(long long n) {
    for (int prime : primes) {
        if (n % prime == 0) {
            n /= prime;
            if (n % prime == 0) return false;
        }
    }
    if (n > 1000000) {
        auto f = (long long) sqrt((double) n);
        return f * f != n;
    }
    return true;
}

int main() {
    sieve(1000005);
    int t;
    scanf("%d", &t);
    long long n;
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%lld", &n);
        printf("Case %d: %s\n", kase, solve(n) ? "Yes" : "No");
    }
    return 0;
}
