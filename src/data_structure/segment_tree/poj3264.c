#include <stdio.h>

int arr[50003];
typedef struct {
    int maxv;
    int minv;
} Segment_tree;

Segment_tree segment_tree[2000009];

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void push_up(int node)
{
    segment_tree[node].maxv = max(segment_tree[node<<1].maxv, segment_tree[node<<1|1].maxv);
    segment_tree[node].minv = min(segment_tree[node<<1].minv, segment_tree[node<<1|1].minv);
}

void build_tree(int l, int r, int node)
{
    if (l == r) {
        segment_tree[node].maxv = segment_tree[node].minv = arr[l];
        return;
    }

    int m = (l + r) / 2;
    build_tree(l, m, node<<1);
    build_tree(m+1, r, node<<1|1);
    push_up(node);
}

int query_maxv(int ql, int qr, int l , int r, int node)
{
    if (ql <= l && r <= qr) {
        return segment_tree[node].maxv;
    }

    int res = 0;
    int m = (l + r) / 2;
    if (m >= ql) {
        res = max(query_maxv(ql, qr, l, m, node<<1), res);
    }
    if (m+1 <= qr) {
        res = max(query_maxv(ql, qr, m+1, r, node<<1|1), res);
    }
    return res;
}

int query_minv(int ql, int qr, int l , int r, int node)
{
    if (ql <= l && r <= qr) {
        return segment_tree[node].minv;
    }

    int res = 1000009;
    int m = (l + r) / 2;
    if (m >= ql) {
        res = min(query_minv(ql, qr, l, m, node<<1), res);
    }
    if (m+1 <= qr) {
        res = min(query_minv(ql, qr, m+1, r, node<<1|1), res);
    }
    return res;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    build_tree(1, n, 1);

    int ql, qr;
    for (int i = 1; i <= q; ++i) {
        scanf("%d %d", &ql, &qr);
        printf("%d\n",
            query_maxv(ql, qr, 1, n, 1)-query_minv(ql, qr, 1, n ,1)
        );
    }
    
    return 0;
}