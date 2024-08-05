#include <cstdio>
#include <cstring>

const int MAX_N = 201;

bool graph[MAX_N][MAX_N];
int color[MAX_N];

bool is_ok(int i, int c, int n) {
    for (int j = 1; j <= n; ++j) {
        if (graph[i][j] && c == color[j])
            return false;
    }
    return true;
}

int solve(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int c = 1; c <= n; ++c) {
            if (is_ok(i, c, n)) {
                color[i] = c;
                if (ans < c)ans = c;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int u, v;
        memset(graph, false, sizeof(graph));
        memset(color, 0, sizeof(color));
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = true;
        }
        printf("%d\n", m == 0 ? 0 : solve(n));
    }
    return 0;
}