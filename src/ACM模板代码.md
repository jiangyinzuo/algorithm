# ACM模板代码

[TOC]

## C++

std::cin取消同步

```c++
std::cin.sync_with_stdio(false);
std::cin.tie(nullptr);
```

## 数据结构

### 并查集



### 线段树

```c++
//
// Created by Jiang Yinzuo on 2020/3/21.
//

#include <cstdio>
#include <cstring>

namespace seg_tree {
int sum1[50005];
int tree[50005 << 2];

/**
 * 区间查询
 * @param left 线段树节点左边界
 * @param right 线段树节点右边界
 * @param cur_idx 当前线段树节点标记
 * @param arr_left 区间查询左边界
 * @param arr_right 区间查询右边界
 * @return
 */
int query(int left, int right, int cur_idx, const int arr_left, const int arr_right) {
    if (arr_left <= left && right <= arr_right) {
        return tree[cur_idx];
    }

    int mid = (left + right) / 2;

    int result = 0;
    if (arr_left <= mid) {
        result = query(left, mid, cur_idx << 1, arr_left, arr_right);
    }
    if (mid + 1 <= arr_right) {
        result += query(mid + 1, right, (cur_idx << 1) | 1, arr_left, arr_right);
    }

    return result;
}

/**
 * 单点更新线段树
 * @param left 线段树节点左边界
 * @param right 线段树节点右边界
 * @param cur_idx 当前线段树节点标号
 * @param arr_idx 更新的原始数组标号
 * @param value 更新值
 */
void update(int left, int right, int cur_idx, const int arr_idx, const int value) {
    if (left == right) {
        tree[cur_idx] += value;
        return;
    }

    int mid = (left + right) / 2;
    if (arr_idx <= mid) {
        update(left, mid, cur_idx << 1, arr_idx, value);
    } else {
        update(mid + 1, right, (cur_idx << 1) | 1, arr_idx, value);
    }

    tree[cur_idx] = tree[cur_idx << 1] + tree[(cur_idx << 1) | 1];
}

/**
 * 建立线段树
 * @param left 线段树节点左边界
 * @param right 线段树节点右边界
 * @param cur_idx 当前线段树节点标号
 */
void build(int left, int right, int cur_idx) {
    if (left == right) {
        tree[cur_idx] = sum1[left];
        return;
    }

    int mid = (left + right) / 2;
    build(left, mid, cur_idx << 1);
    build(mid + 1, right, (cur_idx << 1) | 1);
    tree[cur_idx] = tree[cur_idx << 1] + tree[(cur_idx << 1) | 1];
}
}


int main() {
    int t, n;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &seg_tree::sum1[i]);
        }
        seg_tree::build(1, n, 1);

        printf("Case %d:\n", kase);

        char query_str[6];
        int l, r;
        while (true) {
            scanf("%s", query_str);
            if (strcmp(query_str, "End") == 0) {
                break;
            }
            scanf("%d %d", &l, &r);
            if (strcmp(query_str, "Query") == 0) {
                printf("%d\n", seg_tree::query(1, n, 1, l, r));
            } else if (strcmp(query_str, "Add") == 0) {
                seg_tree::update(1, n, 1, l, r);
            } else if (strcmp(query_str, "Sub") == 0) {
                seg_tree::update(1, n, 1, l, -r);
            }
        }
    }
    return 0;
}

```

