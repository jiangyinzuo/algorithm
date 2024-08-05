//
// Created by jiang on 2020/8/15.
// https://nanti.jisuanke.com/t/42552

#include <cstdio>
#include <vector>

#define MAXN 200001
std::vector<int> tree[MAXN];

/**
 * fathers: 每个节点的父亲
 * depth： 每个节点的深度
 * centroids: 每个子树深度较深的重心
 * size: 每个子树的节点数量
 */
int fathers[MAXN], depth[MAXN], centroids[MAXN], size[MAXN];

/**
 * 合并两棵子树的重心时，新的重心一定在子树重心的连线上
 * @param cur_v 合并后的根节点
 * @param c1 子树1的重心
 * @param c2 子树2的重心
 */
void merge(int cur_v, int c1, int c2) {
    while (depth[c1] > depth[cur_v] && size[c1] < size[cur_v] - size[c1])
        c1 = fathers[c1];
    while (depth[c2] > depth[cur_v] && size[c2] < size[cur_v] - size[c2])
        c2 = fathers[c2];
    centroids[cur_v] = depth[c1] > depth[c2] ? c1 : c2;
}

void dfs(int cur_v) {
    size[cur_v] = 1;
    centroids[cur_v] = cur_v;
    for (auto &i : tree[cur_v]) {
        if (i != fathers[cur_v]) {
            fathers[i] = cur_v;
            depth[i] = depth[cur_v] + 1;
            dfs(i);
            size[cur_v] += size[i];
            merge(cur_v, centroids[cur_v], centroids[i]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fathers[1] = 0;
    depth[1] = 1;
    dfs(1);

    // 一棵树最多2个重心
    for (int i = 1; i <= n; ++i) {
        if (fathers[centroids[i]] && size[centroids[i]] * 2 == size[i]) {
            if (centroids[i] < fathers[centroids[i]])
                printf("%d %d\n", centroids[i], fathers[centroids[i]]);
            else
                printf("%d %d\n", fathers[centroids[i]], centroids[i]);
        } else {
            printf("%d\n", centroids[i]);
        }
    }
    return 0;
}