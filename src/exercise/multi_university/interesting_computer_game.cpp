//
// Created by Jiang Yinzuo on 2020/8/3.
//

#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <ctime>

struct Graph {
    int v_num, e_num;
};
std::unordered_set<int> vertex;
std::unordered_map<int, int> parents;
std::unordered_map<int, Graph> graphs;

inline void init() {
    graphs.clear();
    parents.clear();
    vertex.clear();
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
    if (vertex.find(v1) == vertex.end()) {
        ++new_v_num;
    }
    if (v1 != v2 && vertex.find(v2) == vertex.end()) {
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

int main() {
    FILE* f = fopen("data2.txt", "r");
    clock_t clk = clock();
    int t;
    fscanf(f, "%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int n, a, b;
        init();
        fscanf(f, "%d", &n);
        for (int i = 0; i < n; ++i) {
            fscanf(f, "%d %d", &a, &b);
            union_set(a, b);
            vertex.insert(a);
            vertex.insert(b);
        }
        int ans = 0;
        for (auto &i : graphs) {
            ans += std::min(i.second.v_num, i.second.e_num);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    printf("%d\n", clock() - clk);
    return 0;
}

/*


1
1 1
4
1 2
1 2
1 1
7 7
3
1 1
2 2
1 2
2
1 1
2 2
*/