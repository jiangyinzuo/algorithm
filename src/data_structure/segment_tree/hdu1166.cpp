//
// Created by Jiang Yinzuo on 2020/3/21.
//

#include <cstdio>
#include <cstring>

namespace seg_tree {
int arr[50005];
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
        tree[cur_idx] = arr[left];
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
            scanf("%d", &seg_tree::arr[i]);
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