//
// Created by Jiang Yinzuo on 2020/8/3.
//

#include <algorithm>
#include <cstdio>
#include <map>

const int maxn = 100010;

struct Graph {
    int v_num, e_num;
};
bool vertex[2 * maxn];
int parents[2 * maxn];
std::map<int, Graph> graphs;
int a[maxn];
int b[maxn];
int c[2 * maxn];

inline void init(int n) {
    graphs.clear();
    for (int i = 0; i <= 2 * n; i++)
        parents[i] = vertex[i] = false;
}

int find_parent(int v) {
    auto &p = parents[v];
    if (p == 0) {
        return p = v;
    }
    return p == v ? v : p = find_parent(p);
}

void union_set(int v1, int v2) {
    int p1 = find_parent(v1);
    int p2 = find_parent(v2);
    parents[p1] = p2;

    auto &g1 = graphs[p1];
    auto &g2 = graphs[p2];
    int new_v_num = 0;
    if (vertex[v1] == 0) {
        ++new_v_num;
    }
    if (v1 != v2 && vertex[v2] == 0) {
        ++new_v_num;
    }

    if (p2 != p1) {
        g2.v_num += g1.v_num + new_v_num;
        g2.e_num += g1.e_num + 1;
        graphs.erase(p1);
    } else {
        ++g2.e_num;
        g2.v_num += new_v_num;
    }
}

void Discretization(int n) {
    for (int i = 1; i <= n; i++) {
        c[i] = a[i];
        c[i + n] = b[i];
    }
    std::sort(c + 1, c + n + 1);
    int len = std::unique(c + 1, c + n + 1) - c - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = std::lower_bound(c + 1, c + 1 + len, a[i]) - c;
        b[i] = std::lower_bound(c + 1, c + 1 + len, b[i]) - c;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int n;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i], &b[i]);
        }
        Discretization(n);
        for (int i = 1; i <= n; ++i) {
            union_set(a[i], b[i]);
            vertex[a[i]] = true;
            vertex[b[i]] = true;
        }
        int ans = 0;
        for (auto &i : graphs) {
            ans += std::min(i.second.v_num, i.second.e_num);
        }
        printf("Case #%d: %d\n", kase, ans);
    }

    return 0;
}