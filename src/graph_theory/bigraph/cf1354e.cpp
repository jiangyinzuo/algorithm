//
// Created by Jiang Yinzuo on 2020/10/24.
//

#include <cstdio>
#include <vector>

constexpr int MAX_N = 5001;
std::vector<int> graph[MAX_N];
int tag[MAX_N] = {0};

int g_cnt = 0;
std::vector<int> tag_group[MAX_N][3];

bool is_bigraph(int cur_v, int last_tag) {
    tag[cur_v] = 3 - last_tag;
    tag_group[g_cnt][tag[cur_v]].push_back(cur_v);
    for (auto i : graph[cur_v]) {
        if (tag[cur_v] == tag[i] || tag[i] == 0 && !is_bigraph(i, tag[cur_v])) {
            return false;
        }
    }
    return true;
}

void solve(int n, int n1, int n2, int n3) {
    for (int v = 1; v <= n; ++v) {
        if (tag[v] == 0) {
            ++g_cnt;
            if (!is_bigraph(v, 1)) {
                puts("NO");
                return;
            }
        }
    }
    static bool dp[MAX_N][MAX_N];
    for (int i = 0; i <= g_cnt; ++i) dp[i][0] = true;
    int right = 0;
    for (int idx = 1; idx <= g_cnt; ++idx) {
        int _max_v = std::max(tag_group[idx][1].size(), tag_group[idx][2].size());
        right = std::min(n2, right + _max_v);
        for (int j = _max_v; j <= right; ++j) {
            for (int k = 1; k <= 2; ++k) {
                if (dp[idx - 1][j - tag_group[idx][k].size()]) {
                    dp[idx][j] = true;
                    break;
                }
            }
        }
    }
    if (dp[g_cnt][n2]) {
        int remain_n2 = n2;
        for (int i = g_cnt; i >= 1; --i) {
            for (int k = 1; k <= 2; ++k) {
                int r = remain_n2 - (int)tag_group[i][k].size();
                if (r >= 0 && dp[i - 1][r]) {
                    for (int v : tag_group[i][k]) tag[v] = -2;
                    remain_n2 -= tag_group[i][k].size();
                    break;
                }
            }

        }
        puts("YES");
        for (int i = 1; i <= n; ++i) {
            printf("%d", tag[i] == -2 ? 2 : (n3-- > 0 ? 3 : 1));
        }
        puts("");
    } else {
        puts("NO");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (n2 == 0 && m > 0) puts("NO");
    else solve(n, n1, n2, n3);
    return 0;
}
