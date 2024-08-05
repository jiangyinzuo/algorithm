//
// Created by Jiang Yinzuo on 2020/8/11.
//

#include <iostream>
#include <vector>
#include <cassert>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int x = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            x ^= a[i];
        }
        if (x == 0) {
            std::cout << "DRAW" << '\n';
            continue;
        }
        int bit = 30;
        while (!(x & (1 << bit))) {
            --bit;
        }
        int k0 = 0, k1 = 0;
        for (int y : a) {
            if (y & (1 << bit)) {
                k1 += 1;
            } else {
                k0 += 1;
            }
        }
        assert(k1 % 2 == 1);
        if (k0 % 2 == 0 && k1 % 4 == 3) {
            std::cout << "LOSE" << '\n';
        } else {
            std::cout << "WIN" << '\n';
        }
    }
    return 0;
}