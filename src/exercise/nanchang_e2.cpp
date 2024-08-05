//
// Created by Jiang Yinzuo on 2020/10/1.
//

#include<iostream>
#include<algorithm>
#include<cstdio>

const int NUM = 50100;
const int maxn = 500100;
using namespace std;
int S[NUM];
struct Edge {
    int u, v;
    long long w;
    int sign, choose;
} edge[maxn];

bool cmp(Edge &a, Edge &b) { return a.w > b.w; }

int find(int u) { return S[u] == u ? u : S[u] = find(S[u]); }

int n, m, k;

long long kruskal() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) S[i] = i;

    for (int i = 1; i <= m; i++) {
        if (edge[i].sign == 0) {
            int b = find(edge[i].u);
            int c = find(edge[i].v);
            S[c] = b;
            ans += edge[i].w;
            edge[i].choose = 1;
        }
    }
    int x = 0;
    sort(edge + 1, edge + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        if (x >= k) break;
        if (edge[i].choose == 0) {
            int b = find(edge[i].u);
            int c = find(edge[i].v);
            if (b == c) continue;
            S[c] = b;
            ans += edge[i].w;
            edge[i].choose = 1;
            x++;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (x >= k) break;
        if (edge[i].choose == 0) {
            ans += edge[i].w;
            x++;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        int b = find(i);
        int c = find(i + 1);
        if (b == c) continue;
        else return -1;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        //sum = 0;
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%lld%d", &edge[i].u, &edge[i].v, &edge[i].w, &edge[i].sign);
            edge[i].choose = 0;
        }
        printf("%lld\n", kruskal());
    }
    return 0;
}