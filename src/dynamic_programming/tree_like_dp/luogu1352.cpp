//
// Created by Jiang Yinzuo on 2020/3/21.
//

#include <cstdio>

struct Edge {
    static int head[6009];
    static int edge_idx;
    int child;
    int next;

    static void add_edge(int parent, int child);
} edges[6009];

int Edge::edge_idx = 0;
int Edge::head[6009] = {0};

void Edge::add_edge(int parent, int child) {
    edges[++edge_idx] = {child, head[parent]};
    head[parent] = edge_idx;
}

int vertex[6009];

int f[6009][2] = {0};

inline int max(int a, int b) {
    return a > b ? a : b;
}

void tree_dp(int cur_idx) {
    if (Edge::head[cur_idx] == 0) {
        f[cur_idx][1] = vertex[cur_idx];
        return;
    }
    for (int i = Edge::head[cur_idx]; i != 0; i = edges[i].next) {
        tree_dp(edges[i].child);
    }

    f[cur_idx][1] = vertex[cur_idx];
    for (int i = Edge::head[cur_idx]; i != 0; i = edges[i].next) {
        f[cur_idx][1] += f[edges[i].child][0];
        f[cur_idx][0] += max(f[edges[i].child][0], f[edges[i].child][1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vertex[i]);
    }

    int child, parent;
    int root = (1 + n) * n / 2;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &child, &parent);
        Edge::add_edge(parent, child);
        root -= child;
    }
    tree_dp(root);
    printf("%d\n", max(f[root][0], f[root][1]));
    return 0;
}