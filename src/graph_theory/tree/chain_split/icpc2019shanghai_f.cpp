//
// Created by Jiang Yinzuo on 2020/12/11.
//

#include <cstdio>
#include <vector>

constexpr int MaxN = 100001;
constexpr long long Mod = 1000000007;
std::vector<int> tree[MaxN];

namespace tree_split {
int father[MaxN];
int depth[MaxN];
int size[MaxN];
int heavy_son[MaxN] = {0};
int chain_top[MaxN];  // chain_top[v] =  top of the heavy chain containing v
int dfn[MaxN], dfn_cnt = 0;  // dfs order
int rank[MaxN];  // rank[dfn[v]] = v

long long weight[MaxN];  // dfs order
long long w[MaxN];  // initial node weight

/// process father, depth, size and heavy_son
void dfs1(int cur_v, int fa, int dep) {
    father[cur_v] = fa;
    depth[cur_v] = dep;
    size[cur_v] = 1;
    for (auto &i : tree[cur_v]) {
        if (i != fa) {
            dfs1(i, cur_v, dep + 1);
            size[cur_v] += size[i];
            if (size[i] >= size[heavy_son[cur_v]]) {
                heavy_son[cur_v] = i;
            }
        }
    }
}

void dfs2(int cur_v, int top) {
    chain_top[cur_v] = top;
    dfn[cur_v] = ++dfn_cnt;
    weight[dfn_cnt] = w[cur_v];
    rank[dfn_cnt] = cur_v;
    if (!heavy_son[cur_v])
        return;
    dfs2(heavy_son[cur_v], top);

    for (auto &i : tree[cur_v]) {
        if (i != heavy_son[cur_v] && i != father[cur_v]) {
            tree_split::dfs2(i, i);  // top of a heavy chain
        }
    }
}

}  // namespace tree_split

namespace seg_tree {
long long sum1[(MaxN << 2) + 1], sum2[(MaxN << 2) + 1], sum3[(MaxN << 2) + 1];

long long add_lazy_tag[(MaxN << 2) + 1]{0};
long long multi_lazy_tag[(MaxN << 2) + 1]{0};

void push_up(int cur_v) {
    sum1[cur_v] = (sum1[cur_v << 1] + sum1[cur_v << 1 | 1]) % Mod;
    sum2[cur_v] = (sum2[cur_v << 1] + sum2[cur_v << 1 | 1]) % Mod;
    sum3[cur_v] = (sum3[cur_v << 1] + sum3[cur_v << 1 | 1]) % Mod;
}

void push_down(int cur_v, int len) {
    add_lazy_tag[cur_v << 1] += add_lazy_tag[cur_v];
    add_lazy_tag[cur_v << 1 | 1] += add_lazy_tag[cur_v];
    sum1[cur_v << 1] += add_lazy_tag[cur_v] * (len - (len >> 1));
    sum1[cur_v << 1 | 1] += add_lazy_tag[cur_v] * (len >> 1);
    sum1[cur_v << 1] %= Mod;
    sum1[cur_v << 1 | 1] %= Mod;
    add_lazy_tag[cur_v] = 0;
}

void build(int cur_v, int l, int r) {
    if (l == r) {
        sum1[cur_v] = tree_split::weight[l] % Mod;
        sum2[cur_v] = sum1[cur_v] * sum1[cur_v] % Mod;
        sum3[cur_v] = sum2[cur_v] * sum1[cur_v] % Mod;
        return;
    }
    int mid = (l + r) / 2;
    build(cur_v << 1, l, mid);
    build(cur_v << 1 | 1, mid + 1, r);
    push_up(cur_v);
}

int query(int cur_v, int l, int r, const int L, const int R) {
    int res = 0;
    if (L <= l && r <= R) {
        return sum1[cur_v] % Mod;
    }
    if (add_lazy_tag[cur_v])
        push_down(cur_v, r - l + 1);
    int mid = (l + r) / 2;
    if (L <= mid)
        res = (res + query(cur_v << 1, l, mid, L, R)) % Mod;
    if (R > mid)
        res = (res + query(cur_v << 1 | 1, mid + 1, r, L, R)) % Mod;
    return res;
}

void update(int cur_v, int l, int r, const int L, const int R, int val) {
    if (L <= l && r <= R) {
        add_lazy_tag[cur_v] += val;
        sum1[cur_v] += val * (r - l + 1);
    } else {
        if (add_lazy_tag[cur_v])
            push_down(cur_v, r - l + 1);
        int mid = (l + r) / 2;
        if (L <= mid)
            update(cur_v << 1, l, mid, L, R, val);
        if (R > mid)
            update(cur_v << 1 | 1, mid + 1, r, L, R, val);
        sum1[cur_v] = (sum1[cur_v << 1] + sum1[cur_v << 1 | 1]) % Mod;
    }
}
}  // namespace seg_tree

using namespace seg_tree;
using namespace tree_split;

int n;  // num of node
long long query_range(int x, int y) {
    long long ans = 0;

    // 当两个点不在同一条链上
    while (chain_top[x] != chain_top[y]) {
        // 把x点改为所在链顶端的深度更深的那个点
        if (depth[chain_top[x]] < depth[chain_top[y]])
            std::swap(x, y);
        // ans加上x点到x所在链顶端 这一段区间的点权和
        ans = (ans + query(1, 1, n, dfn[chain_top[x]], dfn[x])) % Mod;
        // 把x跳到x所在链顶端的那个点的上面一个点
        x = father[chain_top[x]];
    }
    // 直到两个点处于一条链上
    // 把x跳到x所在链顶端的那个点的上面一个点
    if (depth[x] > depth[y])
        std::swap(x, y);
    // 把x跳到x所在链顶端的那个点的上面一个点
    return (ans + query(1, 1, n, dfn[x], dfn[y])) % Mod;
}

void update_range(int x, int y, long long val) {
    val %= Mod;
    using namespace seg_tree;
    using namespace tree_split;

    while (chain_top[x] != chain_top[y]) {
        if (depth[chain_top[x]] < depth[chain_top[y]])
            std::swap(x, y);
        update(1, 1, n, dfn[chain_top[x]], dfn[x], val);
        x = father[chain_top[x]];
    }
    if (depth[x] > depth[y])
        std::swap(x, y);
    update(1, 1, n, dfn[x], dfn[y], val);
}

int query_subtree(int x) {
    // 把x跳到x所在链顶端的那个点的上面一个点
    return query(1, 1, n, dfn[x], dfn[x] + size[x] - 1);
}

void update_subtree(int x, int val) {
    update(1, 1, n, dfn[x], dfn[x] + size[x] - 1, val);
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d", &n);
        init(n);

        for (int i = 0; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            scanf("%lld", tree_split::w + i);
        }

        tree_split::dfs1(1, 0, 1);
        tree_split::dfs2(1, 1);
        seg_tree::build(1, 1, n);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            int op;
            scanf("%d", &op);
            int u, v;
            long long w;
            switch (op) {
            case 1:
                scanf("%d %d %lld", &u, &v, &w);
                update_range(u, v, w);
            case 2:
            case 3:
            case 4:
            default:
                break;
            }
        }
    }
    return 0;
}