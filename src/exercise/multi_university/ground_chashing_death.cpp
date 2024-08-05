//
// Created by Jiang Yinzuo on 2020/8/9.
//

#include <cstdio>
#include <unordered_map>

const long long MOD = 998244353;

long long q_pow(long long base, long long idx) {
    long long answer = 1;
    while (idx) {
        if (idx & 1) {
            answer = answer * base % MOD;
        }
        base = base * base % MOD;
        idx >>= 1;
    }
    return answer;
}

long long a, b, c, d;

long long calc(long long x, long long y, long long base) {
    long long idx = 0;
    for (long long i = a; i <= b; ++i) {
        long long bound = x * i / y;
        if (bound > d) bound = d;
        else if (bound < c) bound = c - 1;
        idx = (idx + (y * (bound - c + 1) * (c + bound) / 2)) % (MOD - 1);
        idx = (idx + x * i * (d - bound)) % (MOD - 1);
    }
    long long res = q_pow((long long)base, idx);
    return res;
}

int main() {
    long long x, y;
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &x, &y);

    std::unordered_map<long long, long long> factor_nums;
    for (long long i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            ++factor_nums[i];
            x /= i;
        }
    }
    if (x > 1) ++factor_nums[x];
    long long answer = 1;
    for (long long i = 2; i * i <= y; ++i) {
        if (y % i == 0) {
            long long count = 0;
            do {
                ++count;
                y /= i;
            } while (y % i == 0);
            if (factor_nums[i])
                answer = answer * calc(factor_nums[i], count, i) % MOD;
        }
    }
    if (y > 1 && factor_nums[y]) answer = answer * calc(factor_nums[y], 1, y) % MOD;
    printf("%lld\n", answer);
    return 0;
}