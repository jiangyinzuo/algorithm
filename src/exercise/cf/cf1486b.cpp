// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::vector<long long> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> x[i] >> y[i];
        }
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        std::cout << (x[n / 2] - x[(n-1)/2] +1) *(y[n / 2] - y[(n-1)/2] +1) << '\n';
    }
    return 0;
}