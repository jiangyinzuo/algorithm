//
// Created by Jiang Yinzuo on 2020/8/10.
//

#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n == 2) {
            puts("10");
            puts("00");
            continue;
        } else if (n == 4) {
            puts("1010");
            puts("0000");
            puts("1010");
            puts("0001");
            continue;
        }
        if (n & 1) {
            for (int i = 1; i <= n; ++i) {
                if (i & 1) {
                    for (int j = 1; j <= n; ++j) {
                        putchar('0' + (j & 1));
                    }
                } else {
                    for (int j = 1; j <= n; ++j) {
                        putchar('0');
                    }
                }
                putchar('\n');
            }
        } else {
            for (int i = 1; i <= n - 3; ++i) {
                if (i & 1) {
                    for (int j = 1; j <= n; ++j) {
                        putchar('0' + (j & 1));
                    }
                } else {
                    for (int j = 1; j <= n; ++j) {
                        putchar('0');
                    }
                }
                putchar('\n');
            }

            for (int j = 1; j <= n; ++j) {
                if (j & 1 || j == n) {
                    putchar('0');
                } else {
                    putchar('1');
                }
            }
            putchar('\n');

            for (int j = 1; j <= n; ++j) {
                putchar('0');
            }
            putchar('\n');

            for (int j = 1; j <= n; ++j) {
                putchar('0' + (j & 1));
            }
            putchar('\n');
        }
    }
    return 0;
}
