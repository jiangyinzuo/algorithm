#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int N = 200001;
std::vector<int> tree[N];
int sizes[N];
long long sizes_sum[N];

void calc_size(int cur_v, int parent) {
    sizes_sum[cur_v] = 0;
    sizes[cur_v] = 1;
    for (auto u : tree[cur_v]) {
        if (u != parent) {
            calc_size(u, cur_v);
            sizes[cur_v] += sizes[u];
            sizes_sum[cur_v] += sizes_sum[u];
        }
    }
    sizes_sum[cur_v] += sizes[cur_v];
}

static long long dp[N] = {0};
int n;
void dfs(int cur_v, int parent) {
    if (tree[cur_v].size() == 1 && parent > 0) {
        dp[cur_v] = n;
        return;
    }

    for (auto u : tree[cur_v]) {
        if (u != parent) {
            dfs(u, cur_v);
            dp[cur_v] = std::max(dp[cur_v], n - sizes[u] + dp[u] + sizes_sum[cur_v] - sizes_sum[u] - sizes[cur_v]);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    calc_size(1, -1);
    dfs(1, -1);
    printf("%lld\n", std::max(dp[1], sizes_sum[1]));
    return 0;
}
