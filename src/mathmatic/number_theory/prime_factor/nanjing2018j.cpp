//
// Created by jiang on 2020/9/22.
//

#include <cstdio>
#include <vector>
#include <unordered_map>

constexpr int MAX_N = 1000009;

std::vector<long long> primes;

void euler_thieve() {
    static bool not_prime[MAX_N] = {false};
    for (int i = 2; i * i < MAX_N; i++) {
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

std::unordered_map<int, std::vector<long long>> factor_pos;

void factor(int x, int pos) {
    // c++11能用for-range循环
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i) {
        if (x % primes[i] == 0) {
            factor_pos[primes[i]].push_back(pos);
            do {
                x /= primes[i];
            } while (x % primes[i] == 0);
        }
    }
    if (x > 1) factor_pos[x].push_back(pos);
}

int main() {
    euler_thieve();
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        factor(a, i);
    }
    long long ans = 0;
    for (auto &i : factor_pos) {
        ans += i.second[0] * (n - i.second[0] + 1);
        for (int j = 1; j < i.second.size(); ++j) {
            ans += (i.second[j] - i.second[j - 1]) * (n - i.second[j] + 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}