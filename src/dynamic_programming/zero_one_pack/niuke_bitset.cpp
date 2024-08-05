//
// Created by jiang on 2020/8/16.
// https://ac.nowcoder.com/acm/problem/17193?&headNav=acm

#include <cstdio>
#include <bitset>

std::bitset<1000001> dp[101];

int main() {
    int n, l, r;
    scanf("%d", &n);
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &l, &r);
        for (int j = l; j <= r; ++j) {
            dp[i] |= dp[i-1] << (j*j);
        }
    }
    printf("%zu\n", dp[n].count());
    return 0;
}