//
// Created by Jiang Yinzuo on 2020/5/16.
//

#include <cstdio>
#include <map>
#include <vector>

std::map<int, std::vector<int>> num_map;
std::vector<int> result1, result2, result3;

int father[200009];

int find_father(int n) {
    if (father[n] == n) {
        return n;
    }
    return father[n] = find_father(father[n]);
}

void merge(int a, int b) {
    int fa = find_father(a);
    int fb = find_father(b);
    if (fa > fb) father[fa] = fb;
    else father[fb] = fa;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) father[i] = i;

    int cnt;
    int num;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            scanf("%d", &num);
            num_map[num].push_back(i);
        }
    }

    int first_person;
    for (auto &nums : num_map) {
        if (nums.second.size() >= 2) {
            first_person = *nums.second.begin();
            for (const auto &p : nums.second) {
                if (p != first_person && find_father(first_person) != find_father(p)) {
                    merge(first_person, p);
                    result1.push_back(first_person);
                    result2.push_back(p);
                    result3.push_back(nums.first);

                }
            }
        }
    }

    if (result1.size() == n - 1) {
        for (int i = 0; i < n - 1; ++i) {
            printf("%d %d %d\n", result1[i], result2[i], result3[i]);
        }
        return 0;
    }
    printf("impossible\n");

    return 0;
}