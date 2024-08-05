#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

struct Edge {
    int v;
    long long weight;

    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
};

std::vector<Edge> graph[500009];

struct Path {
    int u, v, idx;
    long long total_weight;

    bool operator>(const struct Path &path) const {
        return total_weight > path.total_weight;
    }
};

static int max_query = 0;
static long long result[500005];

long long solve(int query,  std::priority_queue<Path, std::vector<Path>, std::greater<Path> > &queue) {

    Path p{};
    while (max_query < query && !queue.empty()) {
        p = queue.top();
        queue.pop();
        result[++max_query] = p.total_weight;
        if (0 < p.idx && p.idx < graph[p.u].size()) {
            queue.push({p.u,
                        graph[p.u][p.idx].v,
                        p.idx + 1,
                        p.total_weight - graph[p.u][p.idx - 1].weight + graph[p.u][p.idx].weight});
        }
        if (!graph[p.v].empty()) {
            queue.push({p.v, graph[p.v][0].v, 1, p.total_weight + graph[p.v][0].weight});
        }
    }
    return result[query];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);

        max_query = 0;
        memset(result, 0, sizeof(result));
        std::priority_queue<Path, std::vector<Path>, std::greater<Path> > queue;
        for (int i = 1; i <= n; ++i) graph[i].clear();

        int u, v;
        long long w;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %lld", &u, &v, &w);
            graph[u].push_back({v, w});
            queue.push({u, v, -1, w});
        }
        for (int i = 1; i <= n; ++i) std::sort(graph[i].begin(), graph[i].end());

        int query;
        for (int i = 0; i < q; ++i) {
            scanf("%d", &query);
            printf("%lld\n", solve(query, queue));
        }
    }
    return 0;
}