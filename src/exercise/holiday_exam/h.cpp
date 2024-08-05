//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long arr[400009] = {0};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, q;
        scanf("%lld %lld %lld", &a, &b, &q);
        long long l = lcm(a, b);
        arr[0] = 0;
        for (long long i = 1; i <= l; ++i) {
            if (i % a % b != i % b % a) {
                arr[i] = arr[i - 1] + 1;
            } else {
                arr[i] = arr[i - 1];
            }
        }
        long long left, right;
        for (int i = 0; i < q; ++i) {
            scanf("%lld %lld", &left, &right);
            long long _right = right % l;
            if (_right == 0) _right = l;
            long long _left = (left-1) % l;
//            if (_left == 0) _left = l;
            printf("%lld%c", ((right - 1) / l - (left - 1) / l) * arr[l] + arr[_right] - arr[_left],
                   i == q - 1 ? '\n' : ' ');
        }
    }
    return 0;
}