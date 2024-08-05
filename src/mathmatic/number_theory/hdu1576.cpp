//
// Created by Jiang Yinzuo on 2020/7/17.
//
#include <cstdio>

/**
 * 扩展欧几里得算法
 * ax + by = gcd(a, b)
 * x、y是方程的一组整数解
 * @return gcd(a,b)
 */
int ex_gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = ex_gcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, b;
        scanf("%d %d", &n, &b);
        int x, y;
        ex_gcd(b, 9973, x, y);
        x = (x * n) % 9973;
        if (x < 0) x += 9973;
        printf("%d\n", x);
    }
    return 0;
}