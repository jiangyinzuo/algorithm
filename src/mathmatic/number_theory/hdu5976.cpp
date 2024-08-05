//
// Created by Jiang Yinzuo on 2020/7/17.
//

#include <cstdio>
#include <algorithm>
#include <cmath>

const int MOD = 1e9 + 7;
long long factorial[44735];
long long pre_sum[44735];

void init() {
    factorial[1] = 1;
    factorial[2] = 2;
    pre_sum[2] = 2;
    for (int i = 3; i <= 44734; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
        pre_sum[i] = pre_sum[i - 1] + i;
    }
}

long long fast_pow(long long base, long long idx, long long mod) {
    if (base == 0 || mod == 1) return 0;
    long long result = 1;
    base %= mod;
    while (idx > 0) {
        if (idx & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        idx >>= 1;
    }
    return result;
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        if (x <= 4) {
            printf("%d\n", x);
            continue;
        }
        long long idx = std::lower_bound(pre_sum + 2, pre_sum + 44734, x) - pre_sum;

        if (x == pre_sum[idx]) {
            printf("%lld\n", factorial[idx]);
        } else {
            long long delta = x - pre_sum[idx - 1];
            long long left = 2 + delta / (idx - 2);
            long long right = idx - 1 + (long long) ceil((double) delta / (double) (idx - 2));
            long long exclude = right - delta % (idx - 2);
            long long answer;
            if (exclude == right)  answer = factorial[right];
            else answer = factorial[right] * fast_pow(exclude, MOD - 2, MOD) % MOD;
            if (left > 2) {
                answer = answer * fast_pow(factorial[left - 1], MOD - 2, MOD) % MOD;
            }
            printf("%lld\n", answer);
        }
    }
    return 0;
}