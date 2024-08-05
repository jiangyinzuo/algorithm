//
// Created by Jiang Yinzuo on 2020/12/7.
//

#include <cstdio>
#include <unordered_set>
#include <vector>

std::vector<int> tree[100001];
int color[100001];

int heavy_child[100001];
int size[100001];

/*
 * 求重儿子
 */
void dfs1(int cur_v, int father) {

    size[cur_v] = 1;
    int max_size = 0, heaviest_child = 0;
    for (auto &i : tree[cur_v]) {
        if (i != father) {
            dfs1(i, cur_v);
            size[cur_v] += size[i];
            if (size[i] > max_size) {
                max_size = size[i];
                heaviest_child = i;
            }
        }
    }
    heavy_child[cur_v] = heaviest_child;
}

int color_cnt[100001];

std::unordered_set<int> dfs2(int cur_v, int father) {
    if (tree[cur_v].size() == 1 && father != 0) {
        std::unordered_set<int> exist;
        color_cnt[cur_v] = 1;
        exist.insert(color[cur_v]);
        return exist;
    }

    auto heavy_exist = dfs2(heavy_child[cur_v], cur_v);
    for (auto &i : tree[cur_v]) {
        if (i != father && i != heavy_child[cur_v]) {
            auto light_exist = dfs2(i, cur_v);
            heavy_exist.merge(light_exist);
        }
    }

    heavy_exist.insert(color[cur_v]);
    color_cnt[cur_v] = heavy_exist.size();
    return heavy_exist;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", color + i);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int q;
        scanf("%d", &q);
        printf("%d\n", color_cnt[q]);
    }
    return 0;
}