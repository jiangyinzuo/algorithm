//
// Created by Jiang Yinzuo on 2020/12/10.
//

#include <cstdio>

long long get_lines(long long n) {
    if (n % 2 == 1)
        return (n + 1) * ((n - 1 - 2) / 2 + 1) / 2;
    return n * ((n - 1 - 1) / 2 + 1) / 2;
}
int  main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long v = get_lines(n) * (m + 1);
    long long h = get_lines(m) * (n + 1);
    // m > n

//    prlong longf("%d %d", v, h);
    printf("%lld\n", v + h +get_lines(n) * get_lines(m) * 2);
    return 0;
}