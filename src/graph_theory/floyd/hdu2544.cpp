//
// Created by Jiang Yinzuo on 2020/7/18.
// hdu2544

#include <cstdio>
#include <algorithm>

const int INF = 0x3f3f3f3f;
int graph[100][100];

void floyd(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m) && n && m) {
        int u, v, w;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = INF;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            graph[u][v] = graph[v][u] = w;
        }
        floyd(n);
        printf("%d\n", graph[1][n]);
    }

    return 0;
}