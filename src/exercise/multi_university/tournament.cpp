//
// Created by Jiang Yinzuo on 2020/8/10.
//

#include <cstdio>

void solve(int n) {
    for (int i = 1; i <= n - 1; i += 2) {
        printf("%d %d\n", i, i + 1);
        for (int j = i + 2; j <= n; ++j) {
            printf("%d %d\n", i + 1, j);
            printf("%d %d\n", i, j);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}