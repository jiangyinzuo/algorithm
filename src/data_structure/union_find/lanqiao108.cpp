// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.
// https://www.lanqiao.cn/problems/108/learning

#include <cstdio>

template<const int N>
class UnionFind {
    int fathers[N + 1]{};
public:
    UnionFind() {
        for (int i = 0; i < N + 1; ++i) {
            fathers[i] = i;
        }
    }
    void Union(int v1, int v2) {
        int f1 = Find(v1);
        int f2 = Find(v2);
        fathers[f1] = f2;
    }

    int Find(int v1) {
        return fathers[v1] == v1 ? v1 : fathers[v1] = Find(fathers[v1]);
    }
};
UnionFind<100009> u = UnionFind<100009>();
int main() {
    int n;
    scanf("%d", &n);
    int father;
    for (int i = 0; i < n; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        if (u.Find(v1) == u.Find(v2)) {
            father = u.Find(v1);
        } else {
            u.Union(v1, v2);
        }
    }
    int root = u.Find(father);

    for (int i = 1; i <= n; ++i) {
        if (u.Find(i) == root)
            printf("%d%c", i, i == n ? '\n' : ' ');
    }
    return 0;
}
