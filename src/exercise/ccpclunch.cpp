//
// Created by jiang on 2020/9/20.
//

#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

bool is_prime[100006];
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

long long factor(int x) {
    std::map<int, int> factor_nums;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i) {
        while (x % primes[i] == 0) {
            ++factor_nums[primes[i]];
            x /= primes[i];
        }
    }
    if (x > 1) ++factor_nums[x];
    long long sum = 0;
    for (std::map<int, int>::iterator iter = factor_nums.begin(); iter != factor_nums.end(); ++iter) {
        if (iter->first == 2) sum += 1;
        else sum += iter->second;
    }
    return sum;
}

int main() {
    sieve(100002);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a, ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            ans ^= factor(a);
        }
        if (ans == 0) puts("L");
        else puts("W");
    }
    return 0;
}