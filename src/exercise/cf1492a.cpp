//
// Created by Jiang Yinzuo on 2021/2/24.
//

#include <cstdio>
#include <algorithm>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long p, a[3];
        scanf("%lld %lld %lld %lld", &p, &a[0], &a[1], &a[2]);
        long long min = a[0] - p % a[0];
        for (auto i : a) {
            if (p % i == 0) min = 0;
            min = std::min(min, i - p % i);
        }
        printf("%lld\n", min);
    }
    return 0;
}