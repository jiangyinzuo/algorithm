//
// Created by jiang on 2020/8/15.
// poj1655

#include <cstdio>
#include <vector>

std::vector<int> tree[200001];
int size[200001];
int max_size[200001];
int n;
int centroid, min_max_size;

void dfs(int cur_v, int father) {
    size[cur_v] = max_size[cur_v] = 1;
    for (auto &i : tree[cur_v]) {
        if (i != father) {
            dfs(i, cur_v);
            size[cur_v] += size[i];
            max_size[cur_v] = std::max(max_size[cur_v], size[i]);
        }
    }
    max_size[cur_v] = std::max(max_size[cur_v], n - size[cur_v]);
    if (min_max_size > max_size[cur_v]) {
        centroid = cur_v;
        min_max_size = max_size[cur_v];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int u, v;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) tree[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        min_max_size = 0x7fffffff;
        dfs(1, 0);
        printf("%d %d\n", centroid, min_max_size);
    }
    return 0;
}