//
// Created by Jiang Yinzuo on 2020/7/18.
//

#include <cstdio>
#include <vector>

#define MAX_E_NUM 10004

int parents[MAX_E_NUM];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
    }
}

/**
 * 路径压缩
 * @param v
 * @return
 */
int find_parent(int v) {
    return parents[v] == v ? v : parents[v] = find_parent(parents[v]);
}

std::vector<int> size(MAX_E_NUM, 1);

/**
 * 启发式合并
 * @param v1
 * @param v2
 */
void union_set(int v1, int v2) {
    int p1 = find_parent(v1);
    int p2 = find_parent(v2);
    if (p1 == p2) return;
    if (size[p1] > size[p2])  // 保证小的合到大的里
        std::swap(p1, p2);
    parents[p1] = p2;
    size[p2] += size[p1];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    init(n);
    int op, u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &op, &u, &v);
        if (op == 1) {
            union_set(u, v);
        } else {
            puts(find_parent(u) == find_parent(v) ? "Y" : "N");
        }
    }
    return 0;
}