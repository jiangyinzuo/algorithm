//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>
#include <cstring>

bool peak[3][40006];

int main() {
    int p, e, i, d;
    int kase = 1;

    while (scanf("%d%d%d%d", &p, &e, &i, &d) != EOF && p >= 0 && e >= 0 && i >= 0 && d >= 0) {
        memset(peak, false, sizeof(peak));
        p = p % 23;
        e = e % 28;
        i = i % 33;
        for (int x = p; x < 40006; x += 23)
            peak[0][x] = true;
        for (int x = e; x < 40006; x += 28)
            peak[1][x] = true;
        for (int x = i; x < 40006; x += 33)
            peak[2][x] = true;

        for (int x = d + 1; x < 40006; x++) {
            if (peak[0][x] && peak[1][x] && peak[2][x]) {
                printf("Case %d: the next triple peak occurs in %d days.\n", kase++, x - d);
                break;
            }
        }
    }
    return 0;
}