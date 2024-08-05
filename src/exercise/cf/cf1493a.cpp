// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.
#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int min = k / 2;
        int total =  (n - k) + (min + k - 1) * (k-min) / 2;
        printf("%d\n", total);
        for (int i = k+1 ; i <=n; ++i) {
            printf("%d ", i);
        }
        if (k == 3) {
            puts("2");
        } else if (k == 2) {
            puts("1");
        }
        puts("");
    }
    return 0;
}
