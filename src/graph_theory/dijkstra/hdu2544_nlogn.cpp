//
// Created by Jiang Yinzuo on 2020/3/8.
// hdu2544

#include <cstdio>
#include <queue>
#include <cstring>

const long long MAX_LONG_LONG = 9223372036854775807;

struct Edge {
    static int edge_idx;
    static int heads[100005];
    int to;
    long long distance;
    int next;

    bool operator<(Edge &e) const {
        return distance < e.distance;
    }
} edges[200005];

int Edge::edge_idx = 0;
int Edge::heads[100005] = {0};

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


long long distance[100005];
bool visited[100005];

void dijkstra(int vertex_count) {

    memset(visited, false, sizeof(visited));
    distance[1] = 0;
    for (int i = 2; i <= vertex_count; ++i) {
        distance[i] = MAX_LONG_LONG;
    }

    std::priority_queue<Vertex> vertex_queue;

    // 1是起点
    vertex_queue.push({1, 0});

    while (!vertex_queue.empty()) {
        Vertex cur_v = vertex_queue.top();
        vertex_queue.pop();
        if (visited[cur_v.v]) continue;

        // 搜索到终点结束
        if (cur_v.v == vertex_count) break;

        visited[cur_v.v] = true;

        for (int i = Edge::heads[cur_v.v]; i; i = edges[i].next) {
            if (!visited[edges[i].to] && distance[edges[i].to] > distance[cur_v.v] + edges[i].distance) {
                distance[edges[i].to] = distance[cur_v.v] + edges[i].distance;
                vertex_queue.push({edges[i].to, distance[edges[i].to]});
            }
        }
    }
    printf("%lld\n", distance[vertex_count]);
}

int main() {
    int vertex_count, road_count;

    int from, to, tmp_dis;
    while (~scanf("%d %d", &vertex_count, &road_count) && vertex_count && road_count) {
        Edge::edge_idx = 0;
        memset(Edge::heads, 0, sizeof(Edge::heads));

        for (int i = 0; i < road_count; ++i) {
            scanf("%d %d %d", &from, &to, &tmp_dis);
            add_edge(from, to, tmp_dis);
            add_edge(to, from, tmp_dis);
        }
        dijkstra(vertex_count);
    }
    return 0;
}