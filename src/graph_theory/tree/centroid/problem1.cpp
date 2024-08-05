//
// Created by Jiang Yinzuo on 2020/12/11.
//

#include <cstdio>
#include <vector>

constexpr int MaxN = 2001;

std::vector<int> tree[MaxN];
std::vector<std::pair<int, int>> edges;

int ans;
void dfs(int cur_v, int father, int depth, const int max_depth) {
    if (depth > max_depth) {
        return;
    }
    --ans;
    for (auto i : tree[cur_v]) {
        if (i != father) {
            dfs(i, cur_v, depth + 1, max_depth);
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
        (void)edges.emplace_back(u, v);
    }

    int min_ans = n;
    if (k % 2 == 0) {
        for (int i = 1; i <= n; ++i) {
            ans = n;
            dfs(i, 0, 0, k / 2);
            min_ans = min_ans < ans ? min_ans : ans;
        }
    } else {
        for (auto &p : edges) {
            ans = n;
            dfs(p.first, p.second, 0, k / 2);
            dfs(p.second, p.first, 0, k / 2);
            min_ans = min_ans < ans ? min_ans : ans;
        }
    }

    printf("%d\n", min_ans);
    return 0;
}