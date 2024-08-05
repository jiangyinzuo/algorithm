//
// Created by Jiang Yinzuo on 2020/10/24.
//

#include <cstdio>

long long f[91] = {0, 1, 1, 2, 3};

void init_f() {
    for (int i = 5; i <= 90; ++i)
        f[i] = f[i - 1] + f[i - 2];
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    init_f();
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(gcd(f[a], f[b]) == 1 ? "YES" : "NO");
    }

    return 0;
}