//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>
#include <algorithm>

int left[104], right[104];

int main() {
    int t, l, r;
    scanf("%d", &t);
    while (t--) {
        int n, x, m;
        scanf("%d %d %d", &n, &x, &m);
        bool flag = false;
        int idx = -1;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &left[i], &right[i]);
            if (!flag && left[i] <= x && x <= right[i]) {
                idx = i;
                flag = true;
            }
        }
        if (idx == -1) {
            printf("1\n");
            continue;
        }
        l = left[idx];
        r = right[idx];
        for (int i = idx + 1; i < m; ++i) {
            if (right[i] < l || r < left[i]) continue;
            l = std::min(l, left[i]);
            r = std::max(r, right[i]);
        }
        printf("%d\n", r - l + 1);
    }
    return 0;
}
