//
// Created by Jiang Yinzuo on 2020/5/30.
//

#include <iostream>

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;

    if (c % 2 == 1) {
        std::cout << "Take another envelope" << std::endl;
        return 0;
    }

    if ( a / 2 <= c && c <= b)
        std::cout << "Take another envelope" << std::endl;
    else
        std::cout << "Stay with this envelope" << std::endl;
    return 0;
}