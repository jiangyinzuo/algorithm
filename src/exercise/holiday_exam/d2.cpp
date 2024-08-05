//
// Created by Jiang Yinzuo on 2020/3/8.
// hdu2544

#include <cstdio>
#include <queue>
#include <cstring>

const long long MAX_LONG_LONG = 9223372036854775807;

struct Edge {
    static int edge_idx;
    static int heads[105];
    int to;
    long long distance;
    int next;

    bool operator<(Edge &e) const {
        return distance < e.distance;
    }
} edges[200005];

int Edge::edge_idx = 0;
int Edge::heads[105] = {0};

struct Vertex {
    int v;
    long long distance;

    Vertex(int v, long long distance) : v(v), distance(distance) {}

    bool operator<(const Vertex &vertex) const {
        return distance > vertex.distance;
    }
};

void add_edge(int from, int to, long long distance) {
    edges[++Edge::edge_idx] = {to, distance, Edge::heads[from]};
    Edge::heads[from] = Edge::edge_idx;
}


long long distance[105];
bool visited[105];

void dijkstra(int vertex_count) {

    distance[0] = 0;

    for (int i = 1; i <= vertex_count; ++i) {
        distance[i] = MAX_LONG_LONG;
    }

    std::priority_queue<Vertex> vertex_queue;

    // 0是起点
    vertex_queue.push({0, 0});

    while (!vertex_queue.empty()) {
        Vertex cur_v = vertex_queue.top();
        vertex_queue.pop();
        if (visited[cur_v.v]) continue;


        visited[cur_v.v] = true;

        for (int i = Edge::heads[cur_v.v]; i; i = edges[i].next) {
            if (!visited[edges[i].to] && distance[edges[i].to] > distance[cur_v.v] + edges[i].distance) {
                distance[edges[i].to] = distance[cur_v.v] + edges[i].distance;
                vertex_queue.push({edges[i].to, distance[edges[i].to]});
            }
        }
    }
}

int main() {

    int m, n;
    int item[102], level[103];
    while (~scanf("%d %d", &m, &n)) {
        Edge::edge_idx = 0;
        memset(Edge::heads, 0, sizeof(Edge::heads));

        int min_level = 0x7fffffff, max_level = 0;
        for (int i = 1; i <= n; i++) {
            int edge_num;
            scanf("%d %d %d", &item[i], &level[i], &edge_num);
            add_edge(0, i, item[i]);
            min_level = std::min(min_level, level[i]);
            max_level = std::max(max_level, level[i]);
            while (edge_num--) {
                int ver, value;
                scanf("%d %d", &ver, &value);
                add_edge(ver, i, value);
            }
        }

        long long answer = item[1];
        for (int i = min_level; i <= max_level; ++i) {
            memset(visited, false, sizeof(visited));
            for (int j = 1; j <= n; j++)
                if (level[j] > i || i - level[j] > m)
                    visited[j] = true;
            dijkstra(n);
            answer = std::min(answer, distance[1]);
        }
        printf("%lld\n", answer);
    }
    return 0;
}