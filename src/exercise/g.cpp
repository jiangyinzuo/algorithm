//
// Created by Jiang Yinzuo on 2020/5/2.
//

#include <cstdio>

namespace seg_tree {

const int MAX_N = 100002;
int arr[MAX_N];
int tree[MAX_N << 2][4] = {0};
long long result[4];

/**
 * 区间查询
 * @param left 线段树节点左边界
 * @param right 线段树节点右边界
 * @param cur_idx 当前线段树节点标记
 * @param arr_left 区间查询左边界
 * @param arr_right 区间查询右边界
 * @return
 */
void query(int left, int right, int cur_idx, const int arr_left, const int arr_right) {
    if (arr_left <= left && right <= arr_right) {
        for (int i = 0; i < 4; ++i) {
            result[i] += tree[cur_idx][i];
        }
        return;
    }

    int mid = (left + right) / 2;

    if (arr_left <= mid) {
        query(left, mid, cur_idx << 1, arr_left, arr_right);
    }
    if (mid + 1 <= arr_right) {
        query(mid + 1, right, (cur_idx << 1) | 1, arr_left, arr_right);
    }
}

int values[11][4] = {
        0, 0, 0, 0,
        0, 0, 0, 0,
        1, 0, 0, 0,
        0, 1, 0, 0,
        2, 0, 0, 0,
        0, 0, 1, 0,
        1, 1, 0, 0,
        0, 0, 0, 1,
        3, 0, 0, 0,
        0, 2, 0, 0,
        1, 0, 1, 0
};

void update_value(int idx, int value) {
    for (int i = 0; i < 4; ++i) {
        tree[idx][i] = values[value][i];
    }
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
            update_value(cur_idx, value);
            return;
        }

        int mid = (left + right) / 2;
        if (arr_idx <= mid) {
            update(left, mid, cur_idx << 1, arr_idx, value);
        } else {
            update(mid + 1, right, (cur_idx << 1) | 1, arr_idx, value);
        }

        for (int i = 0; i < 4; ++i)
            tree[cur_idx][i] = tree[cur_idx << 1][i] + tree[(cur_idx << 1) | 1][i];
    }

/**
 * 建立线段树
 * @param left 线段树节点左边界
 * @param right 线段树节点右边界
 * @param cur_idx 当前线段树节点标号
 */
    void build(int left, int right, int cur_idx) {
        if (left == right) {
            update_value(cur_idx, arr[left]);
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, cur_idx << 1);
        build(mid + 1, right, (cur_idx << 1) | 1);
        for (int i = 0; i < 4; ++i)
            tree[cur_idx][i] = tree[cur_idx << 1][i] + tree[(cur_idx << 1) | 1][i];
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &seg_tree::arr[i]);
    }
    seg_tree::build(1, n, 1);

    const int MOD = 998244353;
    int op, a, b;
    while (m--) {
        scanf("%d %d %d", &op, &a, &b);

        if (op == 2) {
            for (int i = 0; i < 4; ++i) seg_tree::result[i] = 0;
            seg_tree::query(1, n, 1, a, b);
            long long res = 1;
            for (int i = 0; i < 4; ++i) {
                res = res * ((seg_tree::result[i] + 1) % MOD) % MOD;
            }
            printf("%lld\n", res);
        } else {
            seg_tree::update(1, n, 1, a, b);
        }
    }
    return 0;
}