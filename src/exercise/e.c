//
// Created by Jiang Yinzuo on 2020/4/12.
//

#include <stdio.h>

const int MAX_N = 200008;
int raw_graph[200008];
int c[200008];
int visited[200008] = {0};

int n;
int total_cost = 0;

void dfs(int cur, int turn) {
    while (1) {
        visited[cur] = turn;

        cur = raw_graph[cur];
        if (visited[cur] && visited[cur] != turn) break;
        // find circle
        if (visited[cur]) {
            int min_cost = c[cur];
            for (int i = raw_graph[cur]; i != cur; i = raw_graph[i]) {
                min_cost = min_cost < c[i] ? min_cost : c[i];
            }
            total_cost += min_cost;
            break;
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!visited[raw_graph[i]]) {
            if (!visited[i]) {
                dfs(i, i);
            }
        } else {
            visited[i] = 1;
        }
    }
    printf("%d\n", total_cost);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &raw_graph[i]);
    }
    solve();
    return 0;
}
