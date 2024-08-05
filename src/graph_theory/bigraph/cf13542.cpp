//
// Created by Jiang Yinzuo on 2020/10/24.
//

#include<bits/stdc++.h>

#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;
const int maxn = 5000 + 9;
vector<int> G[maxn], T[maxn][2];
int cc = 0, f[maxn][maxn] = {}, pre[maxn][maxn] = {}, color[maxn], ans[maxn] = {};
int n1, n2, n3, n, m;

void dfs(int v) {
    T[cc][color[v] - 1].push_back(v);
    for (int j:G[v])
        if (!color[j])
            color[j] = 3 - color[v], dfs(j);
        else if (color[j] != 3 - color[v])
            puts("NO"), exit(0);
}

int main() {
    cin >> n >> m >> n1 >> n2 >> n3;
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 1, n + 1) if (!color[i]) {
            cc++;
            color[i] = 1;
            dfs(i);
        }
    f[0][0] = 1;
    rep(i, 0, cc) rep(side, 0, 2)for (int j = 0, en = T[i + 1][side].size(); j <= n - en; j++) {
                if (f[i][j])
                    f[i + 1][j + en] = 1, pre[i + 1][j + en] = side;
            }
    if (!f[cc][n2])
        return puts("NO"), 0;
    else
        puts("YES");
    for (int i = cc, sta = n2; i; i--) {
        int side = pre[i][sta];
        for (int v:T[i][side]) ans[v] = 1;
        sta -= T[i][side].size();
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) printf("2");
        else if (n1) printf("1"), n1--;
        else printf("3");
    }
}
