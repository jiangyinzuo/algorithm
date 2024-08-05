//
// Created by Jiang Yinzuo on 2020/4/29.
//

#include <cstdio>
#include <set>

std::set<int> children[16003];
int beauty[16003];
int dp[16003] = {0};

static void dfs(int cur_node, int father) {
    for (auto &i : children[cur_node]) {
        if (dp[i] == 0 && i != father) {
            dfs(i, cur_node);
        }
    }

    dp[cur_node] = beauty[cur_node];
    for (auto &i : children[cur_node]) {
        if (dp[i] > 0) {
            dp[cur_node] += dp[i];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &beauty[i]);
    }

    int v1, v2;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &v1, &v2);
        children[v1].insert(v2);
        children[v2].insert(v1);
    }

    dfs(1, 0);
    int ans = -2147483647;
    for (int i = 1; i <= n; ++i) {
        ans = dp[i] > ans ? dp[i] : ans;
    }
    printf("%d\n", ans);
    return 0;
}