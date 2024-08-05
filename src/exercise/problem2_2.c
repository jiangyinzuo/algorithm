//
// Created by Jiang Yinzuo on 2020/4/30.
//

#include <stdio.h>

#define MAX_N 100

int weights[MAX_N];
int father[MAX_N];
int children[MAX_N][MAX_N];
int child_count[MAX_N] = {0};

// dp[i][0]: 没选该节点和它子节点之间的边；dp[i][1]: 选了
int dp[MAX_N][2] = {0};

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

    int sum = 0;
    for (int i = 0; i < child_count[cur_node]; ++i) {
        sum += max(dp[children[cur_node][i]][0], dp[children[cur_node][i]][1]);
    }
    for (int i = 0; i < child_count[cur_node]; ++i) {
        dp[cur_node][0] += max(dp[children[cur_node][i]][0], dp[children[cur_node][i]][1]);
        dp[cur_node][1] = max(dp[cur_node][1], dp[children[cur_node][i]][0] + weights[children[cur_node][i]] + sum - max(dp[children[cur_node][i]][0], dp[children[cur_node][i]][1]));
    }
}

int main() {
    // 节点个数
    int n;
    scanf("%d", &n);

    int temp_father, child, weight;
    for (int i = 0; i < n - 1; ++i) {
        // 父节点 子节点 权重
        scanf("%d %d %d", &temp_father, &child, &weight);
        father[child] = temp_father;
        children[temp_father][child_count[temp_father]++] = child;
        weights[child] = weight;
    }

    dfs(1);
    printf("%d\n", max(dp[1][1], dp[1][0]));
    return 0;
}
/*
13
1 2 150
1 3 20
1 4 30
1 5 45
2 6 45
2 7 30
3 8 70
4 9 60
4 10 40
4 11 90
8 12 40
8 13 100

*/