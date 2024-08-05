//
// Created by Jiang Yinzuo on 2020/7/17.
//

#include <cstdio>
#include <algorithm>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int x, y;
        scanf("%d %d", &x, &y);
        int k = gcd(x, y);
        int count = 1;
        x /= k;
        y /= k;
        while (true) {
            if (x > y) std::swap(x, y);
            if (y % (x + 1) == 0) {
                y /= (x + 1);
                count++;
            } else {
                break;
            }
        }
        printf("Case #%d: %d\n", kase, count);
    }
    return 0;
}