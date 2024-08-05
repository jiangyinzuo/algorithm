//
// Created by Jiang Yinzuo on 2020/7/1.
//

#include <cstdio>

int main() {
    long long m, a, b, c;
    scanf("%lld %lld %lld %lld", &m, &a, &b, &c);
    m++;
    long long res = ((a % m)) ^ ((b - 1) % m) ^ ((c - 1) % m);
    if (res == 0)
        printf("Danftito\n");
    else
        printf("Tomaz\n");
    return 0;
}
