//
// Created by jiang on 2020/9/20.
//

#include <cstdio>

static inline int abs(int x, int y) {
    if (x > y) return x - y;
    return y - x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int a, min_a = 0x7fffffff;
        long long ans = k - 1;
        for (int i = 0; i < m ;++i) {
            scanf("%d", &a);
            min_a = min_a < a ? min_a : a;
            ans += abs(k, a) * 2;
        }

        ans += min_a - 1 - abs(min_a, k);
        printf("%lld\n", ans);
    }
    return 0;
}