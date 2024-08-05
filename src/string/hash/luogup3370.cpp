//
// Created by jiang on 2020/8/14.
//

#include <iostream>
#include <string>
#include <hash_fun.h>
#include <unordered_set>

int main() {
    std::string s;
    int n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::unordered_set<std::string> h_set;
    while (n--) {
        std::cin >> s;
        h_set.insert(s);
    }
    __gnu_cxx::__stl_hash_string(s.c_str());
    std::cout << h_set.size() << std::endl;

    return 0;
}