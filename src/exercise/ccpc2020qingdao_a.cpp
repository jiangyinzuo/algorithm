//
// Created by jiang on 2020/10/18.
//

#include <cstdio>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int r, b;
        scanf("%d %d", &r, &b);
        if (r <= 1) {
            printf("Case #%d: 0/1\n", kase);
        } else if (b == 0) {
            printf("Case #%d: 1/1\n", kase);
        } else {
            int c = r * (r - 1) / 2, d = (r + b) * (r + b - 1) / 2;
            int factor = gcd(c, d);
            printf("Case #%d: %d/%d\n", kase, c / factor, d / factor);
        }
    }
    return 0;
}