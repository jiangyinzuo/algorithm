//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include<iostream>
#include<cstdio>
#include<cstring>

#define N 105
#define INF 999999999

int n, m;

struct Edge {
    int v, val, next;
} edge[N * N];
int head[N], cnte;

void addEdge(int a, int b, int val) {
    edge[cnte].v = b;
    edge[cnte].val = val;
    edge[cnte].next = head[a];
    head[a] = cnte++;
}

int  dist[N], vis[N];

void dijkstra() {
    for (int i = head[0]; i != 0; i = edge[i].next) {
        if (vis[edge[i].v] == 0)
            dist[edge[i].v] = edge[i].val;
    }
    dist[0] = 0;
    vis[0] = 1;
    for (int i = 1; i <= n; i++) {
        int u = 0, minn = INF;
        for (int j = 1; j <= n; j++) {
            if (dist[j] < minn && vis[j] == 0) {
                minn = dist[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (int j = head[u]; j != 0; j = edge[j].next) {
            int v = edge[j].v;
            int val = edge[j].val;
            if (dist[v] > dist[u] + val && vis[v] == 0)
                dist[v] = dist[u] + val;
        }
    }
}

int main() {
    int item[N], lev[N];
    while (scanf("%d%d", &m, &n) != EOF) {
        memset(head, 0, sizeof(head));
        cnte = 1;

        int minlv = INF, maxlv = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d%d%d", &item[i], &lev[i], &x);
            addEdge(0, i, item[i]);
            minlv = std::min(minlv, lev[i]);
            maxlv = std::max(maxlv, lev[i]);
            while (x--) {
                int ver, value;
                scanf("%d%d", &ver, &value);
                addEdge(ver, i, value);
            }
        }

        int res = item[1];
        for (int i = minlv; i <= maxlv; i++) {
            memset(vis, 0, sizeof(vis));
            for (int i = 1; i <= n; i++)
                dist[i] = INF;
            for (int j = 1; j <= n; j++)
                if (lev[j] > i || i - lev[j] > m)
                    vis[j] = 1;
            dijkstra();
            res = std::min(res, dist[1]);
        }
        printf("%d\n", res);
    }
    return 0;
}