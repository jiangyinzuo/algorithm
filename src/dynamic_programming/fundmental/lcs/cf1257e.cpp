//
// Created by Jiang Yinzuo on 2020/12/8.
//

#include <algorithm>
#include <cstdio>
#include <vector>

void input_arr(int k, int id, std::vector<int> &problem) {
    int pid;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &pid);
        problem[pid - 1] = id;
    }
}

std::vector<int> get_lcs(const std::vector<int> &vec) {
    std::vector<int> lcs;
    decltype(lcs.begin()) place;
    for (auto &e : vec) {
        if ((place = std::upper_bound(lcs.begin(), lcs.end(), e)) == lcs.end())
            lcs.push_back(e);
        else
            *place = e;
    }
    return lcs;
}

int main() {
    int k1, k2, k3;
    scanf("%d %d %d", &k1, &k2, &k3);
    std::vector<int> problem(k1 + k2 + k3);
    input_arr(k1, 0, problem);
    input_arr(k2, 1, problem);
    input_arr(k3, 2, problem);

    auto vec = get_lcs(problem);
    printf("%d\n", k1 + k2 + k3 - vec.size());
    return 0;
}