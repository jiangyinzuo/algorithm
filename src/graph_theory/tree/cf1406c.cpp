//
// Created by jiang on 2020/9/17.
// 求树的重心

#include <cstdio>
#include <vector>

std::vector<int> tree[200001];
int size[200001];
int max_size[200001];
int n;
std::vector<int> centroids;
int min_max_size;

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
    if (min_max_size >= max_size[cur_v]) {
        if (min_max_size > max_size[cur_v]) centroids.clear();
        centroids.push_back(cur_v);
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
        if (centroids.size() == 1) {
            printf("%d %d\n", tree[1][0], 1);
            printf("%d %d\n", tree[1][0], 1);
        } else {
            int c1 = centroids[0], c2 = centroids[1];
            int child, cur = c1, father = c2;
            while (tree[cur].size() > 1) {
                for (int i = 0; (child = tree[cur][i]) == father; ++i);
                father = cur;
                cur = child;
            }
            printf("%d %d\n", cur, father);
            printf("%d %d\n", cur, c2);
        }
    }
    return 0;
}