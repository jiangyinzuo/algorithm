//
// Created by jiang on 2020/8/16.
//

#include <cstdio>
#include <cstring>

bool is_prime(long long num) {
    for (long long i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        if (r - l > 50) puts("Yes");
        else {
            long long count = 0;
            for (long long i = l; i <= r; ++i) {
                if (is_prime(i)) ++count;
            }
            if (count * 3 >= r - l + 1)puts("No");
            else puts("Yes");
        }
    }
    return 0;
}