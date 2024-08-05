//
// Created by Jiang Yinzuo on 2020/8/3.
//

#include <cstdio>
#include <algorithm>

struct Dish {
    long long pre_profit;
    int num;
    int min_num;
    int min_num_idx;
} dishes[100009];

int dish_kind[100009];

bool cmp(int kind1, int kind2) {
    return dishes[kind1].pre_profit < dishes[kind2].pre_profit ||
           dishes[kind1].pre_profit == dishes[kind2].pre_profit && kind1 < kind2;
}

bool is_pos;
unsigned long long solve(int n) {
    unsigned long long pos_answer = 0, neg_answer = 0;
    int cur_kind = dish_kind[n];
    int dish_kind_idx = n;
    int consumed_num = 0;
    while (cur_kind > 0 && consumed_num < dishes[1].num && dish_kind_idx > 0) {
        if (dishes[cur_kind].pre_profit > 0) {
            pos_answer += dishes[cur_kind].pre_profit * (dishes[cur_kind].min_num - consumed_num);
        } else {
            neg_answer += (-dishes[cur_kind].pre_profit) * (dishes[cur_kind].min_num - consumed_num);
        }
        consumed_num = dishes[cur_kind].min_num;
        cur_kind = dishes[cur_kind].min_num_idx;
        // 比cur_kind小，利润最大且还有盘子
        while (--dish_kind_idx) {
            if (dish_kind[dish_kind_idx] < cur_kind && dishes[dish_kind[dish_kind_idx]].num - consumed_num > 0) {
                cur_kind = dish_kind[dish_kind_idx];
                break;
            }
        }
    }
    if ( pos_answer > neg_answer) {
        is_pos = true;
        return pos_answer - neg_answer;
    } else {
        is_pos = false;
        return neg_answer - pos_answer;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    dishes[0].pre_profit = 0;
    dishes[0].min_num = 999999999;
    for (int kase = 1; kase <= t; ++kase) {
        int n;
        scanf("%d", &n);
        int a;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            dishes[i].pre_profit = dishes[i - 1].pre_profit + a;
            dish_kind[i] = i;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &dishes[i].num);

            if (dishes[i - 1].min_num < dishes[i].num) {
                dishes[i].min_num = dishes[i - 1].min_num;
                dishes[i].min_num_idx = dishes[i - 1].min_num_idx;
            } else {
                dishes[i].min_num = dishes[i].num;
                dishes[i].min_num_idx = i;
            }
        }
        std::sort(dish_kind + 1, dish_kind + n + 1, cmp);
        unsigned long long res = solve(n);
        if (is_pos || res == 0)
            printf("Case #%d: %d %llu\n", kase, dishes[1].num, res);
        else
            printf("Case #%d: %d -%llu\n", kase, dishes[1].num, res);
    }
    return 0;
}