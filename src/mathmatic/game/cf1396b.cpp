//
// Created by Jiang Yinzuo on 2020/10/17.
//

#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cur, sum = 0, max_v = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &cur);
            sum += cur;
            max_v = max_v > cur ? max_v : cur;
        }
        if (max_v * 2 > sum) puts("T");
        else if (sum % 2 == 0) puts("HL");
        else puts("T");
    }
    return 0;
}