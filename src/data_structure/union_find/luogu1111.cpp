#include <cstdio>
#include <algorithm>

struct Road {
    int v1;
    int v2;
    int order;

    bool operator<(Road &r) const {
        return this->order < r.order;
    }
};

int parents[1001];
Road roads[100001];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
    }
}

int find_parent(int v) {
    return parents[v] == v ? v : parents[v] = find_parent(parents[v]);
}

void union_set(int v1, int v2) {
    int p1 = find_parent(v1);
    int p2 = find_parent(v2);
    parents[p1] = p2;
}

void solve(int n, int m) {
    std::sort(roads, roads + m);
    int count = n;
    for (int i = 0; i < m; ++i) {
        if (find_parent(roads[i].v1) != find_parent(roads[i].v2)) {
            union_set(roads[i].v1, roads[i].v2);
            --count;
        }
        if (count == 1) {
            printf("%d\n", roads[i].order);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    // 村庄数，公路数
    int n, m;
    scanf("%d %d", &n, &m);

    int v1, v2, order;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &v1, &v2, &order);
        roads[i].v1 = v1;
        roads[i].v2 = v2;
        roads[i].order = order;
    }
    init(n);
    solve(n, m);
    return 0;
}