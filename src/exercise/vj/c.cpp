//
// Created by Jiang Yinzuo on 2020/5/30.
//
#include <cstdio>
#include <algorithm>

long long a[100009] = {0};
int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    a[0] = 1;
    int t;
    int real_n = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        a[i] = a[i-1] * t;
        if (real_n == -1 && a[i] > 1000000000) {
            a[i] = 0;
            real_n = i - 1;
        }
    }
    if (real_n == -1) real_n = n;
    if (s == 0) {
        printf("0\n");
        return 0;
    } else if (s < a[1]) {
        printf("%d\n", s);
        return 0;
    }

    int i = std::lower_bound(a, a + real_n + 1, s) - a;
    if (i > real_n) --i;
    int total = 0;
    while (s > 0) {
        total += s / a[i];
        s %= a[i];
        --i;
    }
    printf("%d\n", total);
    return 0;
}
