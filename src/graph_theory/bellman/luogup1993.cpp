//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include <cstdio>
#include <queue>

#define MAX_V_NUM 10000
#define MAX_EDGE_NUM 500000

const int INF = 0x7fffffff;

struct Edge {
    int to, next, weight;
    static int idx;
    static int head[MAX_V_NUM + 2];
} edges[MAX_EDGE_NUM + 2];

int Edge::idx = 0;
int Edge::head[MAX_V_NUM + 2] = {0};

inline void add_edge(int u, int v, int weight) {
    edges[++Edge::idx] = {v, Edge::head[u], weight};
    Edge::head[u] = Edge::idx;
}

int distance[MAX_V_NUM + 2];

/**
 * 判断是否有负环
 * @param n 图中点的个数
 * @param start_v 起点
 * @return 有负环: true; 没有: false
 */
bool spfa(int n, int start_v) {

    static bool in_queue[MAX_V_NUM + 2];
    static int count[MAX_V_NUM + 2];
    for (int i = 0; i <= n; ++i) {
        distance[i] = INF;
        in_queue[i] = false;
        count[i] = 0;
    }
    std::queue<int> v_queue;
    v_queue.push(start_v);
    in_queue[start_v] = true;
    distance[start_v] = 0;

    while (!v_queue.empty()) {
        int cur_v = v_queue.front();
        v_queue.pop();
        in_queue[cur_v] = false;
        for (int i = Edge::head[cur_v]; i; i = edges[i].next) {
            int to = edges[i].to;
            if (distance[cur_v] + edges[i].weight < distance[to]) {
                distance[to] = distance[cur_v] + edges[i].weight;
                if (++count[to] >= n) return true;
                if (!in_queue[to]) {
                    v_queue.push(to);
                    in_queue[to] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int op, u, v, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &u, &v, &c);
            add_edge(u, v, -c);
        } else if (op == 2) {
            scanf("%d %d %d", &u, &v, &c);
            add_edge(v, u, c);
        } else {
            scanf("%d %d", &u, &v);
            add_edge(u, v, 0);
            add_edge(v, u, 0);
        }
    }
    // 保证图是连通的
    for (int i = 1; i <= n; ++i)
        add_edge(n + 1, i, 0);
    puts(spfa(n + 1, n + 1) ? "No" : "Yes");
    return 0;
}