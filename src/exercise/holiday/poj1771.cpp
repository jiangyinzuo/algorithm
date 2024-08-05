//
// Created by 江胤佐-2018112664 on 2020/7/3.
//

#include <cstdio>
#include <algorithm>
#include <vector>

int floor[39];
int n;
std::vector<int> stop_layer;

bool is_ok(int total) {
    std::vector<int> temp_layer;
    int stop_cnt = 0;
    int layer = 1;
    for (int i = 0; i < n; ++i) {
        if (layer >= floor[i] ||
            std::max(0, stop_cnt - 1) * 10 + (layer - 1) * 4 + (floor[i] - layer) * 20 <= total)
            continue;
        if (stop_cnt * 10 + (floor[i] - 1) * 4 > total) return false;
        layer = (total - stop_cnt * 10 + 4 + floor[i] * 20) / 24;
        stop_cnt++;
        temp_layer.push_back(layer);
    }
    stop_layer.assign(temp_layer.begin(), temp_layer.end());
    return true;
}

int b_search(int max_time) {
    int min_time = 0;
    while (min_time < max_time) {
        int mid_time = (min_time + max_time) / 2;
        if (is_ok(mid_time))
            max_time = mid_time;
        else
            min_time = mid_time + 1;
    }
    return min_time;
}

int main() {
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", floor + i);
        printf("%d\n", b_search(floor[n - 1] * 20));
        printf("%d", stop_layer.size());
        for (int i = 0; i < stop_layer.size(); ++i)
            printf(" %d", stop_layer[i]);
        printf("\n");
    }
    return 0;
}
