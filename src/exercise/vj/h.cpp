//
// Created by Jiang Yinzuo on 2020/5/30.
//
#include <cstdio>
#include <map>

#include <vector>
std::vector<int> primes[100];

int main() {
    long long k;
    scanf("%lld", &k);
    int count = 0;
    long long n = k * k;
    int idx = 0;
    for (int i = 2; i * i <= n; ++i) {
        int a = 1;
        while (n % i == 0) {
            a *= i;
            primes[idx].push_back(a);
            n /= i;
        }
        if (!primes[idx].empty())++idx;
    }
    printf("%d\n", count);
    for (auto &i : primes) {
        for (int j = 0; j < i.second; ++j) {

        }
    }
    return 0;
}