```C++
/**
 * luogu3372
 *
 */
#include <cstdio>

long long seq[100008];
long long seg_tree[400008];
long long add_tag[400008] = {0};

/**
 * 建立线段树
 * @param l 区间左端点
 * @param r 区间右端点
 * @param num 序号
 */
void build(int l, int r, int num) {
    if (l == r) {
        seg_tree[num] = seq[l];
        return;
    }

    build(l, (l + r) / 2, num << 1);
    build((l + r) / 2 + 1, r, num << 1 | 1);

    seg_tree[num] = seg_tree[num << 1] + seg_tree[num << 1 | 1];
}

/**
 * 下推懒惰标记
 * @param l 左区间端点
 * @param r 右区间端点
 * @param num 序号
 */
void push_down(int l, int r, int num) {

    if (add_tag[num]) {
        int mid = (r + l) / 2;
        seg_tree[num << 1] += add_tag[num] * (mid - l + 1);
        seg_tree[num << 1 | 1] += add_tag[num] * (r - mid);
        add_tag[num << 1] += add_tag[num];
        add_tag[num << 1 | 1] += add_tag[num];
        add_tag[num] = 0;
    }
}

/**
 * 区间更新
 * @param update_l 更新区间左端点
 * @param update_r 更新区间右端点
 * @param value 更新的值
 * @param l 当前搜索区间左端点
 * @param r 当前搜索区间右端点
 * @param num 线段树序号
 */
void update(int update_l, int update_r, long long value, int l, int r, int num) {
    if (update_l <= l && r <= update_r) {
        seg_tree[num] += (r - l + 1) * value;
        add_tag[num] += value;
        return;
    }

    push_down(l, r, num);

    int mid = (l + r) / 2;
    if (update_l <= mid) {
        update(update_l, update_r, value, l, mid, num << 1);
    }
    if (mid + 1 <= update_r) {
        update(update_l, update_r, value, mid + 1, r, num << 1 | 1);
    }
    seg_tree[num] = seg_tree[num << 1] + seg_tree[num << 1 | 1];
}

/**
 * 区间查询
 * @param query_l 查询区间左端点
 * @param query_r 查询区间右端点
 * @param l 当前搜索区间左端点
 * @param r 当前搜索区间右端点
 * @param num 线段树序号
 * @return 区间查询结果（求区间和）
 */
long long query(int query_l, int query_r, int l, int r, int num) {

    if (query_l <= l && r <= query_r) {
        return seg_tree[num];
    }

    push_down(l, r, num);

    long long result = 0;
    int mid = (l + r) / 2;
    if (query_l <= mid) {
        result += query(query_l, query_r, l, mid, num << 1);
    }
    if (mid + 1 <= query_r) {
        result += query(query_l, query_r, mid + 1, r, num << 1 | 1);
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &seq[i]);
    }
    build(1, n, 1);
    int op;
    long long x, y, k;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%lld %lld %lld", &x, &y, &k);
            update(x, y, k, 1, n, 1);
        } else {
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}
```

### ST表

```c++
// luogu3865 ST表模板
// Created by Jiang Yinzuo on 2020/4/11.
//

#include <cstdio>
#include <algorithm>

const int MAX_N = 100009;

int sum1[MAX_N];

/**
 * sparse_table[i][j] 表示区间arr中第i个数开始的2^j个数中的最大值
 */
int sparse_table[MAX_N][21];

int LOG_2[MAX_N];

/**
 * log2对数打表
 * @param n 最大值
 */
void calculate_log(int n) {
    LOG_2[1] = 0;
    for (int i = 2; i <= n; ++i) {
        LOG_2[i] = LOG_2[i >> 1] + 1;
    }
}

/**
 * 查询区间f(left, right)最值
 * @param left 左端点
 * @param right 右端点
 * @return 最值
 */
int query(int left, int right) {
    int mid = LOG_2[right - left + 1];

    // 将f(left, right)分成前2^mid个数和后2^mid个数，分别查询
    // f(left, right) = max(f(left, left + 2^mid - 1), f(right - (2^mid-1), right))
    return std::max(sparse_table[left][mid], sparse_table[right - (1 << mid) + 1][mid]);
}

/**
 * 初始化ST表
 * @param sum1 输入序列, 下标从1开始
 * @param size 序列长度
 */
void init(int *sum1, int size) {

    // 区间arr中第i个数开始的1个数中的最大值就是第i个数
    for (int i = 1; i <= size; ++i) sparse_table[i][0] = sum1[i];

    // 依次求2^1, 2^2, 2^3, ... size个数中的最大值
    for (int j = 1; j <= LOG_2[size]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= size; ++i) {

            // f(i, i + 2^j - 1) = max(f(i, i + 2^(j-1) - 1), f(i + 2^(j-1), i + 2^j - 1)
            sparse_table[i][j] = std::max(sparse_table[i][j-1], sparse_table[i + (1 << (j-1))][j-1]);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    calculate_log(n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &sum1[i]);
    }
    init(sum1, n);

    int left, right;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &left, &right);
        printf("%d\n", query(left, right));
    }
    return 0;
}

```

