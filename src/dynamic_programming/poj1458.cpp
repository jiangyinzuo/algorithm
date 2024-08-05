//
// Created by Jiang Yinzuo on 2020/7/28.
//

#include <cstring>
#include <cstdio>
#include <algorithm>

int lcs(const char a[], const char b[]) {
    static int dp[2][1002];
    memset(dp, 0, sizeof(dp));
    int i, j;
    for (i = 1; a[i]; ++i) {
        for (j = 1; b[j]; ++j) {
            dp[i & 1][j] = a[i] == b[j] ? dp[i & 1 ^ 1][j - 1] + 1 : std::max(dp[i & 1 ^ 1][j], dp[i & 1][j - 1]);
        }
    }
    return dp[i & 1 ^ 1][j - 1];
}

int main() {
    char a[1002], b[1002];
    while (scanf("%s %s", a + 1, b + 1) != EOF) {
        printf("%d\n", lcs(a, b));
    }
    return 0;
}