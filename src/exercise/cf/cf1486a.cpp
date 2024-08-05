// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        long long a[109];
        long long total = 0;
        bool flag = true;
        scanf("%lld", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", a + i);
            total += a[i];
            if ((0 + i) * (i + 1) / 2 > total) {
                flag = false;
            }
        }
        puts(flag ? "yes" : "no");
    }
    return 0;
}