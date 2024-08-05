// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <cstdio>
#include <cstring>

template<const int T>
struct TreeArray {
    int arr[T + 1];

    int lowbit(int x) {
        return x & (-x);
    }

    // add value to arr[i]
    void update(int i, int value) {
        while (i <= T) {
            arr[i] += value;
            i += lowbit(i);
        }
    }

    // query sum of [1, i]
    int query(int i) {
        int total = 0;
        while (i > 0) {
            total += arr[i];
            i -= lowbit(i);
        }
        return total;
    }
};

TreeArray<50003> tree_arr;

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        printf("Case %d:\n", kase);
        int n;
        scanf("%d", &n);
        memset(tree_arr.arr, 0, sizeof(tree_arr.arr));
        for (int i = 1; i <= n; ++i) {
            int d;

            scanf("%d", &d);
            tree_arr.update(i, d);
        }
        char s[20];
        for (;;) {
            scanf("%s", s);
            switch (s[0]) {
            case 'E': goto end;
            case 'Q':int from, to;
                scanf("%d %d", &from, &to);
                printf("%d\n", tree_arr.query(to) - tree_arr.query(from - 1));
                break;
            case 'A':int i, d;
                scanf("%d %d", &i, &d);
                tree_arr.update(i, d);
                break;
            case 'S':scanf("%d %d", &i, &d);
                tree_arr.update(i, -d);
                break;
            }
        }
        end:;
    }
    return 0;
}