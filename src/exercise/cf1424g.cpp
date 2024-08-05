//
// Created by Jiang Yinzuo on 2020/12/9.
//

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>

constexpr int MaxN = 100000;

static std::array<int, MaxN> birth{}, death{};

int main() {
    int n, cur_people = 0, max_year = 0, max_people = 0, next_d_idx = 0;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> birth[i] >> death[i];
    std::sort(birth.begin(), &birth[n]);
    std::sort(death.begin(), &death[n]);

    for (int i = 0; i < n; ++i) {
        while (birth[i] >= death[next_d_idx]) {
            ++next_d_idx;
            --cur_people;
        }
        assert(cur_people >= 0);
        ++cur_people;
        if (cur_people > max_people) {
            max_year = birth[i];
            max_people = cur_people;
        }
    }
    std::cout << max_year << ' ' << max_people << std::endl;
    return 0;
}