## 图论

### 最短路

#### Dijkstra

```c++
//
// Created by Jiang Yinzuo on 2020/3/8.
// hdu2544

#include <cstdio>
#include <name_queue>
#include <cstring>

const long long MAX_LONG_LONG = 9223372036854775807;

struct Edge {
    static int edge_idx;
    static int heads[100005];
    int to;
    long long distance;
    int next;

    bool operator<(Edge &edges) {
        return distance < edges.distance;
    }
} edges[200005];

int Edge::edge_idx = 0;
int Edge::heads[100005] = {0};

struct Vertex {
    int v;
    long long distance;

    Vertex(int v, long long distance) : v(v), distance(distance) {}

    bool operator<(const Vertex &vertex) const {
        return distance > vertex.distance;
    }
};

void add_edge(int from, int to, long long distance) {
    edges[++Edge::edge_idx] = {to, distance, Edge::heads[from]};
    Edge::heads[from] = Edge::edge_idx;
}


long long distance[100005];
bool grid[100005];

void dijkstra(int vertex_count) {

    memset(grid, false, sizeof(grid));
    distance[1] = 0;
    for (int i = 2; i <= vertex_count; ++i) {
        distance[i] = MAX_LONG_LONG;
    }

    std::priority_queue<Vertex> vertex_queue;

    // 1是起点
    vertex_queue.push({1, 0});

    while (!vertex_queue.empty()) {
        Vertex cur_v = vertex_queue.top();
        vertex_queue.pop();
        if (grid[cur_v.v]) continue;

        // 搜索到终点结束
        if (cur_v.v == vertex_count) break;

        grid[cur_v.v] = true;

        for (int i = Edge::heads[cur_v.v]; i; i = edges[i].next) {
            if (!grid[edges[i].to] && distance[edges[i].to] > distance[cur_v.v] + edges[i].distance) {
                distance[edges[i].to] = distance[cur_v.v] + edges[i].distance;
                vertex_queue.push({edges[i].to, distance[edges[i].to]});
            }
        }
    }
    printf("%lld\n", distance[vertex_count]);
}

int main() {
    int vertex_count, road_count;

    int from, to, tmp_dis;
    while (~scanf("%d %d", &vertex_count, &road_count) && vertex_count && road_count) {
        Edge::edge_idx = 0;
        memset(Edge::heads, 0, sizeof(Edge::heads));

        for (int i = 0; i < road_count; ++i) {
            scanf("%d %d %d", &from, &to, &tmp_dis);
            add_edge(from, to, tmp_dis);
            add_edge(to, from, tmp_dis);
        }
        dijkstra(vertex_count);
    }
    return 0;
}
```

### 树

#### LCA

倍增求LCA

```C++
/**
 * luogu3379
 */

#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
    int v;
    int next;
} edges[500002 << 1];
int heads[500002];
int total = 0;

int depth[500002] = {0};
int ancestors[500002][22] = {0};

int LOG_2[500002];

void add_edge(int u, int v) {
    edges[++total] = {v, heads[u]};
    heads[u] = total;
}

void dfs(int cur_v, int parent) {
    ancestors[cur_v][0] = parent;
    depth[cur_v] = depth[parent] + 1;

    for (int i = 1; i <= LOG_2[depth[cur_v]]; ++i) {
        ancestors[cur_v][i] = ancestors[ancestors[cur_v][i-1]][i-1];
    }

    for (int i = heads[cur_v]; i; i = edges[i].next) {
        if (edges[i].v != parent) {
            dfs(edges[i].v, cur_v);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        a = ancestors[a][LOG_2[depth[a]-depth[b]]];
    }
    if (a == b) {
        return a;
    }
    for (int i = LOG_2[depth[a]]; i >= 0; --i) {
        if (ancestors[a][i] != ancestors[b][i]) {
            a = ancestors[a][i];
            b = ancestors[b][i];
        }
    }
    return ancestors[a][0];
}

void get_log_2() {
    LOG_2[1] = 0;
    for (int i = 2; i <= 500001; ++i) {
        LOG_2[i] = LOG_2[i>>1] + 1;
    }
}

int main() {
    get_log_2();

    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    int x, y;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }

    dfs(s, 0);

    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }

    return 0;
}
```

