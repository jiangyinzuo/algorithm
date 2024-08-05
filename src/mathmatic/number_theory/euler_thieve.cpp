//
// Created by jiang on 2020/9/21.
//

#include <cstdio>
#include <vector>

constexpr int MAX_N = 100005;
std::vector<int> primes;
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

int main() {
    euler_thieve();
    for (int i = 0; i < 100; ++i) printf("%d ", primes[i]);
    return 0;
}
