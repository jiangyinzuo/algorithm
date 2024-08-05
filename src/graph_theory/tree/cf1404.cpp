//
// Created by jiang on 2020/9/15.
//

#include <cstdio>
#include <vector>

std::vector<int> tree[100004];

int dis;
void get_dis(int cur, int end, int father, int depth) {
    if (cur == end) {
        dis = depth;
        return;
    }
    for (auto i : tree[cur]) {
        if (i != father) {
            get_dis(i, end, cur, depth + 1);
        }
    }
}

int max_depth = 0;
int end1;
void get_diameter(int cur, int father, int depth) {
    if (tree[cur].size() == 1 && father != -1 && depth > max_depth) {
        max_depth = depth;
        end1 = cur;
    }
    for (auto i : tree[cur]) {
        if (i != father) {
            get_diameter(i, cur, depth + 1);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b, da, db, u, v;
        scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);

        for (int i = 1; i <= n; ++i) tree[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        if (db <= da * 2) {
            puts("Alice");
            continue;
        }
        get_dis(a, b, -1, 0);
        if (da >= dis) {
            puts("Alice");
            continue;
        }
        max_depth = 0;
        get_diameter(1, -1, 1);
        get_diameter(end1, -1, 1);
        int diameter = max_depth;
        if (2 * da + 1 >= diameter) {
            puts("Alice");
        } else {
            puts("Bob");
        }
    }
    return 0;
}