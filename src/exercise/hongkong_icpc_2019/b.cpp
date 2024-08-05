//
// Created by Jiang Yinzuo on 2020/12/3.
//

#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i) scanf("%*d%*d");
        puts(n & 1 ? "Alice" : "Bob");
    }
    return 0;
}