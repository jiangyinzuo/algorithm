// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <cstdio>
#include <algorithm>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int res = 32;
        int start_times = 0;
        if (b == 1) {
            ++b;
            ++start_times;
        }
        for (int op = 0; op < res; ++op) {
            int times = start_times + op;
            int _b = b + op;
            int _a = a;
            while (_a) {
                _a /= _b;
                ++times;
            }
            res = std::min(res, times);
        }
        printf("%d\n", res);
    }
    return 0;
}