//
// Created by jiang on 2020/10/19.
//

#include <cstdio>
#include <cmath>
#include <algorithm>

int qpow(int base, int idx) {
    int res = 1;
    while (idx) {
        if (idx & 1) {
            res *= base;
        }
        base *= base;
        idx >>= 1;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int n;
        int k;

        scanf("%d %d", &n, &k);
        if (k >= 30 || k == 1) {
            printf("Case #%d: %d\n", kase, n);
        } else {
            int ans = 0;
            int max_base = (int) floor(pow(n, 1 / (double) k));
            int left = 1;
            for (int base = 1; base <= max_base; ++base) {
                int tmp = qpow(base + 1, k);
                ans += std::min(tmp - 1, n) / base - left / base + 1;
                left = tmp;
            }
            printf("Case #%d: %d\n", kase, ans);
        }
    }
    return 0;
}