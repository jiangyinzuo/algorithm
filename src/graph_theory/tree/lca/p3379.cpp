//
// Created by Jiang Yinzuo on 2020/10/28.
// Tarjan Algorithm O(n + m)

#include <cstdio>
#include <vector>

constexpr int MAX_N = 500000;
constexpr int MAX_M = 500000;
std::vector<int> tree[MAX_N + 1];
/// queries[x] = {y, id}
std::vector<std::pair<int, int> > queries[MAX_N];

///// Union Find /////
int father[MAX_N + 1];

int get_father(int v) {
    return father[v] == v ? v : father[v] = get_father(father[v]);
}

int answer[MAX_M + 1];

void tarjan(int cur_v) {
    static int tag[MAX_N + 1] = {0};
    tag[cur_v] = 1;
    for (auto i : tree[cur_v]) {
        if (tag[i] == 0) {
            tarjan(i);
            father[i] = cur_v; // merge child vertex to self
        }
    }
    for (auto &q : queries[cur_v]) {
        int y = q.first, id = q.second;
        if (tag[y] == 2) answer[id] = get_father(y);
    }
    tag[cur_v] = 2;
}

int main() {
    int n, m, root;
    scanf("%d %d %d", &n, &m, &root);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        queries[a].emplace_back(b, i);
        queries[b].emplace_back(a, i);
    }

    for (int i = 0; i <= n; ++i) father[i] = i;

    tarjan(root);
    for (int i = 0; i < m; ++i) printf("%d\n", answer[i]);
    return 0;
}