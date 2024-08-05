//
// Created by Jiang Yinzuo on 2020/4/29.
//

#include <stdio.h>

#define MAX_N 100

int weights[MAX_N];
int father[MAX_N];
int children[MAX_N][MAX_N];
int child_count[MAX_N] = {0};

int dp[MAX_N] = {0};

int max(int a, int b) {
    return a > b ? a : b;
}

void dfs(int cur_node) {
    if (child_count[cur_node] == 0) {
        return;
    }

    for (int i = 0; i < child_count[cur_node]; ++i) {
        dfs(children[cur_node][i]);
    }

    // dp[cur_node] = sum(dp[child]) + max(max(weights[child] - dp[child]), 0)
    int max_add = 0;
    for (int i = 0; i < child_count[cur_node]; ++i) {
        dp[cur_node] += dp[children[cur_node][i]];
        max_add = max(max_add, weights[children[cur_node][i]] - dp[children[cur_node][i]]);
    }
    dp[cur_node] += max_add;
}

int main() {
    // 节点个数
    int n;
    scanf("%d", &n);

    int temp_father, child, weight;
    for (int i = 0; i < n - 1; ++i) {
        // 父节点 子节点 权重（均大于0）
        scanf("%d %d %d", &temp_father, &child, &weight);
        father[child] = temp_father;
        children[temp_father][child_count[temp_father]++] = child;
        weights[child] = weight;
    }

    dfs(1);
    printf("%d\n", dp[1]);
    return 0;
}