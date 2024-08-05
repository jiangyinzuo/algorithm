#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX_V_NUM 200
#define MAX_E_NUM 5000

const int INF = 0x3fffffff;
int edge_idx = 1, start_head[MAX_V_NUM + 4];

/* 2、3是一对反向边；4、5是一对反向边... */
struct Edge {
    int to, next, remain_capacity;
    static int head[MAX_V_NUM + 4];
} edges[MAX_E_NUM * 2 + 4];

int Edge::head[MAX_V_NUM + 4] = {0};

int depth[MAX_V_NUM + 4];

/**
 * 添加双向边
 * @param u 起点
 * @param v 终点
 * @param w 边权
 */
static void add_edges(int u, int v, int w) {
    edges[++edge_idx] = {v, Edge::head[u], w};
    Edge::head[u] = edge_idx;

    edges[++edge_idx] = {u, Edge::head[v], 0};
    Edge::head[v] = edge_idx;
}


/* 在残量网络中构造分层图 */
bool bfs(int source, int n, int target) {
    for (int i = 1; i <= n; i++) depth[i] = INF;
    std::queue<int> q;
    q.push(source);
    depth[source] = 0;
    start_head[source] = Edge::head[source];
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = Edge::head[x]; i; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[i].remain_capacity > 0 && depth[v] == INF) {
                q.push(v);
                start_head[v] = Edge::head[v];
                depth[v] = depth[x] + 1;
                if (v == target) return true;
            }
        }
    }
    return false;
}

/**
 * 只对下一层级的点进行dfs
 * @param cur_v 当前所在的点
 * @param cur_min_flow 增广路上最小的边权(剩余容量)
 * @return 经过cur_v流出的总容量
 */
int dfs(int cur_v, int cur_min_flow, const int target) {
    if (cur_v == target) return cur_min_flow;
    // min_flow是当前最小的剩余容量
    int min_flow, result = 0;
    for (int i = start_head[cur_v]; i && cur_min_flow > 0; i = edges[i].next) {
        // 当前弧优化
        start_head[cur_v] = i;
        int next_v = edges[i].to;
        if (edges[i].remain_capacity > 0 && (depth[next_v] == depth[cur_v] + 1)) {
            min_flow = dfs(next_v, std::min(cur_min_flow, edges[i].remain_capacity), target);
            // 剪枝，去掉增广完毕的点
            if (min_flow == 0) depth[next_v] = INF;
            edges[i].remain_capacity -= min_flow;
            edges[i ^ 1].remain_capacity += min_flow;
            result += min_flow;
            cur_min_flow -= min_flow;
        }
    }
    return result;
}


int main() {
    int n, m, source, target;
    scanf("%d %d %d %d", &n, &m, &source, &target);
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edges(u, v, w);
    }

    long long ans = 0;
    while (bfs(source, n, target)) {
        ans += dfs(source, INF, target);
    }
    printf("%lld\n", ans);
    return 0;
}
