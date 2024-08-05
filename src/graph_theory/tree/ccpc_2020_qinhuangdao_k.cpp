#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<int> sons[1000006];

long long ans = 0;
int height[1000006];

void get_height(int cur, int depth) {
    if (sons[cur].empty()) {
        height[cur] = 0;
        return;
    }
    int h = 0;
    for (auto &i : sons[cur]) {
        get_height(i, depth + 1);
        h = std::max(h, height[i]);
    }
    height[cur] = h + 1;
}

int dfs(int cur, int depth, int dis) {
    if (sons[cur].empty()) {
        ans += dis;
        return 1;
    }
    std::sort(sons[cur].begin(), sons[cur].end(), [](int s1, int s2){return height[s1] < height[s2];});
    for (auto &i : sons[cur]) {
        dis = std::min(depth, dfs(i, depth + 1, dis + 1));
    }
    return dis + 1;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int n, v;
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; ++i) sons[i].clear();
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &v);
            sons[v].push_back(i);
        }
        get_height(1, 0);
        dfs(1, 0, 0);
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}