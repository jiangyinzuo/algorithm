//
// Created by Jiang Yinzuo on 2020/7/15.
//

#include <cstdio>
#include <cstring>

bool graph[501][501]; /* 邻接矩阵存有向图 u -> v */
bool matched[501];    /* 一次dfs中，v是否已经同一个u匹配 */
int link_u[501];      /* 点v同哪个u匹配 */

bool dfs(int u, int v_num) {
    for (int v = 1; v <= v_num; ++v) {
        if (graph[u][v] && !matched[v]) {
            matched[v] = true;
            if (link_u[v] == -1 || dfs(link_u[v], v_num)) {
                link_u[v] = u;
                return true;
            }
        }
    }
    return false;
}

/**
 * 匈牙利算法求二分图最大匹配。（左右两边点的编号均从1开始）
 * @param u_num 左边一组点的个数
 * @param v_num 右边一组点的个数
 * @return 最大匹配数
 */
int hungary(int u_num, int v_num) {
    int result = 0;
    memset(link_u, -1, sizeof(link_u));

    for (int i = 1; i <= u_num; ++i) {
        memset(matched, false, sizeof(matched));
        if (dfs(i, v_num)) ++result;
    }
    return result;
}

int main() {
    int k, m, n;
    while (scanf("%d", &k) && k) {
        scanf("%d %d", &m, &n);
        memset(graph, false, sizeof(graph));

        int u, v;
        while (k--) {
            scanf("%d %d", &u, &v);
            graph[u][v] = true;
        }
        printf("%d\n", hungary(m, n));
    }
    return 0;
}