### 树的直径

#### 两次dfs

先从任意一点P出发，找离它最远的点Q，再从点Q出发，找离它最远的点W，W到Q的距离就是是的直径

#### 树形DP



## 数学

### 快速幂

快速幂

```c++
long long fast_pow(long long base, long long idx) {
    if (base == 0) return 0;
    long long result = 1;
    while (idx > 0) {
        if (idx & 1) result *= base;
        base *= base;
        idx >>= 1;
    }
    return result;
}
```

快速幂取模

```c++
long long fast_pow(long long base, long long idx, long long mod) {
    if (base == 0 || mod == 1) return 0;
    long long result = 1;
    base %= mod;
    while (idx > 0) {
        if (idx & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        idx >>= 1;
    }
    return result;
}
```

费马小定理：若p为素数，gcd(a, p) = 1，则$a^{p-1} \equiv 1 \pmod p$

因此当a和p互质且p为素数时，可以计算$a^{x}\bmod p=a^{x\bmod(p-1)} \bmod p$ 来提高效率。
### 乘法逆元

若线性同余方程$ax\equiv1\pmod b$，则称x为$a\bmod b$ 的逆元，记作$a^{-1}$

快速幂+费马小定理求逆元：b为素数时，逆元$x=a^{b-2}$

$\frac a b$为分数，求$a*b^{-1} \bmod p$
$$
a*b^{-1} \equiv a * b^{p-2}\pmod p
$$

### 组合数学

组合数打表

$\mathrm C_n^m=C_{n-1}^m+C_{n-1}^{m-1}$

```c++
long long C[1009][1009];

void init() {
    for (int n = 0; n <= 1003; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int m = 1; m < n; ++m) {
            C[n][m] = C[n - 1][m] + C[n - 1][m - 1];
        }
    }
}
```

## 字符串

### KMP

```c++
// 替换掉所有word中的p
// Created by Jiang Yinzuo on 2020/3/22.
//

#include <cstdio>
#include <cstring>

const int MAX= 5000007;
int next[MAX];

void get_next(char *word, int len) {
    next[0] = -1;
    int i = 0, j = -1;
    while (i < len) {
        if (j != -1 && word[i] != word[j]) {
            j = next[j];
        } else {
            next[++i] = ++j;
        }
    }
}

int pos[MAX];
char p[MAX], word[MAX];
char ans[MAX];

int main() {

    int ans_idx;
    while (~scanf("%s%s", word, p)) {
        int len = strlen(word);
        get_next(word, len);

        int p_len = strlen(p);
        int i = 0, j = 0;
        ans_idx = 0;
        while (i < p_len) {
            ans[ans_idx] = p[i];
            while (j != -1 && p[i] != word[j]) {
                j = next[j];
            }
            ++i;
            ++j;
            pos[ans_idx++] = j;
            if (j == len) {
                ans_idx -= len;
                j = pos[ans_idx - 1];
            }
        }
        ans[ans_idx] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
```

利用KMP算法中的get_next()可以求字符串最大回文前缀（cf1326D）

## 动态规划

### 动态规划基础

#### 最长递增子序列

```c++
#include <cstdio>
#include <algorithm>

const int MAX_N = 200000;
int sum1[MAX_N] = {0};

int main() {
    int n;
    scanf("%d", &n);
    
    int element, idx = 0;
    int *index;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        if ((index = std::lower_bound(sum1, sum1 + idx, element)) == sum1 + idx) idx++;
        *index = element;
    }
    printf("%d\n", idx);
    for (int i = 0; i < idx; ++i) {
        printf("%d ", sum1[i]);
    }
    printf("\n");
    return 0;
}
```

