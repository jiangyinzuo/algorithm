//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>
#include <vector>

std::vector<int> tree[2000009];

struct Edge {
    int u, v;
} edges[2000009];

int size[2000009];
int answer = 0;
int n, k;
void dfs(int u, int father) {
    size[u] = 1;
    for (auto &i : tree[u]) {
        if (i != father) {
            dfs(i, u);
            size[u] += size[i];
        }
    }
    if (size[u] >= k && n - size[u] >= k) answer++;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
            size[i] = 0;
        }
        answer = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d", &edges[i].u, &edges[i].v);
            tree[edges[i].u].push_back(edges[i].v);
            tree[edges[i].v].push_back(edges[i].u);
        }
        if (k * 2 > n) {
            printf("0\n");
        } else {
            dfs(1, 0);
            printf("%d\n", answer);
        }
    }
    return 0;
}
