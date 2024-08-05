//
// Created by Jiang Yinzuo on 2020/5/30.
//

#include <stdio.h>

int total[102][102][13] = {0};

void init() {
    for (int x = 1; x <= 100; ++x) {
        for (int y = 1; y <= 100; ++y) {
            for (int s = 0; s <= 10; ++s) {
                total[x][y][s] += total[x][y - 1][s] + total[x - 1][y][s] - total[x - 1][y - 1][s];
            }
        }
    }
}

int main() {
    int n, q, c;
    scanf("%d %d %d", &n, &q, &c);

    int x, y, s;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &x, &y, &s);
        total[x][y][s]++;
    }

    init();
    int t, x1, y1, x2, y2;

    int bright;
    for (int i = 0; i < q; ++i) {
        int ans = 0;
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        for (s = 0; s <= c; ++s) {
            bright = (t + s) % (c + 1);
            if ((t + s) % (c + 1) != 0)
                ans += bright * (total[x2][y2][s] - total[x1 - 1][y2][s] - total[x2][y1 - 1][s] + total[x1 - 1][y1 - 1][s]);
        }
        printf("%d\n", ans);

    }
    return 0;
}