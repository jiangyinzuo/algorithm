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

void spfa(int n, int start_v) {

    static bool in_queue[MAX_V_NUM + 2];
    for (int i = 0; i <= n; ++i) {
        distance[i] = INF;
        in_queue[i] = false;
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
                if (!in_queue[to]) {
                    v_queue.push(to);
                    in_queue[to] = true;
                }
            }
        }
    }
}

int main() {
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);

    int u, v, weight;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(u, v, weight);
    }
    spfa(n, start);
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", distance[i], (i != n ? ' ' : '\n'));
    }
    return 0;
}