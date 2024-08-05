//
// Created by jiang on 2020/5/23.
//

#include <cstdio>
#include <cstring>

#define MAX_X 1000000
const long long mod = 1e9 + 7;

long long f[1000002] = {0};
long long big_factor[1000002];

void init() {
    memset(big_factor, 2, sizeof(big_factor));
    for (long long factor = 1; factor <= MAX_X; ++factor) {
        for (long long x = factor; x <= MAX_X; x += factor) {
            if (factor * factor >= x)
                big_factor[x] = big_factor[x] < factor ? big_factor[x] : factor;
            else break;
        }
    }
    for (int x = 1; x <= MAX_X; ++x)
        f[x] = (f[x - 1] + (x / big_factor[x] + big_factor[x]) / 2) % mod;
}

int main() {
    init();
    int t, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        printf("%lld\n", f[x]);
    }
    return 0;
}