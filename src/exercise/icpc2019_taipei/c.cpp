//
// Created by Jiang Yinzuo on 2020/12/10.
//

#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            if (i == j) continue;
            for (int k = 0; k < vec.size(); ++k) {
                if (i == k || j == k) continue;
                if (std::abs(vec[i] - vec[j]) % vec[k] != 0) {
                    puts("no");
                    return 0;
                }
            }
        }
    }
    puts("yes");
    return 0;
}