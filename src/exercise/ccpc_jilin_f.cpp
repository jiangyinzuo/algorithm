//
// Created by Jiang Yinzuo on 2020/10/7.
//

#include <cstdio>

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int k;
        scanf("%d", &k);
        int a, ans = 0;
        for (int i = 0; i < k; ++i) {
            scanf("%d", &a);
            ans ^= max(0, a - 2);
        }
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}
