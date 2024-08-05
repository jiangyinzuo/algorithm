//
// Created by Jiang Yinzuo on 2020/11/30.
//

#include <cstdio>
#include <unordered_map>
#include <vector>

static int arr[200000];

int get_longest_interval_sum0(int maxv, int v, int n) {
    int cur_sum = 0, ans = 0;
    std::vector<int> pos(n + 1), neg(n + 1);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == v) {
            ++cur_sum;
        } else if (arr[i] == maxv) {
            --cur_sum;
        }
        if (cur_sum == 0) {
            ans = i + 1;
        } else if (cur_sum > 0) {
            if (pos[cur_sum]) {
                ans = std::max(ans, i + 2 - pos[cur_sum]);
            } else {
                pos[cur_sum] = i + 1;
            }
        } else {
            if (neg[-cur_sum]) {
                ans = std::max(ans, i + 1 - neg[-cur_sum]);
            } else {
                neg[-cur_sum] = i + 1;
            }
        }
    }
    return ans;
}

int main() {
    std::unordered_map<int, int> map;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        ++map[arr[i]];
    }

    int maxv = -1, max_cnt = 0, max_key = -1;
    for (auto &i : map) {
        if (i.second > maxv) {
            max_cnt = 1;
            max_key = i.first;
            maxv = i.second;
        } else if (i.second == maxv) ++max_cnt;
    }
    if (max_cnt >= 2) printf("%d\n", n);
    else {
        int answer = 0;
        for (int i = 1; i <= 100; ++i) {
            if (i == max_key) continue;
            answer = std::max(answer, get_longest_interval_sum0(max_key, i, n));
        }
        printf("%d\n", answer);
    }
    return 0;
}
