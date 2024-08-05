//
// Created by Jiang Yinzuo on 2020/3/21.
//

#include <cstdio>
#include <utility>

std::pair<int, int> p[100009];
int degree[100009] = {0};

int main() {
    int n;
    scanf("%d", &n);

    int parent, child;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &parent, &child);
        p[i] = {parent, child};
        degree[parent]++;
        degree[child]++;
    }

    int max_degree = 0;
    int max_degree_node = -1;
    for (int i = 1; i <= n; ++i) {
        if (max_degree < degree[i]) {
            max_degree =  degree[i];
            max_degree_node = i;
        }
    }
    if (max_degree <= 2) {
        for (int i = 0; i < n - 1; ++i) {
            printf("%d\n", i);
        }
    } else {
        int output1 = 3;
        int output2 = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (output2 < 3 && (p[i].first == max_degree_node || p[i].second == max_degree_node)) {
                printf("%d\n", output2++);
            } else {
                printf("%d\n", output1++);
            }
        }
    }
    return 0;
}