//
// Created by jiang on 2020/8/16.
//

#include <cstdio>
#include <bitset>
#include <vector>
#include <unistd.h>

std::bitset<46342> is_prime;
std::bitset<1000001> is_comp;
std::vector<long long> primes;

template<typename T>
T read_integer() {
    T x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}


void thieve() {
    is_prime.flip();
    for (int i = 2; i <= 46341; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i; j <= 46341; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    thieve();
    long long l, r;
    l = read_integer<long long>();
    r = read_integer<long long>();
//    scanf("%lld %lld", &l, &r);
    if (l == 1) l = 2;
    for (auto &i : primes) {
        if (i * i > r) break;
        for (long long j = std::max(i << 1, (l + i - 1) / i * i); j <= r; j += i)
            is_comp[j - l] = true;
    }
    printf("%llu\n", r - l + 1 - is_comp.count());
    return 0;
}
