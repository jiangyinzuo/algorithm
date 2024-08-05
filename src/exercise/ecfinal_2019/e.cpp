//
// Created by Jiang Yinzuo on 2020/12/10.
//

#include <algorithm>
#include <cstdio>
#include <vector>

struct Node {
    int v;
    long long w;
};
std::vector<Node> graph[200001];
std::vector<long long> flow[100001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long total = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        graph[u].push_back({v, w});
        total += w;
    }
    if (n == 2) {
        puts("0");
        return 0;
    }
    int flow_idx = 0;
    for (auto &node : graph[1]) {
        int v = node.v;
        auto &_node = node;
        do {
            flow[flow_idx].push_back(_node.w);
            _node = graph[v][0];
            v = _node.v;
        } while (v != n);
        flow[flow_idx].push_back(_node.w);
        ++flow_idx;
    }

    for (int i = 0; i < flow_idx; ++i) {
        std::sort(flow[i].begin(), flow[i].end());
    }

    long long avg = total / flow[0].size(), ans = 0;
    for (int i = 0; i < flow[0].size(); ++i) {
        long long sum = 0;
        for (int j = 0; j < flow_idx;++j) {
            sum += flow[j][i];
        }
        ans += std::max(0LL, avg - sum);
    }
    printf("%lld\n", ans);
    return 0;
}