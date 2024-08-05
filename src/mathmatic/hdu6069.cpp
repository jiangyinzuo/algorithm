//
// Created by Jiang Yinzuo on 2020/7/17.
//

#include <cstdio>
#include <vector>
#include <cstring>

const int MOD = 998244353;
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

void solve(long long l, long long r, long long k) {
    static long long num[1000006];
    static long long factor_count[1000006];
    for (long long i = l; i <= r; ++i) {
        num[i - l] = i;
        factor_count[i - l] = 1;
    }

    for (auto &prime : primes) {
        if (prime * prime > r) break;
        long long i = (long long) (l / prime) * prime;
        while (i < l) i += prime;
        for (; i <= r; i += prime) {
            long long count = 0;
            while (num[i - l] % prime == 0) {
                num[i - l] /= prime;
                count++;
            }
            factor_count[i - l] = factor_count[i - l] * (count * k + 1) % MOD;
        }
    }

    long long answer = 0;
    for (long long i = l; i <= r; ++i) {
        if (num[i - l] == 1)
            answer = (answer + factor_count[i - l]) % MOD;
        else answer = (answer + factor_count[i - l] * (k + 1) % MOD) % MOD;
    }
    printf("%lld\n", answer);
}

int main() {
    sieve(1000005);
    int t;
    scanf("%d", &t);
    while (t--) {
        long long l, r, k;
        scanf("%lld %lld %lld", &l, &r, &k);
        solve(l, r, k);
    }
    return 0;
}
