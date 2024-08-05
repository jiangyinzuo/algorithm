//
// Created by Jiang Yinzuo on 2020/7/28.
//

#include <cstdio>
#include <algorithm>

struct Cake {
    int w, d;
    bool operator < (Cake &c) const  {
        return w * d < c.w * c.d;
    }
} cakes[111], c1, c2;

int main() {
    int n, w, d;
    while (scanf("%d%d%d", &n, &w, &d) && (n + w + d)) {
        cakes[1].w = w;
        cakes[1].d = d;
        int p, s, idx = 2;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p, &s);
            c2 = cakes[p];
            for (int j = p + 1; j < idx; j++) {
                cakes[j - 1] = cakes[j];
            }
            idx--;
            s %= 2 * (c2.d + c2.w);
            if (s < c2.w || (s > c2.w + c2.d && s < 2 * c2.w + c2.d)) {
                if (s > c2.w) {
                    s = 2 * c2.w + c2.d - s;
                }
                c1.w = c2.w - s;
                c2.w = s;
                c1.d = c2.d;
                if (c1.w < c2.w) {
                    std::swap(c1, c2);
                }
            } else {
                if (s < c2.w + c2.d) {
                    s -= c2.w;
                } else {
                    s = 2 * (c2.w + c2.d) - s;
                }
                c1.w = c2.w;
                c1.d = c2.d - s;
                c2.d = s;
                if (c1.d < c2.d) {
                    std::swap(c1, c2);
                }
            }
            cakes[idx++] = c2;
            cakes[idx++] = c1;
        }
        std::sort(cakes + 1, cakes + idx);
        printf("%d", cakes[1].w * cakes[1].d);
        for (int i = 2; i < idx; i++) {
            printf(" %d", cakes[i].w * cakes[i].d);
        }
        printf("\n");
    }
    return 0;
}