//
// Created by jiang on 2020/12/2.
//

#include <cstdio>
#include <vector>

constexpr int BLACK = 2, GREY = 0, WHITE = 1;

static int color[200001];
static std::vector<int> tree[200001];
static int black_group_cnt[200001], white_group_cnt[200001];
static bool conn_black[200001], conn_white[200001];

void dfs(int cur_v, int father) {
    black_group_cnt[cur_v] = white_group_cnt[cur_v] = 0;
    conn_white[cur_v] = conn_black[cur_v] = false;
    if (tree[cur_v].size() == 1) {
        if (color[cur_v] == BLACK) {
            black_group_cnt[cur_v] = 1;
            conn_black[cur_v] = true;
        } else if (color[cur_v] == WHITE) {
            white_group_cnt[cur_v] = 1;
            conn_white[cur_v] = true;
        }
        return;
    }

    int child_conn_black_cnt = 0, child_conn_white_cnt = 0;
    for (auto &i : tree[cur_v]) {
        if (i != father) {
            dfs(i, cur_v);
            child_conn_black_cnt += conn_black[i];
            child_conn_white_cnt += conn_white[i];
            white_group_cnt[cur_v] += white_group_cnt[i];
            black_group_cnt[cur_v] += black_group_cnt[i];
        }
    }

    switch (color[cur_v]) {
        case BLACK:
            black_group_cnt[cur_v] -= child_conn_black_cnt - 1;
            conn_black[cur_v] = true;
            break;
        case WHITE:
            white_group_cnt[cur_v] -= child_conn_white_cnt - 1;
            conn_white[cur_v] = true;
            break;
        default:
            black_group_cnt[cur_v] -= std::max(0, child_conn_black_cnt - 1);
            white_group_cnt[cur_v] -= std::max(0, child_conn_white_cnt - 1);
            conn_black[cur_v] = child_conn_black_cnt > 0;
            conn_white[cur_v] = child_conn_white_cnt > 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int _case = 1; _case <= t; ++_case) {

        int n;
        scanf("%d", &n);
        bool has_color[3]{false, false, false};
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
            scanf("%d", color + i);
            has_color[color[i]] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        if (!has_color[WHITE] || !has_color[BLACK])
            puts("1");
        else {
            tree[n].push_back(0);
            dfs(n, 0);
            int res =std::min(white_group_cnt[n], black_group_cnt[n]) + 1;
            printf("%d\n", res >= 4 ? res - 1:res);
        }
    }
    return 0;
}
/*
1
12
0 1 2 1 2 1 1 2 1 2 0 1
12
11
1 11
1 2
2 3
3 4
3 6
2 5
1 7
7 8
8 9
7 10

 */