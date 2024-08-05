//
// Created by Jiang Yinzuo on 2020/3/21.
//
#include <iostream>
#include <vector>

int main() {
    long long u, v;
    std::cin >> u >> v;

    if (u == v) {
        if (u == 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl << u << std::endl;
        }
        return 0;
    }
    if (v < u || (v - u) & 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<long long> arr;

    long long remain = (v - u) / 2;
    if ((u ^ remain) == u + remain) {
        arr.push_back(u + remain);
        arr.push_back(remain);
    } else {
        arr.push_back(u);
        arr.push_back(remain);
        arr.push_back(remain);
    }
    std::cout << arr.size() << std::endl;
    std::cout << arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    return 0;
}
