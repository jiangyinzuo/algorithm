#include <cstdio>
#include <cstring>

const int MAX_N = 201;

bool graph[MAX_N][MAX_N];

int color[MAX_N];

int n, m;

bool is_ok(int cur_v, int c) {
    for (int i = 1; i <= n; ++i) {
        if (graph[i][cur_v] && color[i] == c) return false;
    }
    return true;
}

bool m_coloring(const int m_color, int cur_v) {
    for (int c = 1; c <= m_color; ++c) {
        if (is_ok(cur_v, c)) {
            color[cur_v] = c;
            bool flag = true;
            for (int i = 1; i <= n; ++i) {
                if (graph[i][cur_v] && color[i] == 0 && !m_coloring(m_color, i)) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
    }
    return false;
}

int solve() {
    int lower = 1, upper = n;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        memset(color, 0, sizeof(color));
        bool flag = true;
        for (int i = 1; i <= m; ++i) {
            if (!color[i] && !m_coloring(mid, i)) {
                lower = mid + 1;
                flag = false;
                break;
            }
        }
        if (flag)upper = mid;
    }
    return lower;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        int u, v;
        memset(graph, false, sizeof(graph));
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = true;
        }
        printf("%d\n", m == 0 ? 0 : solve());
    }
    return 0;
}
