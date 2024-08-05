//
// Created by Jiang Yinzuo on 2020/7/19.
//

#include<iostream>
#include<cstdio>
#include<algorithm>

const int N = 710;
const int INF = 1e8;
char s[N];
int dp[N][N], nxt[N][N];
int n;

void get_next(int x) {
    int i, j;
    j = x - 1;
    nxt[x][x] = x - 1;
    for (i = x + 1; i <= n; i++) {
        while (j >= x && s[i] != s[j + 1])
            j = nxt[x][j];
        if (s[i] == s[j + 1])
            j++;
        nxt[x][i] = j;
    }
}

int main() {
    int i, j, len, l, r, k;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (i = 1; i <= n; i++)
        get_next(i);
    for (i = 1; i <= n; i++)
        dp[i][i] = 1;
    for (i = 2; i <= n; i++)
        for (l = 1; l <= n - i + 1; l++) {
            r = l + i - 1;
            dp[l][r] = INF;
            for (k = l; k <= r; k++) {
                len = r - k + 1;
                if (len % (len - (nxt[k][r] - k + 1)) == 0)
                    dp[l][r] = std::min(dp[l][r], dp[l][k - 1] + dp[k][k + len - (nxt[k][r] - k + 1) - 1]);
            }
        }
    printf("%d\n", dp[1][n]);
    return 0;
}
