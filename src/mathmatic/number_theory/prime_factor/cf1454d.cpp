//
// Created by jiang on 2020/12/2.
//

#include <cstdio>
#include <vector>
#include <unordered_map>

constexpr int MAX_N = 100005;
std::vector<long long> primes;
bool not_prime[MAX_N] = {false};

void euler_thieve() {
    for (int i = 2; i < MAX_N; i++) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] < MAX_N; ++j) {
            not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

auto get_num_factors(long long n) {
    std::unordered_map<long long, long long> num_factors;
    for (auto &prime : primes) {
        if (prime * prime > n) break;
        if (n % prime == 0) {
            do {
                n /= prime;
                ++num_factors[prime];
            } while (n % prime == 0);
        }
    }
    if (n > 1) ++num_factors[n];
    return num_factors;
}

int main() {
    euler_thieve();
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n;
        scanf("%lld", &n);
        auto num_factors = get_num_factors(n);
        long long max_k, max_nums = 0;
        for (auto &kv : num_factors) {
            if (kv.second > max_nums) {
                max_nums = kv.second;
                max_k = kv.first;
            }
        }
        long long divisor = 1;
        printf("%lld\n", max_nums);
        for (int i = 0; i < max_nums - 1; ++i) {
            printf("%lld ", max_k);
            divisor *= max_k;
        }
        printf("%lld\n", n / divisor);
    }
    return 0;
}