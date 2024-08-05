//
// Created by Jiang Yinzuo on 2020/10/28.
//

#include <cstdio>
#include <vector>

constexpr int MAX_N = 200004;

std::vector<int> tree[MAX_N + 1];

////////////// tree split
int father[MAX_N];
int depth[MAX_N];
int size[MAX_N];
int heavy_son[MAX_N] = {0};
int chain_top[MAX_N]; // chain_top[v] =  top of the heavy chain containing v
int dfn[MAX_N], dfn_cnt = 0; // dfs order
int rank[MAX_N]; // rank[dfn[v]] = v

int weight[MAX_N];
int w[MAX_N];

/// process father, depth, size and heavy_son
void dfs1(int cur_v, int fa, int dep) {
    father[cur_v] = fa;
    depth[cur_v] = dep;
    size[cur_v] = 1;
    for (auto i : tree[cur_v]) {
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
    if (!heavy_son[cur_v]) return;
    dfs2(heavy_son[cur_v], top);

    for (auto i : tree[cur_v]) {
        if (i != heavy_son[cur_v] && i != father[cur_v]) {
            dfs2(i, i); // top of a heavy chain
        }
    }
}
///////////////////

///// segment tree
int arr[(MAX_N << 2) + 1], lazy_tag[(MAX_N << 2) + 1] = {0};
int mod;

void push_down(int cur_v, int len) {
    lazy_tag[cur_v << 1] += lazy_tag[cur_v];
    lazy_tag[cur_v << 1 | 1] += lazy_tag[cur_v];
    arr[cur_v << 1] += lazy_tag[cur_v] * (len - (len >> 1));
    arr[cur_v << 1 | 1] += lazy_tag[cur_v] * (len >> 1);
    arr[cur_v << 1] %= mod;
    arr[cur_v << 1 | 1] %= mod;
    lazy_tag[cur_v] = 0;
}

void build(int cur_v, int l, int r) {
    if (l == r) {
        arr[cur_v] = weight[l] % mod;
        return;
    }
    int mid = (l + r) / 2;
    build(cur_v << 1, l, mid);
    build(cur_v << 1 | 1, mid + 1, r);
    arr[cur_v] = (arr[cur_v << 1] + arr[cur_v << 1 | 1]) % mod;
}

int query(int cur_v, int l, int r, int L, int R) {
    int res = 0;
    if (L <= l && r <= R) {
        return arr[cur_v] % mod;
    }
    if (lazy_tag[cur_v]) push_down(cur_v, r - l + 1);
    int mid = (l + r) / 2;
    if (L <= mid) res = (res + query(cur_v << 1, l, mid, L, R)) % mod;
    if (R > mid) res = (res + query(cur_v << 1 | 1, mid + 1, r, L, R)) % mod;
    return res;
}

void update(int cur_v, int l, int r, const int L, const int R, int val) {
    if (L <= l && r <= R) {
        lazy_tag[cur_v] += val;
        arr[cur_v] += val * (r - l + 1);
    } else {
        if (lazy_tag[cur_v])push_down(cur_v, r - l + 1);
        int mid = (l + r) / 2;
        if (L <= mid)update(cur_v << 1, l, mid, L, R, val);
        if (R > mid)update(cur_v << 1 | 1, mid + 1, r, L, R, val);
        arr[cur_v] = (arr[cur_v << 1] + arr[cur_v << 1 | 1]) % mod;
    }
}

////////////
int n, m, r;

int query_range(int x, int y) {
    int ans = 0;

    // 当两个点不在同一条链上
    while (chain_top[x] != chain_top[y]) {
        // 把x点改为所在链顶端的深度更深的那个点
        if (depth[chain_top[x]] < depth[chain_top[y]])
            std::swap(x, y);
        // ans加上x点到x所在链顶端 这一段区间的点权和
        ans = (ans + query(1, 1, n, dfn[chain_top[x]], dfn[x])) % mod;
        // 把x跳到x所在链顶端的那个点的上面一个点
        x = father[chain_top[x]];
    }
    // 直到两个点处于一条链上
    // 把x跳到x所在链顶端的那个点的上面一个点
    if (depth[x] > depth[y]) std::swap(x, y);
    // 把x跳到x所在链顶端的那个点的上面一个点
    return (ans + query(1, 1, n, dfn[x], dfn[y])) % mod;
}

void update_range(int x, int y, int val) {
    val %= mod;
    while (chain_top[x] != chain_top[y]) {
        if (depth[chain_top[x]] < depth[chain_top[y]])std::swap(x, y);
        update(1, 1, n, dfn[chain_top[x]], dfn[x], val);
        x = father[chain_top[x]];
    }
    if (depth[x] > depth[y])std::swap(x, y);
    update(1, 1, n, dfn[x], dfn[y], val);
}

int query_subtree(int x) {
    // 把x跳到x所在链顶端的那个点的上面一个点
    return query(1, 1, n, dfn[x], dfn[x] + size[x] - 1);
}

void update_subtree(int x, int val) {
    update(1, 1, n, dfn[x], dfn[x] + size[x] - 1, val);
}


int main() {
    scanf("%d %d %d %d", &n, &m, &r, &mod);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", w + i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(r, 0, 1);
    dfs2(r, r);
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int op, x, y, z;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &x, &y, &z);
            update_range(x, y, z);
        } else if (op == 2) {
            scanf("%d %d", &x, &y);
            printf("%d\n", query_range(x, y));
        } else if (op == 3) {
            scanf("%d %d", &x, &z);
            update_subtree(x, z);
        } else {
            scanf("%d", &x);
            printf("%d\n", query_subtree(x));
        }
    }
    return 0;
}