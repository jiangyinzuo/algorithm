//
// Created by Jiang Yinzuo on 2020/7/18.
// luogu p3366

#include <cstdio>
#include <queue>
#include <cstring>

#define MAX_V_NUM 5000
#define MAX_E_NUM 200000

const int INF = 0x7fffffff;

struct Edge {
    int to, next, weight;
    static int idx;
    static int head[MAX_V_NUM + 1];

    bool operator<(const Edge &e) const {
        return this->weight < e.weight;
    }
} edges[MAX_E_NUM * 2 + 1];

int Edge::idx = 0;
int Edge::head[MAX_V_NUM + 1] = {0};

static inline void add_edge(int u, int v, int weight) {
    edges[++Edge::idx] = {v, Edge::head[u], weight};
    Edge::head[u] = Edge::idx;
}

/**
 * prim算法求最小生成树
 * @param n 图中点的个数
 * @return 最小生成树的权值之和。返回-1表示图不连通
 */
int prim(int n) {

    static bool added_v[MAX_V_NUM + 1];
    static int min_weight[MAX_V_NUM + 1];
    for (int i = 0; i <= n; ++i) min_weight[i] = INF;
    memset(added_v, false, sizeof(added_v));
    int added_v_num = 1;
    int cur_v = 1;
    int result = 0;
    added_v[cur_v] = true;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<> > queue;
    for (int i = Edge::head[cur_v]; i; i = edges[i].next) {
        queue.push({edges[i].weight, edges[i].to});
    }
    while (!queue.empty() && added_v_num < n) {
        auto edge = queue.top();
        queue.pop();
        if (added_v[edge.second]) continue;
        added_v[edge.second] = true;
        result += edge.first;
        added_v_num++;
        for (int i = Edge::head[edge.second]; i; i = edges[i].next) {
            if (!added_v[edges[i].to] && edges[i].weight < min_weight[edges[i].to]) {
                min_weight[edges[i].to] = edges[i].weight;
                queue.push({edges[i].weight, edges[i].to});
            }
        }
    }
    if (added_v_num < n) return -1;
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    int result = prim(n);
    if (result >= 0) printf("%d\n", result);
    else {
        printf("orz\n");
    }
    return 0;
}