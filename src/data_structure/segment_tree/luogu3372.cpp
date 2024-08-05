#include <cstdio>

long long seq[100008];

long long seg_tree[400008];
long long add_tag[400008] = {0};

void build(int l, int r, int num) {
    if (l == r) {
        seg_tree[num] = seq[l];
        return;
    }

    build(l, (l + r) / 2, num << 1);
    build((l + r) / 2 + 1, r, num << 1 | 1);

    seg_tree[num] = seg_tree[num << 1] + seg_tree[num << 1 | 1];
}

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