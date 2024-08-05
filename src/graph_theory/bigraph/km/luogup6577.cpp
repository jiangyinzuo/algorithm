//
// Created by Jiang Yinzuo on 2020/9/28.
//

#include <cstdio>
#include <cstring>

class KM {

#define MAX_N 605
#define INF 0x3f3f3f3f

public:
    static long long graph[MAX_N][MAX_N]; // 边权邻接矩阵
private:
    static long long lx[MAX_N], ly[MAX_N], slack[MAX_N], pre[MAX_N];
    static int linker[MAX_N]; // linker[i]：与右边第i个点相匹配的左边的点
    static bool vis_y[MAX_N]; // 标记右边点集是否被访问过

    static void bfs(int k, int n);

public:
    static long long solve(int n);

    static void print_linker(int n) {
        for (int i = 1; i <= n - 1; ++i) {
            printf("%d ", KM::linker[i]);
        }
        printf("%d\n", KM::linker[n]);
    }
};

long long KM::graph[MAX_N][MAX_N]; // 边权邻接矩阵
long long  KM::lx[MAX_N], KM::ly[MAX_N], KM::slack[MAX_N], KM::pre[MAX_N];
bool KM::vis_y[MAX_N];
int KM::linker[MAX_N];

void KM::bfs(int k, int n) {
    long long x, y = 0, yy = 0, delta;
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) slack[i] = INF;
    linker[y] = k;
    while (true) {
        x = linker[y];
        delta = INF;
        vis_y[y] = true;
        for (int i = 1; i <= n; i++) {
            if (!vis_y[i]) {
                if (slack[i] > lx[x] + ly[i] - graph[x][i]) {
                    slack[i] = lx[x] + ly[i] - graph[x][i];
                    pre[i] = y;
                }
                if (slack[i] < delta) delta = slack[i], yy = i;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (vis_y[i]) lx[linker[i]] -= delta, ly[i] += delta;
            else slack[i] -= delta;
        }
        y = yy;
        if (linker[y] == -1) break;
    }
    while (y) linker[y] = linker[pre[y]], y = pre[y];
}

long long KM::solve(int n) {
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(linker, -1, sizeof(linker));
    for (int i = 1; i <= n; i++) {
        memset(vis_y, false, sizeof(vis_y));
        bfs(i, n);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (linker[i] != -1) {
            res += graph[linker[i]][i];
        }
    }
    return res;
}

int main() {
    int n;
    static long long m, x, y, weight;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            KM::graph[i][j] = -INF;
    for (int i = 0; i < m; ++i) {
        scanf("%lld %lld %lld", &x, &y, &weight);
        KM::graph[x][y] = weight;
    }

    printf("%lld\n", KM::solve(n));
    KM::print_linker(n);
    return 0;
}