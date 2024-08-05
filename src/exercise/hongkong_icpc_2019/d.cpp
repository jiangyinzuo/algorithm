//
// Created by Jiang Yinzuo on 2020/12/3.
//
#include <cstdio>
#include <deque>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int base, x;
        scanf("%d %d", &base, &x);
        --x;
        std::deque<int> num;
        while (x) {
            num.push_back(x % base);
            x /= base;
        }
        while (!num.empty()) {
            printf("%d", num.back() + 10 - base);
            num.pop_back();
        }
        puts("");
    }
    return 0;
}