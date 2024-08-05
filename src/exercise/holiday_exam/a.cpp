//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>
#include <algorithm>

int main() {
    int a1, a2, k1, k2, n;
    scanf("%d %d %d %d %d", &a1, &a2, &k1, &k2, &n);

    int useless_card = a1 * (k1 - 1) + a2 * (k2 - 1);
    int min_ans, max_ans;
    if (useless_card >= n) {
        min_ans = 0;
    } else {
        min_ans = n - useless_card;
    }
    if (k1 <= k2) {
        if (n <= a1 * k1) {
            max_ans = n / k1;
        } else {
            max_ans = a1;
            n -= a1 * k1;
            max_ans += n / k2;
        }
    } else {
        if (n <= a2 * k2) {
            max_ans = n / k2;
        } else {
            max_ans = a2;
            n -= a2 * k2;
            max_ans += n / k1;
        }
    }
    printf("%d %d\n", min_ans, max_ans);
    return 0;
}