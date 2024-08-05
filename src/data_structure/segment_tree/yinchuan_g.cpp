//
// Created by jiang on 2020/8/12.
//

#include <cstdio>
#include <cstring>
#include <array>

long long seq[100008];
std::array<int, 4> seg_tree[400008]; // 本题build初始化
std::array<int, 4> multi_tags[400008];

/**
 * 下推懒惰标记
 * @param l 左区间端点
 * @param r 右区间端点
 * @param num 序号
 */
void push_down(int l, int r, int num) {
    for (int i = 0; i < 4; ++i)
        if (multi_tags[num][i]) {
            seg_tree[num << 1][i] += multi_tags[num][i];
            seg_tree[num << 1 | 1][i] += multi_tags[num][i];
            multi_tags[num << 1][i] += multi_tags[num][i];
            multi_tags[num << 1 | 1][i] += multi_tags[num][i];
            multi_tags[num][i] = 0;
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
#define ADD(n, v) (multi_tags[num][n] += v, seg_tree[num][n] += v)
    if (update_l <= l && r <= update_r) {
        if (value == 2) ADD(0, 1);
        else if (value == 3) ADD(1, 1);
        else if (value == 4) ADD(0, 2);
        else if (value == 5) ADD(2, 1);
        else if (value == 6) {
            ADD(0, 1);
            ADD(1, 1);
        } else if (value == 7) ADD(3, 1);
        else if (value == 8) ADD(0, 3);
        else if (value == 9) ADD(1, 2);
        else if (value == 10) {
            ADD(0, 1);
            ADD(2, 1);
        }
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
    for (int i = 0; i < 4; ++i)
        seg_tree[num][i] = std::max(seg_tree[num << 1][i], seg_tree[num << 1 | 1][i]);
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
        int max_value = 0;
        for (auto &i : seg_tree[num]) {
            max_value = std::max(max_value, i);
        }
        return max_value;
    }

    push_down(l, r, num);

    long long result = 0;
    int mid = (l + r) / 2;
    if (query_l <= mid) {
        result = std::max(result, query(query_l, query_r, l, mid, num << 1));
    }
    if (mid + 1 <= query_r) {
        result = std::max(result, query(query_l, query_r, mid + 1, r, num << 1 | 1));
    }
    return result;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    memset(seq, 1, sizeof(seq));
    char op[10];
    int n1, n2, n3;
    for (int i = 0; i < q; ++i) {
        scanf("%s %d %d", op, &n1, &n2);
        if (op[1] == 'U') {
            scanf("%d", &n3);
            update(n1, n2, n3, 1, n, 1);
        } else {
            printf("ANSWER %lld\n", query(n1, n2, 1, n, 1));
        }
    }
    return 0;
}